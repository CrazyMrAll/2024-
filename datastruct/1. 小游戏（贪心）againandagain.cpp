#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1501;
int l[MAXN], map[MAXN][16], n;
bool s[MAXN], vis[MAXN];

int dfs(int u) {
    bool flag = 0;
    int r = 0; 
    vis[u] = 1;
    for(int i = 0; i < l[u]; i++) {
        if (vis[map[u][i]]) continue;
        r += dfs(map[u][i]);
        if (!s[map[u][i]]) flag = 1;
    }
    return r + (s[u] = flag);
}
int main()
{
    while(cin >> n) {
        if (n == 1) printf("1\n");
        else {
            for (register int i = 0; i < n; i++)
                l[i] = s[i] = vis[i] = 0;
            int now, m, t;
            for(register int i = 0; i < n; i++) {
                scanf("%d:(%d)", &now, &m);
                for (register int j = 0; j < m; j++) {
                    scanf("%d", &t);
                    map[now][l[now]++] = t;
                    map[t][l[t]++] = now;
                }
            }
            printf("%d\n", dfs(0));
        }
    }
}