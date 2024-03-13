#include <iostream>
using namespace std;

int main()
{
    int map[101][101]={{0}}, island[100]={0}, n, m, cnt = 0;
    scanf("%d %d\n", &n, &m);
    for ( int i=1; i<=n; i++ ) {
        for ( int j=1; j<=m; j++ ) {
            char tmp;
            scanf("%c", &tmp);
            if ( tmp=='I' ) {
                int min = cnt + 1;
                if ( map[i-1][j+1]<min && map[i-1][j+1] ) min=map[i-1][j+1];
                if ( map[i-1][j]<min && map[i-1][j] ) min=map[i-1][j];
                if ( map[i-1][j-1]<min && map[i-1][j-1] ) min=map[i-1][j-1];
                if ( map[i][j-1]<min && map[i][j-1] ) min=map[i][j-1];

                if ( min==cnt+1 ) {
                    map[i][j] = ++cnt;
                } else {
                    map[i][j] = min;
                    if ( map[i-1][j+1]>min ) {map[i-1][j+1]=min,cnt--;}
                    if ( map[i-1][j]>min ) {map[i-1][j]=min,cnt--;}
                    if ( map[i-1][j-1]>min ) {map[i-1][j-1]=min,cnt--;}
                    if ( map[i][j-1]>min ) {map[i][j-1]=min,cnt--;}
                }

            }
        }
        getchar();
    }
    for ( int i=1; i<=n; i++ ) {
        for ( int j=1; j<=m; j++ ) {
            if ( map[i][j] ) island[map[i][j]]++;
            // printf("%d", map[i][j]);
        }
        // printf("\n");
    }
    int max = island[1];
    for ( int i=2; i<=cnt; i++ ) {
        if ( island[i]>max ) max=island[i];
    }
    printf("%d\n", max);
    return 0;
}