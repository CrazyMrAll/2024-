#include <iostream>
using namespace std;

int main()
{
    int n, m, max_x, max_y;
    scanf("%d %d", &n, &m);
    int a[n][m];
    bool flag = 1;
    for ( int i=0; i<n; i++ )
        for ( int j=0; j<m; j++ )
            scanf("%d" ,&a[i][j]);
    for ( int i=0; i<n; i++) {
        flag = 1;
        max_x = a[i][0];
        for ( int j=0; j<m-1; j++ ) {
            if ( max_x<a[i][j+1] ) max_x = a[i][j+1];
        }
        for ( int j=0; j<m; j++ ) {
            if ( max_x==a[i][j] ) {
                max_x = j;
                break;
            }
        }
        int max_y = a[i][max_x];
        for ( int i=0; i<n; i++ ) {
            if ( max_y>a[i][max_x] ) {
                flag = 0;
                break;
            }
        }
        if ( flag==0 ) continue;
        else {
            printf("Point:a[%d][%d]==%d\n", i, max_x, a[i][max_x]);
            break;
        }
    }
    if ( flag==0 ) printf("No Point\n");
    return 0;
}