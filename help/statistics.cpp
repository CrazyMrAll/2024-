#include <stdio.h>
#define MIN 1
#define AVG 2
#define MAX 3
 
//截取整数n中一个区段的值，辅助函数。
int getSectVal(int n, int sect)
{
    int scissors = 0x0;//十六进制编码，“剪刀”；注意：十六进制编码与n在计算机里都以二进制形式储存
    int moveDist = 0;
 
    switch(sect)
    {
    case MIN:
        scissors = 0x00FF0000;
        moveDist = 16;
        break;
    case AVG:
        scissors = 0x0000FF00;
        moveDist = 8;
        break;
    case MAX:
        scissors = 0x000000FF;
        moveDist = 0;
    }
 
    int val = (n & scissors);//剪下片段//留下相应位置的数1或0；
    val = (val >> moveDist);//段移到最右侧//movedist意味着右移相应的单位
 
    return val;
}
//分数在[0, 150]区间
int stat(int score[], int n)
{
    int _min = score[0];
    int _max = score[0];
    int _avg = score[0];
    for(int i = 1; i < n; i++)
    {
        _avg += score[i];
 
        if(_min > score[i]) _min = score[i];
        if(_max < score[i]) _max = score[i];
 
    }
    _avg /= n;
 
    int rs = 0;
    //将3个255以内的正整数，拼接成一个整数
    rs |= (_min<<16);//左移到对应的区段
    printf("%0X\n", rs);
    rs |= (_avg<<8);
    printf("%0X\n", rs);
    rs |= _max;
    return rs;//即为拼接得到的结果，一个没意义的大整数
}
 
int main()
{
    int n = 0;
    int score[500]; //总数最大500
 
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", score+i); //&score[i]
    }
 
    int rs = stat(score, n);
    {
        //调试用
        printf("%0X\n", rs);
    }
    printf("%d %d %d\n", getSectVal(rs, MIN),
            getSectVal(rs, AVG),
            getSectVal(rs, MAX)
          );
 
    return 0;
 
} 