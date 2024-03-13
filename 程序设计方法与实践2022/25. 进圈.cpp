#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 1005;
bool map[MAXN][MAXN];
bool visited[MAXN][MAXN];
struct point
{
    int x, y, t;
};
point start, ending, now, tp;
queue<point> q;
bool flag = 1;
int n, m, k, ans;
int a[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};

bool inline check(int i, int j) {
    if (i >= 1 && i <= n && j >= 1 && j <= m) return 1;
    else return 0;
}

int main()
{   
    scanf("%d %d %d\n", &n, &m, &k);
    char t[MAXN];
    for (register int i = 1; i <= n; i++) {
        scanf("%s", t);
        for (register int j = 1; j <= m; j++) {
            char tmp = t[j-1];
            if (tmp == '#')
                map[i][j] = 1;
        }
    }
    scanf("%d %d %d %d", &start.y, &start.x, &ending.y, &ending.x);
    visited[start.y][start.x] = 1;
    if (start.x == ending.x && start.y == ending.y) {
        printf("0\n");
    } else {
        q.push(start);
        while (!q.empty() && flag) {
            now = q.front();
            // printf("Pop map[%d][%d]\n", now.y, now.x);
            q.pop();
            for (register int g = 0; g < 4 && flag; g++) {
                for (register int b = 1; b <= k; b++) {
                    int i = now.y + b*a[g], j = now.x + b*c[g];
                    // printf("i = %d, j = %d\n", i, j);
                    if (check(i, j) && !map[i][j]) {
                        if (!visited[i][j]) {
                            visited[i][j] = 1;
                            tp.y = i, tp.x = j;
                            tp.t = now.t + 1;
                            // printf("Push map[%d][%d]\n", tp.y, tp.x);
                            q.push(tp);
                            if (ending.y == i && ending.x == j) {
                                flag = 0;
                                ans = tp.t;
                                break;
                            }
                        }
                    } else {
                        break;
                    }
                }
            }
        }
        if (flag) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}