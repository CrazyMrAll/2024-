#include "p_and_c.h"

int main()
{
    HANDLE hMapFile;
    //创建文件映射 
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,  // 临时文件对象 
        NULL,                  
        PAGE_READWRITE,        // 全部权限 
        0,                     // 最小空间 
        sizeof(struct MyBuffer), // 最大空间 
        FileMappingName);    // 使用定义好的const常量 
    // 创建信号量 mutex
    CreateMutex(NULL, FALSE, MutexName);
    // 创建信号量 empty，初值3，最大3 
    CreateSemaphore(NULL, 4, 4, SemaphoreEmptyName);
    // 创建信号量 full，初值0，最大3 
    CreateSemaphore(NULL, 0, 4, SemaphoreFullName);
    // 打开文件映射，清零 
    struct MyBuffer* pBuf = (struct MyBuffer*)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(struct MyBuffer));
    //初始化结构体
    for (int i = 0; i < BUF_CNT; i++)
        pBuf->str[i][0] = '-';
    UnmapViewOfFile(pBuf);//断开连接 
    pBuf = NULL;

	//创建进程（准备信息） 
    PROCESS_INFORMATION pi[PRO_NUM+CON_NUM] = { 0 };//进程信息 
    STARTUPINFO si[PRO_NUM+CON_NUM] = { 0 };//进程信息 
    for (int i = 0; i < PRO_NUM+CON_NUM; i++)//初始化STARTUPINFO 
    {
        si[i].cb = sizeof(STARTUPINFO);
    }
    //创建 生产者 
    TCHAR ProducerName[] = TEXT("producer.exe");
    TCHAR ConsumerName[] = TEXT("consumer.exe");
    for (int i = 0; i < PRO_NUM; i++)
        CreateProcess(NULL, ProducerName, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si[i], &pi[i]);
    //创建 消费者 
    for (int i = PRO_NUM; i < PRO_NUM+CON_NUM; i++)
        CreateProcess(NULL, ConsumerName, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si[i], &pi[i]);
    
    //阻塞进程 
    HANDLE hProcesses[PRO_NUM+CON_NUM];
    DWORD ExitCode;
    for (int i = 0; i < PRO_NUM+CON_NUM; i++)
        hProcesses[i] = pi[i].hProcess;
    // wait...
    WaitForMultipleObjects(PRO_NUM+CON_NUM, hProcesses, TRUE, INFINITE);
    std::cout << "Finished!" << std::endl;
    //释放句柄 
    for (int i = 0; i < PRO_NUM+CON_NUM; i++)
    {
        if (pi[i].hProcess == 0)
            exit(-1);
        GetExitCodeProcess(pi[i].hProcess, &ExitCode);
        CloseHandle(pi[i].hProcess);
        CloseHandle(pi[i].hThread);
    }
    CloseHandle(hMapFile);
    return 0;
}