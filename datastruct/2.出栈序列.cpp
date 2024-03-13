#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n, m, t;
    bool flag = 0;
    while (scanf("%d%d", &n, &m) && n && m) {
        if (flag) printf("\n");
        flag = 1;
        for (register int i = 0; i < m; i++) {
            stack<int> s;
            queue<int> q;
            for (register int j = 1; j <= n; j++) {
                scanf("%d", &t);
                s.push(j);
                q.push(t);
                while (!s.empty()) {
                    if (s.top() == q.front()) {
                        s.pop();
                        q.pop();
                    } else break;
                }
            }
            if (s.empty()) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}