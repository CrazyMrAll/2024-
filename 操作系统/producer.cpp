#include "p_and_c.h"

char *randc()
{
    static char buf[BUF_LEN];
    int n = rand() % 3;
    buf[0] = wqy[n];
    return buf;
}

int main(void)
{
	HANDLE hMapFile;
	struct MyBuffer* pBuf;
	int pid = GetCurrentProcessId();
	srand(pid);
 
	//shmget获取映射 OpenFileMapping
    hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,//全部权限 
        FALSE,      		//不继承 
        FileMappingName);//使用前面定义的const常量 
	//shmat获取地址 MapViewOfFile
    pBuf = (struct MyBuffer*)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(struct MyBuffer));

    //打开Mutex ，使用const常量的ipName 
    HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, TRUE, MutexName);
    //打开Empty 
    HANDLE hEmpty = OpenSemaphore(SEMAPHORE_ALL_ACCESS, TRUE, SemaphoreEmptyName);
    //打开FULL 
    HANDLE hFull = OpenSemaphore(SEMAPHORE_ALL_ACCESS, TRUE, SemaphoreFullName);

    //写入 
    int sleepTime;
    LARGE_INTEGER start_time, end_time;
    LARGE_INTEGER freq;
    double running_time;
    for (int i = 0; i < PRO_REP; i++)
    {
        QueryPerformanceCounter(&start_time);
        sleepTime = rand() % 3000;
        // p(empty)
        WaitForSingleObject(hEmpty, INFINITE);
        // p(mutex)
        WaitForSingleObject(hMutex, INFINITE);
        // sleep
        Sleep(sleepTime);

        // 写入 
        char* s = pBuf->str[pBuf->tail];
        strcpy(s, randc());
        pBuf->tail = (pBuf->tail + 1) % BUF_CNT;
        printf("[pid %d] producer: push %-10s ", pid, s);
        
        // 显示缓冲区 
        for (int cnt = 0; cnt < BUF_CNT ; cnt++) {
            printf("[%-5s] ", pBuf->str[cnt]);
            if (cnt != BUF_CNT-1) printf("+ ");
        }

        QueryPerformanceCounter(&end_time);
        QueryPerformanceFrequency(&freq);
        running_time = (double)(end_time.QuadPart - start_time.QuadPart) / freq.QuadPart;
        printf(" running time:%lf s\n", running_time);
        
        // v(mutex)
        ReleaseMutex(hMutex);
        // v(full)
        ReleaseSemaphore(hFull, 1, NULL);
    }

    // release resources
    CloseHandle(hEmpty);
    CloseHandle(hFull);
    CloseHandle(hMutex);
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
    return 0;
}