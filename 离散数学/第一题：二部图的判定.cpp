#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 10;
bool map[MAXN][MAXN];
int color[MAXN];//function as vis

int main()
{
    int n;
    scanf("%d", &n);
    bool flag = 1;
    queue<int> q;
    for (register int i = 0; i < n && flag; i++)
        for (register int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (i == j && map[i][j]) {
                flag = 0;
                break;
            }
        }
    for (register int i = 0; i < n && flag; i++) {
        if (!color[i]) {
            q.push(i);
            color[i] = 1;
        }
        while (!q.empty()) {
            int t = q.front();
            // printf("now = %d\n", t);
            int tc = color[t];
            q.pop();
            for (register int j = 0; j < n; j++)
                if (map[t][j]) {
                    if (!color[j]) {
                        q.push(j);
                        color[j] = -tc;
                    } else if (color[j] == tc) {
                        flag = 0;
                        break;
                    }
                }
        }
    }
    if (flag) printf("yes\n");
    else printf("no\n");
    return 0;
}