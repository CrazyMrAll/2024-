#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        int father[n], now, m, t;
        for (register int i = 0; i < n; i++)
            father[i] = -1;
        bool cnt[n], vis[n];
        queue<int> q;
        for (register int i = 0; i < n; i++) {
            scanf("%d:(%d)", &now, &m);
            vis[now] = cnt[now] = 0;
            if (!m) q.push(now);
            for (register int j = 0; j < m; j++) {
                scanf("%d", &t);
                father[t] = now;
            }
        }
        while (!q.empty()) {
            int last = 2;
            now = q.front();
            q.pop();
            t = father[now];
            while (1) {
                // printf("now = %d, last = %d, father = %d\n", now, last, t);
                if (vis[now]) break;
                vis[now] = 1;
                last %= 3;
                if (!last) cnt[now] = 1;
                if (t == -1) {
                    if (last == 2) cnt[now] = 1;
                    break;
                }
                last++;
                now = t;
                t = father[now];
            }
        }
        int ans = 0;
        for (register int i = 0; i < n; i++)
            ans += cnt[i];
        printf("%d\n", ans);
    }
    return 0;
}