#include<stdio.h>

int main()
{
    int n, step = 1, method = 1;
    scanf("%d", &n);
    int map[n][n];
    for ( int i=0; i<n; i++ )
        for ( int j=0; j<n; j++ )
            map[i][j] = 0;
    int i, j;
    i = j = 0;
    while ( step<=n*n ) {
        switch (method)
        {
        case 1 : while ( 1 ) {
                    map[i][j++] = step++;
                    if ( map[i][j] || j==n ) {i++;j--;break;}
                } 
                method = 2;
                break;
        case 2 : while ( 1 ) {
                    map[i++][j] = step++;
                    if ( map[i][j] || i==n ) {j--;i--;break;}
                } 
                method = 3;
                break;
        case 3 : while ( 1 ) {
                    map[i][j--] = step++;
                    if ( map[i][j] || i<0 ) {j++;i--;break;}
                } 
                method = 4;
                break;
        case 4 : while ( 1 ) {
                    map[i--][j] = step++;
                    if ( map[i][j] || j<0 ) {i++;j++;break;}
                } 
                method = 1;
                break;
        }    
    }
    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) {
            printf("%3d", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}