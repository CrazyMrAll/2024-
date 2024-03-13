#ifndef P_AND_C_H
#define P_AND_C_H

#include<stdio.h>//标准库 
#include<time.h>
#include<string.h> 
#include<stdlib.h> 

#include<unistd.h>//进程库
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/wait.h>

//进程个数
#define PRO_NUM 3
#define CON_NUM 4

//重复次数
#define PRO_REP 8
#define CON_REP 6

//缓冲区大小 
#define BUF_LEN 2
#define BUF_CNT 4

//内存，信号量key 
#define SHM_KEY 1234
#define SEM_KEY 1235
#define MUTEX 0
#define EMPTY 1
#define FULL 2

//模式，可读可写 
#define MODE 0600 

//缓冲区结构
struct MyBuffer
{
	char str[BUF_CNT][BUF_LEN];
	int head;
	int tail;
};

#endif
