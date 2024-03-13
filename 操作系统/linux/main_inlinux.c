#include "p_and_c.h"

char *randc()
{
    static char buf[BUF_LEN];//static重复使用 
    int n = rand() % 3;
    buf[0] = wqy[n];
    return buf;
}

// pv封装

void P(int sem_id, int sem_num) //P
{
   struct sembuf xx;
   xx.sem_num = sem_num;
   xx.sem_op = -1;
   xx.sem_flg = 0;
   semop(sem_id, &xx, 1);
}

void V(int sem_id, int sem_num) //V
{
   struct sembuf xx;
   xx.sem_num = sem_num;
   xx.sem_op = 1;
   xx.sem_flg = 0;
   semop(sem_id, &xx, 1);
}

//进程函数
void init() //初始化 
{
	//信号量 
	int semid = semget(SEM_KEY, 3, IPC_CREAT|MODE);
	semctl(semid, MUTEX, SETVAL, 1);
	semctl(semid, EMPTY, SETVAL, BUF_CNT);
	semctl(semid, FULL, SETVAL, 0);
	
	//共享内存 
	int shmid = shmget(SHM_KEY, sizeof(struct MyBuffer), IPC_CREAT|MODE);
	//清空内存
	struct MyBuffer* shmptr = shmat(shmid, 0, 0);
    //初始化
	memset(shmptr, 0, sizeof(struct MyBuffer));
    for (int i = 0; i < BUF_CNT; i++)
        shmptr->str[i][0] = '-';
	shmdt(shmptr);
}

void pro() //生产者 
{
	srand((unsigned)getpid());//以pid作为seed
	//获取已有信号量和共享内存 
	//信号量 
	int semid = semget(SEM_KEY, 3, IPC_CREAT|MODE);
	//共享内存 
	int shmid = shmget(SHM_KEY, sizeof(struct MyBuffer), IPC_CREAT|MODE);
	struct MyBuffer* shmptr = shmat(shmid, 0, 0);
	//重复向储存区写入
	struct timespec begin;//精确获取时间 
	struct timespec end;
	for(int i = 0;i < PRO_REP; i++)
	{
		clock_gettime(1, &begin);//记录初始时间 
		P(semid, EMPTY);//P
		P(semid, MUTEX);
		usleep(rand() % 3000000);//随机等待
		strncpy(shmptr->str[shmptr->tail], randc(), BUF_LEN);//写入 
		printf("[pid %d] push %-10s ", getpid(), shmptr->str[shmptr->tail]);
		shmptr->tail = (shmptr->tail + 1) % BUF_CNT;
		for (int cnt = 0; cnt < BUF_CNT ; cnt++) {
            printf("[%-5s] ", shmptr->str[cnt]);
            if (cnt != BUF_CNT-1) printf("+ ");
        }

		V(semid, FULL);//V
		V(semid, MUTEX);
		clock_gettime(1, &end);//获取最终时间，输出耗时
		double duration=(end.tv_sec-begin.tv_sec)*1000+(end.tv_nsec-begin.tv_nsec)/1000000;
		printf(" running time:%lf ms\n", duration);
	} 
	
	exit(0);
} 

void con() //消费者 
{
	srand((unsigned)getpid());//以pid作为seed
	//获取已有信号量和共享内存 
	//信号量 
	int semid = semget(SEM_KEY, 3, IPC_CREAT|MODE);
	//共享内存 
	int shmid = shmget(SHM_KEY, sizeof(struct MyBuffer), IPC_CREAT|MODE);
	struct MyBuffer* shmptr = shmat(shmid, 0, 0);
	//重复从储存区读取 
	struct timespec begin;//精确获取时间 
	struct timespec end;
	for(int i = 0; i < CON_REP; i++)
	{
		clock_gettime(1, &begin);//记录初始时间 
		P(semid, FULL);//P
		P(semid, MUTEX);
		usleep(rand() % 3000000);//随机等待
		printf("[pid %d] pop %-10s ", getpid(), shmptr->str[shmptr->head]);//读取 
		shmptr->str[shmptr->head][0] = '-';
		shmptr->head = (shmptr->head + 1) % BUF_CNT;
		for (int cnt = 0; cnt < BUF_CNT ; cnt++) {
            printf("[%-5s] ", shmptr->str[cnt]);
            if (cnt != BUF_CNT-1) printf("+ ");
        }

		V(semid, EMPTY);//V
		V(semid, MUTEX);
		clock_gettime(1, &end);//获取最终时间，输出耗时
		double duration = (end.tv_sec - begin.tv_sec) * 1000 + (end.tv_nsec - begin.tv_nsec) / 1000000;
		printf(" running time:%lf ms\n", duration);
	} 
	
	exit(0);
} 


int main(void)
{
	init();
	for(int i = 0; i < PRO_NUM + CON_NUM; i++) 
	{
		pid_t pid = fork();
		if(pid<0)
		{
			printf("fork err\n");
			exit(1);
		}
		else if(pid == 0)
		{
			if(i < PRO_NUM)//生产者 
			{
				printf("create pro\n");
				pro();
			}
			else //消费者 
			{
				printf("create con\n");
				con();
			}	
		}
	}
	for(int i = 0;i < PRO_NUM + CON_NUM; i++)//等待所有子进程 
	{
		wait(NULL);
	} 
}

