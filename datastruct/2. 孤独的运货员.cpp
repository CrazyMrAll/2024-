#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int T, N, S, Q;
    scanf("%d", &T);
    for (register int g = 0; g < T; g++) {
        scanf("%d %d %d", &N, &S, &Q);
        queue<int> q[N+1];
        stack<int> stack;
        int n, t, total = 0;
        for (register int i = 1; i <= N; i++) {
            scanf("%d", &n);
            total += n;
            for (register int j = 1; j <= n; j++) {
                scanf("%d", &t);
                q[i].push(t);
            } 
        }
        int now = 1, atotal = 0, ans = 0;
        while(1) {
            // printf("%d: %d %d\n", now, atotal, ans);
            while(1) {
                if (!stack.empty()) {
                    t = stack.top();
                    if (t == now) {
                        stack.pop();
                        // printf("%d delivery!\n", t);
                        atotal++;
                        ans++;
                    } else if ((int)q[now].size() < Q) {
                        // printf("add q[%d] %d\n", now, t);
                        stack.pop();
                        ans++;
                        q[now].push(t);
                    } else break;
                } else break;
            }
            // printf("stacksize = %d, q[now]size = %d\n", (int)stack.size(), (int)q[now].size());
            while((int)stack.size() < S && !q[now].empty()) {
                t = q[now].front();
                // printf("load %d\n", t);
                q[now].pop();
                stack.push(t);
                ans++;
            }
            if (atotal == total) break;
            else {
                ans += 2;
                now = now % N + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}