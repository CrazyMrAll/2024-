#ifndef P_AND_C_H
#define P_AND_C_H

#include<iostream>
#include<ctime>
#include<cstring> 
#include<windows.h>

//进程个数
#define PRO_NUM 3
#define CON_NUM 4

//重复次数 保证3*8=4*6
#define PRO_REP 8
#define CON_REP 6

//缓冲区大小 
#define BUF_LEN 2
#define BUF_CNT 4

// 定义共享内存相关信息
const TCHAR FileMappingName[] = TEXT("FileMapping");
const TCHAR MutexName[] = TEXT("Mutex");
const TCHAR SemaphoreEmptyName[] = TEXT("Empty");
const TCHAR SemaphoreFullName[] = TEXT("Full");

//缓冲区结构
struct MyBuffer
{
	char str[BUF_CNT][BUF_LEN];
	int head;
	int tail;
};

// 特定字符串
char wqy[] = {"WQY"};

#endif
