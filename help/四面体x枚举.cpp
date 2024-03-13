#include <stdio.h>
#include <math.h>
#define MAXN 50

int main()
{
    int xmax, ymax, zmax, xmin, ymin, zmin, x[4], y[4], z[4], xresult[MAXN], yresult[MAXN], zresult[MAXN], min, cnt = 0;
    xmax = ymax = zmax = INT_MIN;
    min = xmin = ymin = zmin = INT_MAX;
    // 找最大值和最小值，找到一个一定可以包住四面体的长方体
    for ( int i=0; i<4; i++ ) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
        if ( xmax<x[i] ) xmax=x[i];
        if ( ymax<y[i] ) ymax=y[i];
        if ( zmax<z[i] ) zmax=z[i];
        if ( xmin>x[i] ) xmin=x[i];
        if ( ymin>y[i] ) ymin=y[i];
        if ( zmin>z[i] ) zmin=z[i];
    }
    int standard = 0;
    for ( int q=0; q<4; q++ ) {
        standard += (int)sqrt( pow(x[0]-x[q], 2) + pow(y[0]-y[q], 2) + pow(z[0]-z[q], 2) );
        printf("%d ", standard);
    }
    printf("\n");

    // 遍历范围内每一个点
    for ( int i=xmin; i<=xmax; i++ ) {
        for ( int j=ymin; j<=ymax; j++) {
            for ( int k=zmin; k<=zmax; k++ ) {
                int tmp = 0;
                for ( int q=0; q<4; q++ ) {
                    tmp += (int)sqrt( pow(i-x[q], 2) + pow(j-y[q], 2) + pow(k-z[q], 2) );
                }
                if ( tmp<min ) {
                    min = tmp;
                    cnt = 0; 
                } else if ( tmp==min ) {
                    cnt++;
                    if ( cnt>=MAXN ) cnt=0;
                    // 这一步是考虑到就算是最极端的情况四面体高度对称那么符合要求的点也不会太多，
                    // 至少在50个以内的，这里是防止在找到正确答案之前数组越界，
                    // 如果答案都超过50那么一定不是正确答案了就干脆让cnt从头开始循环
                    // （因为我之前一直不对就是因为数组开小了发生了越界导致程序发生一些不可预料的错误）
                    // 没有加入这个步骤以前我把数组大小（MAXN）从10调到100，后面调到1000才对
                }
                else continue;
                xresult[cnt] = i;
                yresult[cnt] = j;
                zresult[cnt] = k; 
            }
        }
    }
    printf("stadard = %d\n", standard);
    printf("%d %d\n", min, cnt+1);
    for ( int i=0; i<=cnt; i++ ) {
        printf("%d %d %d\n", xresult[i], yresult[i], zresult[i]);
    }
    return 0;
}