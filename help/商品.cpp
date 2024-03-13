#include <stdio.h>
#define MAXN 101

int main()
{
    int n;
    int list[MAXN];
    bool flag = 0;
    scanf("%d\n", &n);
    for ( int i=1; i<MAXN; i++ ) 
        list[i] = 0;
    for ( int i=0; i<n; i++ ) {
        int m;
        scanf("%d ", &m);
        for ( int j=0; j<m; j++ ) {
            int t;
            scanf("%d", &t);
            list[t]++;
            if ( list[t]>=n ) flag = 1;
        }
    }
    if ( flag ) {
        for ( int i=1; i<MAXN; i++ )
            if ( list[i]>=n ) printf("%d ", i);
    }
    else printf("NO\n");
    return 0;
}