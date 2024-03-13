#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int sum = 0;
    for ( int i=0; i<m; i++ ) {
        for ( int j=0; j<n; j++ ) {
            int tmp;
            scanf("%d", &tmp);
            if ( (i==0 || i==m-1) || (j==0 || j==n-1) ) sum+=tmp;
        }
    }
    printf("%d\n", sum);
    return 0;
}