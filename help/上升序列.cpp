#include <stdio.h>
#define MAXN 1000

int main()
{
    int a[MAXN], connect[MAXN], n, max = 0; // 变量说明：connect[MAXN]记录各个子上升序列的所有节点，方便回溯
    scanf("%d", &n);
    for ( int i=0; i<n; i++ ) {
        scanf("%d", &a[i]);
    }
    for ( int j=0; j<n; j++ ) {
        // 将a[j]记录成当前第一个节点
        int cnt = 0; // 变量说明：cnt节点数，亦为当前子上升序列长度
        connect[cnt++] = j;
        // 先找一个以a[j]开头的上升序列，这里的上升序列只需要遇见比上一个节点大的数就行
        for ( int k=j+1; k<n; k++ ) {
            if ( a[k]>a[connect[cnt-1]] ) {
                connect[cnt++] = k;
            }
        }
        if ( cnt>max ) max=cnt;
        cnt--;

        // 不断回溯到上一节点看是否有其他上升序列
        while ( cnt>0 ) {
            int tmpcnt = cnt;
            for ( int k=connect[cnt]+1; k<n; k++) {
                if ( a[k]>a[connect[cnt-1]] ) {
                    connect[cnt++] = k;
                }
            }
            // 如果上一节点并未改变则直接回退到再上一节点
            if ( cnt==tmpcnt ) {
                cnt--;
                continue;
            }

            // 调试信息，可以看每次取出来的上升序列
            // for ( int i=0; i<cnt; i++ ) {
            //     printf("%d ", a[connect[i]]);
            // }
            // printf("  cnt = %d", cnt);
            // printf("\n");


            if ( cnt>max ) max=cnt;
            cnt--;
        }
    }
    printf("%d\n", max);
    return 0;
}