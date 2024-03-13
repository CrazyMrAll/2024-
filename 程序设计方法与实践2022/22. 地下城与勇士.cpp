#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN = 105;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN][55];
struct point
{
    int x, y, t;
};
queue<point> q;
point start, ending, f, tp;
int ans = 0;
int n, m, k;
bool flag = 1;

void inline check() {
    int i = tp.y, j = tp.x, z = (f.t+1)%k;
    if (!visited[i][j][z]) {
        if (map[i][j] == 0) {
            tp.t = f.t + 1;
            visited[i][j][z] = 1;
            // printf("tp.x = %d, tp.y = %d\n", tp.x, tp.y);
            // cout << z << ":";
            // printf("Push map[%d][%d] t = %d\n", tp.y, tp.x, tp.t);
            q.push(tp);
        } else if (map[i][j] == -1) {
            if (f.t%k == k-1) {
                tp.t = f.t + 1;
                visited[i][j][z] = 1;
                // printf("Push map[%d][%d] t = %d\n", tp.y, tp.x, tp.t);
                q.push(tp);
            }
        }
    }
    // cout << 1 << endl;
    if (tp.x == ending.x && tp.y == ending.y) {
        // printf("ending.x = %d, ending.y = %d\n", ending.x, ending.y); 
        ans = tp.t;
        flag = 0;
    }
}

int main()
{
    int T;
    scanf("%d\n", &T);
    for (register int g = 0; g < T; g++) {
        flag = 1;
        ans = 0;
        scanf("%d %d %d\n", &n, &m, &k);
        char tmps[105], tmp;
        ending.x = ending.y = -1;
        for (register int i = 0; i < n; i++) {
            scanf("%s", tmps);
            for (register int j = 0; j < m; j++) {
                tmp = tmps[j];
                if (tmp == 'S') {
                    start.x = j;
                    start.y = i;
                } else if (tmp == 'E') {
                    ending.x = j;
                    ending.y = i;
                } else if (tmp == '#') {
                    map[i][j] = 1;
                } else if (tmp == '*') {
                    map[i][j] = -1;
                }
            }
        }   
        // for (register int i = 0; i < n; i++) {
        //     for (register int j = 0; j < m; j++) 
        //         cout << map[i][j];
        //     cout << endl;
        // }  
        // printf("strat.x = %d, start.y = %d\n", start.x, start.y);
        // printf("ending.x = %d, ending.y = %d\n", ending.x, ending.y); 
        start.t = 0;
        visited[start.y][start.x][0] = 1;
        q.push(start);
        while (!q.empty() && flag) {
            f = q.front();
            // printf("  Pop  map[%d][%d] t = %d\n", f.y, f.x, f.t);
            q.pop();
            if (f.y > 0) {
                tp = f;
                tp.y = f.y - 1;
                check();
            }
            if (f.x+1 < m && flag) {
                tp = f;
                tp.x = f.x + 1;
                check();
            }
            if (f.y+1 < n && flag) {
                tp = f;
                tp.y = f.y + 1;
                check();
            }
            if (f.x > 0 && flag) {
                tp = f;
                tp.x = f.x - 1;
                check();
            }
        }
        if (flag) printf("-1\n");
        else printf("%d\n", ans);
        // for (int z = 0; z < k; z++) {
        //     for (int i = 0; i < n; i++) {
        //         for (int j = 0; j < m; j++) {
        //             cout << visited[i][j][z];
        //         }   
        //         cout << endl;   
        //     }   
        //     cout << endl;
        // }
        if (g < T-1) {
            memset(visited, 0, sizeof(visited));
            memset(map, 0, sizeof(map));
            while (!q.empty()) q.pop();
        }
    }
    return 0;
}