#include <stdio.h>
#include <ctype.h>
#include <string.h> //字符数组相关
 
/*
解决思路：
1）逐个取出数值数据缓存到临时数组中；2）识别分类后重新拼接。
*/
 
int main()
{
    bool hasDigi = false;
    bool hasDot = false;
    int countN = 0, countF = 0;     
     
    char str[300]; //存放原始字符串(不足300)
    char nstr[300] = {'\0'};//存放整数
    char fstr[300] = {'\0'};//存放浮点数
 
    char tstr[25] = {'\0'}; //临时缓存数值数据
    int dataLen = 0;  //记录每个数据的长度
 
    gets(str); //一次性读入全部字符（可能包含空格）
 
    int len = strlen(str); //已读字符串的实际长度
 
    //从字符串中逐个取出字符
    for(int i = 0; i <= len; i++)
    {
        // 判断字符是否是数字 ↓↓↓↓↓       
        if (isdigit(str[i])) //用专门的库函数
        {
            hasDigi = true;
            tstr[dataLen++] = str[i]; //缓存，执行了两步操作
        }
        else if (str[i] == '.')
        {
            hasDot = true;
            tstr[dataLen++] = str[i]; //缓存，...            
        }
        else
        {//【一个】数据结束
 
            //↓↓↓ 在这样加，产生bug 
            //tstr[dataLen++] = ((str[i] == '\0') ? '\0' : ' ');
 
            //缓存数据末尾加上结束标识          
            tstr[dataLen] = '\0'; //【重要】
 
            if (hasDot && hasDigi)
            {
                //在已有拼接的字符数组后加空格
                if(countF) fstr[strlen(fstr)] = ' ';
                strcat(fstr,tstr);
                                 
                //@{你的代码语句，拼接缓存的有效数值字符串};
                countF++;
            }
            else if (!hasDot && hasDigi)
            {
                //在已有拼接的字符数组后加空格
                if(countN) nstr[strlen(nstr)] = ' ';
                strcat(nstr,tstr);
                 
                //@{你的代码语句，拼接缓存的有效数值字符串};
                countN++;
            }            
 
            //重置状态，重要
            hasDigi = hasDot = false;
            dataLen = 0;
        }
    }
 
    if(countF&&countN==0)
   {printf("%d:%s",countF,fstr);}
   else if(countN&&countF==0)
    {printf("%d:%s",countN,nstr);}
    else if(countF&&countN)
    {
        printf("%d:%s\n",countN,nstr);
        printf("%d:%s",countF,fstr);}//@{你的代码片段：
    else
    printf("NO DATA");
     
     
     
 
    return 0;
}
/* 思考
1）Line 28 for循环i的上界包含 i == len 的目的是什么？
2）Line 45 原本设计在缓存数组tstr末尾加空格，产生了bug。。。？
3）Line 16-18 字符数组大小的依据什么？ Line 20 tstr 数组大小足够 ？
*/