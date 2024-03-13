#include <iostream>
#include <stack>
#include <queue>
#include <limits.h>
using namespace std;
const int MAXN = 100;

struct list
{
    int name, w, e;
    list *next = NULL;
};
list *table[MAXN];
int Indegree[MAXN], ve[MAXN], vl[MAXN];
char head[MAXN][5];

list *h = new list;
list *tail = h;
void path(int start) {
    // printf("now %s\n", head[start]);
    list *tmp = tail;
    tail->next = new list;
    tail = tail->next;
    tail->name = start;
    list *tp = table[start];
    if (!tp->next) {
        tp = h;
        while (tp->next) {
            tp = tp->next;
            printf("%s", head[tp->name]);
            if (tp->next) printf("-");
            else printf("\n");
        }
    } else {
        priority_queue<int, vector<int>, greater<int>> q;
        while (tp->next) {
            tp = tp->next;
            if (tp->e == vl[tp->name]-tp->w) q.push(tp->name);
        }
        while (!q.empty()) {
            path(q.top());
            q.pop();
        }
    }
    tail = tmp;
    delete tmp->next;
}

int main()
{
    int V, E;
    scanf("%d,%d\n", &V, &E);
    char tmp;
    for (register int i = 0; i < V; i++) {
        for (register int j = 0; ; j++) {
            scanf("%c", &tmp);
            if (tmp != ',' && tmp != '\n') {
                head[i][j] = tmp;
            } else {
                head[i][j] = '\0';
                break;
            }
        }
        table[i] = new list;
        ve[i] = Indegree[i] = 0;
    }
    int a, b, c;
    list *tp;
    for (register int i = 0; i < E; i++) {
        scanf("<%d,%d,%d>", &a, &b, &c);
        getchar();
        Indegree[b]++;
        tp = table[a]->next;
        table[a]->next = new list;
        table[a]->next->name = b;
        table[a]->next->w = c;
        table[a]->next->next = tp;
    }
    // for (register int i = 0; i < V; i++) {
    //     printf("%d:", i);
    //     tp = table[i];
    //     while (tp->next) {
    //         tp = tp->next;
    //         printf("%s->", head[tp->name]);
    //     }
    //     printf("\n");
    // }
    int start, now;
    for (register int i = 0; i < V; i++) 
        if (!Indegree[i]) {
            start = i;
            break;
        }
    priority_queue<int, vector<int>, greater<int>> q;
    stack<int> s;
    queue<int> ans;
    q.push(start);
    while (!q.empty()) {
        now = q.top();
        tp = table[now];
        // printf("%s", head[now]);
        // if (tp->next) printf("-");
        // else printf("\n");
        q.pop();
        s.push(now);
        ans.push(now);
        while (tp->next) {
            tp = tp->next;
            if (--Indegree[tp->name] == 0) q.push(tp->name);
            else if (Indegree[tp->name] < 0) continue;
            ve[tp->name] = max(ve[tp->name], ve[now]+tp->w);
            tp->e = ve[now];
        }
    }
    while (!s.empty()) {
        now = s.top();
        s.pop();
        tp = table[now];
        if (tp->next) {
            int t = INT_MAX;
            while (tp->next) {
                tp = tp->next;
                t = min(t, ve[tp->name]-tp->w);
            }
            vl[now] = t;
        } else vl[now] = ve[now];
    }
    // for (register int i = 0; i < V; i++) 
    //     printf("%d: ve = %d, vl = %d\n", i, ve[i], vl[i]);
    bool flag = 1;
    for (register int i = 0; i < V; i++)
        if (Indegree[i]) {
            flag = 0;
            break;
        }
    if (flag) {
        while (1) {
            printf("%s", head[ans.front()]);
            ans.pop();
            if (ans.empty()) {
                printf("\n");
                break;
            } else printf("-");
        }
        path(start);
    } else printf("NO TOPOLOGICAL PATH\n");
    return 0;
}