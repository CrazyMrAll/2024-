#include <stdio.h>
#include <math.h>
#define UPPER 1000001

int N[UPPER] = {0, 1};

int main()
{
    int d = 1;
    int sum = 1;

    int m, n;
    scanf("%d %d", &m, &n);
    for ( int i=m; i<=n; i++ ) {
        sum = 1, d = (int)sqrt(i)+1;
        for ( int j=2; j<d; j++ ) {
            if ( i%j==0 ) {
                d = i/j;
                sum += j + ((d==j) ? 0 : d);


            }
        }

        // if ( i<N[i] )
            N[i] = sum;
    }

    int count = 0;
    for ( int i=m; i<=n; i++ ) {
        if ( N[i]==0 ) continue;

        if ( i==N[N[i]] ) {
            printf("%d %d\n", i, N[i]);
            count++;
            N[N[i]] = 0;
        }
    }
    printf("%d\n", count);

    return 0;
}