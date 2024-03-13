#include <iostream>
using namespace std;
int map[10][10];
bool mark[10][10];
int cnt = 0;
int n, m;

void queen (int num) {
    if ( num==0 ) {
        for ( int i=0; i<n; i++ )
            for ( int j=0; j<n; j++ ) 
                if ( map[i][j]<=1 ) return;
        cnt++;
    } else {
        for ( int i=0; i<n; i++ ) {
            for ( int j=0; j<n; j++ ) {
                if ( mark[i][j] && map[i][j]==1 ) {
                    mark[i][j] = 0;
                    map[i][j]++;
                    for ( int k=1; k<n; k++ ) {
                        if ( j+k<n ) {
                            map[i][j+k]++;
                            if ( i-k>=0 ) map[i-k][j+k]++;
                            if ( i+k<n ) map[i+k][j+k]++;
                        }
                        if ( j-k>=0 ) {
                            map[i][j-k]++;
                            if ( i-k>=0 ) map[i-k][j-k]++;
                            if ( i+k<n ) map[i+k][j-k]++;
                        }
                        if ( i-k>=0 ) map[i-k][j]++;
                        if ( i+k<n ) map[i+k][j]++;
                    }
                    queen(num-1);
                    map[i][j]--;
                    for ( int k=1; k<n; k++ ) {
                        if ( j+k<n ) {
                            map[i][j+k]--;
                            if ( i-k>=0 ) map[i-k][j+k]--;
                            if ( i+k<n ) map[i+k][j+k]--;
                        }
                        if ( j-k>=0 ) {
                            map[i][j-k]--;
                            if ( i-k>=0 ) map[i-k][j-k]--;
                            if ( i+k<n ) map[i+k][j-k]--;
                        }
                        if ( i-k>=0 ) map[i-k][j]--;
                        if ( i+k<n ) map[i+k][j]--;
                    }
                    if ( num!=m ) mark[i][j] = 1;    
                } 
            }
        }
    }
    
}

int main()
{
    scanf("%d %d", &n, &m);
    for ( int i=0; i<n; i++ )
            for ( int j=0; j<n; j++ )
                map[i][j] = mark[i][j] = 1;
    queen(m);
    printf("%d\n", cnt);
    return 0;
}