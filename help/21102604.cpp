//-----------------程序结构-------------------
#include <stdio.h>
#include <math.h>
int main()
{
    double g[200];
    double avg, sd;
 
    int n, maxi, count;
 
    int allBeInt = 1; //整型标识变量，默认都是
 
    scanf("%d", &n);
 
    maxi = count = 0, avg = 0.0;
 
    //输入及初步处理过程 ...
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &g[i]);
 
        if(g[i] >=0)
        {
            count++;
            avg += g[i];
            maxi = (g[maxi] < g[i]) ? i : maxi;
 
            if(allBeInt && (fabs(g[i] - (int)g[i]) > 0.01))
            {
                allBeInt = 0;
            }
 
        }
 
    }
    sd = 0;
    avg/=count;
    if(allBeInt)
    {
        
        for(int i=0;i<n;i++)
        {
            sd+=pow(fabs((g[i]>=0?g[i]:avg)-avg),2);
        }
        sd=sqrt((double)1/(count-1)*sd);
        printf("%.0lf %d",g[maxi],sd);
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            sd+=pow(fabs(g[i]>=0?g[i]:avg)-avg,2);
            
        }sd=sqrt((double)1/(count-1)*sd);
        if(fabs(g[maxi] - (int)g[maxi]) > 0.01)
        printf("%.1lf %.1lf",g[maxi],sd);
        else
        printf("%.0lf %.1lf",g[maxi],sd);
        //@{你补齐的剩余代码}
 
 
 
    }
 
 
    return 0;
 
}