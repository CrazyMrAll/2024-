//
//-----------↓↓↓↓程序结构↓↓↓↓--------------------       
#include <stdio.h>
#include <stdlib.h>
//数据定义
int a[15][15] = { { 0 } };  //数值矩阵
int path[30];               //路径节点上的数值
int maxv = 0;               //最大值
int count = 0;              //路径数
int nsize;                  //矩阵的阶数
int endIdx;                 //路径最后一个节点的编号(从0开始)
 
/* 把路径上的值累加起来 */
int sumPath()
{
    int i, sum;
    for (sum = i = 0; i <= endIdx; i++)
    {
        sum += path[i];
    }
    return sum;
}
 
/*
 * 参数定义
 * row: 行号；column: 列号；index: 路径节点编号，都从0开始编号; 
 * 也可再增加一个参数：每到一个点即累加一个数，并向后传递，从而避免使用 
 * sumPath()每次从头累加，以减少计算总量。No.11 评测点可体现此策略。
 * */
void navigate(int row, int column, int sumnow)
{
    sumnow += a[row][column];
    if ( column==nsize-1 && row==0 ) {
        if ( sumnow>maxv ) {
            maxv = sumnow;
            count = 1;
        } else if ( sumnow==maxv ) {
            count++;
        }
        return;
    } else {
        if ( row==0 ){
            navigate(row,column+1,sumnow);
        }
        else if ( column==nsize-1 ) {
            navigate(row-1,column,sumnow);
        }
        else {
            navigate(row,column+1,sumnow);
            navigate(row-1,column,sumnow);
        }
        sumnow -= a[row][column];
    }
}
 
int main()
{    
    scanf("%d", &nsize);
    endIdx = 2 * (nsize - 1); //路径最后一个节点的编号
    /* 矩阵数据读入 */
    for (int i = 0; i < nsize; i++)
    {
        for (int j = 0; j < nsize; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    maxv = 0;
    navigate(nsize - 1, 0, 0);
    printf("%d %d\n", count, maxv);
    return 0;
}   