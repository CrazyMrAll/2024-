#include <iostream>
#include <queue>
using namespace std;

struct list
{
    int n;
    list *next = NULL;
};

int main()
{
    int n;
    while (cin >> n) {
        bool cnt[n], vis[n];
        list *table[n];
        int now, m, t, Indegree[n];
        for (register int i = 0; i < n; i++) {
            Indegree[i] = vis[i] = cnt[i] = 0;
            table[i] = new list;
        }
        list *tp;
        for (register int i = 0; i < n; i++) {
            scanf("%d:(%d)", &now, &m);
            for (register int j = 0; j < m; j++) {
                scanf("%d", &t);
                tp = table[now]->next;
                table[now]->next = new list;
                table[now]->next->n = t;
                table[now]->next->next = tp;
                tp = table[t]->next;
                table[t]->next = new list;
                table[t]->next->n = now;
                table[t]->next->next = tp;
                Indegree[now]++;
                Indegree[t]++;
            }
        }
        queue<int> q;
        while (1) {
            for (register int i = 0; i < n; i++) {
                if (!vis[i] && Indegree[i] == 1) {
                    vis[i] = 1;
                    Indegree[i]--;
                    q.push(i);
                }
            }
            if (q.empty()) break;
            int now;
            while (!q.empty()) {
                now = q.front();
                q.pop();
                tp = table[now];
                while (tp->next) {
                    tp = tp->next;
                    if (!vis[tp->n]) {
                        vis[tp->n] = cnt[tp->n] = 1; 
                        Indegree[tp->n]--;
                        break;
                    }
                }
            }
            for (register int i = 0; i < n; i++) {
                if (cnt[i]) {
                    tp = table[i];
                    while (tp->next) {
                        tp = tp->next;
                        int tmp = tp->n;
                        vis[tmp] = 1;
                        {
                            list *p = table[tmp];
                            while (p->next) {
                                p = p->next;
                                if (!vis[p->n]) {
                                    Indegree[p->n]--;
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (register int i = 0; i < n; i++)
            ans += cnt[i];
        printf("%d\n", ans);
    }
    return 0;
}