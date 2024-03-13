#include <stdio.h>
int n, m, cnt = 0, max = 0, tmp_max = 0;
bool map[100][100];

// 在周围搜索
void search(int i, int j) {
    if ( i-1>=0 ) {
        if ( j-1>=0 && map[i-1][j-1] ) {
            map[i-1][j-1] = 0; 
            tmp_max++;
            search(i-1,j-1);
        }
        if ( map[i-1][j] ) {
            map[i-1][j] = 0; 
            tmp_max++;
            search(i-1,j);
        }
        if ( j+1<m && map[i-1][j+1] ) {
            map[i-1][j+1] = 0; 
            tmp_max++;
            search(i-1,j+1);
        }
    }
    if ( j-1>=0 && map[i][j-1] ) {
        map[i][j-1] = 0;
        tmp_max++;
        search(i,j-1);
    }
    if ( j+1>=0 && map[i][j+1] ) {
        map[i][j+1] = 0;
        tmp_max++;
        search(i,j+1);
    }
    if ( i+1<n ) {
        if ( j-1>=0 && map[i+1][j-1] ) {
            map[i+1][j-1] = 0; 
            tmp_max++;
            search(i+1,j-1);
        }
        if ( map[i+1][j] ) {
            map[i+1][j] = 0; 
            tmp_max++;
            search(i+1,j);
        }
        if ( j+1<m && map[i+1][j+1] ) {
            map[i+1][j+1] = 0; 
            tmp_max++;
            search(i+1,j+1);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<m; j++ ) {
            char tmp;
            scanf("%c", &tmp);
            if ( tmp=='I' ) map[i][j]=1;
            else map[i][j]=0;
        }
        getchar();
    }
    for ( int i=0; i<n; i++ ) {
        for ( int j=0; j<m; j++ ) {
            if ( map[i][j] ) { //判断是否搜索过
                map[i][j] = 0; // 代表搜索过
                cnt++;
                tmp_max = 1;
                search(i,j);
                if ( tmp_max>max ) max=tmp_max;
            }
        }
    }
    printf("%d %d\n", cnt, max);
    return 0;
}