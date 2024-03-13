#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 10;
bool vis[MAXN];

struct list {
    int n;
    list *next = NULL;
};

void inline Insert(list *tp, int x) {
    list *tmp;
    while (tp->next && x > tp->next->n) 
        tp = tp->next;
    tmp = tp->next;
    tp->next = new list;
    tp->next->n = x;
    tp->next->next = tmp;
}

int main()
{
    int n;
    scanf("%d", &n);
    list *table[MAXN];
    for (register int i = 0; i < n; i++)
        table[i] = new list;
    int a, b;
    while (scanf("%d", &a) && a != -1) {
        scanf("%d", &b);
        Insert(table[a], b);
        Insert(table[b], a);
    }
    queue<int> q;
    for (register int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            q.push(i);
            int t, cnt = 0;
            list *tp;
            while (!q.empty()) {
                if (cnt++) printf("-");
                t = q.front();
                printf("%d", t);
                q.pop();
                tp = table[t];
                while (tp->next) {
                    tp = tp->next;
                    if (!vis[tp->n]) {
                        vis[tp->n] = 1;
                        q.push(tp->n);
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}