#include <stdio.h>
#include <math.h>

int main()
{
    int m, n, cnt = 0;
    scanf("%d %d", &m, &n);
    for ( ; m<=n; m++ ) {
        int d, sum, sum2, max;
        max = sqrt(m);
        sum = 1;
        for ( int i=2; i<=max; i++ )
            if ( m%i==0 ) {
                d = m/i;
                sum += i + ((d==i) ? 0 : d);
            }
        if ( sum<=n && m<=sum ) {
            max = sqrt(sum);
            sum2 = 1;
            for ( int i=2; i<=max; i++ )
                if ( sum%i==0 ) {
                    d = sum/i;
                    sum2 += i + ((d==i) ? 0 : d);
                }
            if ( m==sum2 ) {
                cnt++;
                printf("%d %d\n", m, sum);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}