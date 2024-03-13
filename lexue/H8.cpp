#include <iostream>
using namespace std;
#define wtf 10000007

int main()
{
    int n;
    int map[666][666];
    scanf("%d", &n);
    for ( int i=0; i<n; i++ ) 
        for ( int j=0; j<n; j++ )
            map[i][j] = 0;
    map[n-1][n-1] = 1;
    for ( int cnt=2*n-1; cnt>=1; cnt-- ) {
        int i, j;
        if ( cnt>n ) {
            j = n-1;
            i = cnt - n;
        } else { 
            j = cnt - 1;
            i = 0;
        }
        while ( j>=((cnt>n)?cnt-n:0) && i<=((cnt>n)?n-1:cnt-1) ) {
            if ( j-1>=0 ) {
                map[i][j-1] += map[i][j]%wtf;
                if ( i+1<=n-1 ) {
                    map[i+1][j-1] += map[i][j]%wtf;
                }
            }
            if ( i-1>=0 ) map[i-1][j] += map[i][j]%wtf;
            j--;
            i++;
        }
    }
    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) {
            printf("%d\t", map[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", map[0][0]%wtf);
    return 0;
}