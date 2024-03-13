#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct list {
    int p = -1, w;
    list *next = NULL;
};

struct node {
    int Indegree, t;
    list *egdeto, *pre;
};

int main()
{
    int V, E;
    scanf("%d,%d\n", &V, &E);
    char head[V][5], tmp;
    node Info[V];
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
        Info[i].t = Info[i].Indegree = 0;
        Info[i].egdeto = new list;
        Info[i].pre = new list;
        Info[i].egdeto->next = Info[i].pre->next = NULL;
    }
    int a, b, c;
    list *tp, *tmpp;
    for (register int i = 0; i < E; i++) {
        scanf("<%d,%d,%d>", &a, &b, &c);
        getchar();
        Info[b].Indegree++;
        tp = Info[a].egdeto;
        // 按照升序插入节点
        while (tp->next && b > tp->next->p) 
            tp = tp->next;
        tmpp = tp->next;
        tp->next = new list;
        tp = tp->next;
        tp->p = b;
        tp->w = c;
        tp->next = tmpp;
    }
    int start;
    for (register int i = 0; i < V; i++) 
        if (!Info[i].Indegree) {
            start = i;
            break;
        }
    priority_queue<int, vector<int>, greater<int>> q;
    queue<int> ans;
    q.push(start);
    int now;
    while (!q.empty()) {
        now = q.top();
        ans.push(now);
        q.pop();
        tp = Info[now].egdeto;
        while (tp->next) {
            tp = tp->next;
            if (--Info[tp->p].Indegree == 0) q.push(tp->p);
            else if (Info[tp->p].Indegree < 0) break;
            // 动态更新pre，考虑到有更大的，以及相同大的，并且实时释放空间
            if (Info[now].t + tp->w >= Info[tp->p].t) {
                tmpp = Info[tp->p].pre;
                if (!tmpp->next) {
                    tmpp->next = new list;
                    tmpp = tmpp->next;
                    tmpp->p = now;
                    Info[tp->p].t = Info[now].t + tp->w;
                } else {
                    tmpp = tmpp->next;
                    if (Info[now].t + tp->w > Info[tp->p].t) {
                        Info[tp->p].t = Info[now].t + tp->w;
                        tmpp->p = now;
                        list *ttp;
                        while (tmpp->next) {
                            tmpp = tmpp->next;
                            ttp = tmpp->next;
                            delete tmpp;
                            tmpp = ttp;
                        }
                    } else {
                        while (tmpp->next) tmpp = tmpp->next;
                        tmpp->next = new list;
                        tmpp = tmpp->next;
                        tmpp->p = now;
                    }
                }
            }
        }
    }
    for (register int i = 0; i < V; i++)
        printf("%d ", Info[i].t);
    printf("\n");
    bool flag = 1;
    for (register int i = 0; i < V; i++)
        if (Info[i].Indegree) {
            flag = 0;
            break;
        }
    if (flag) {
        printf("%s", head[ans.front()]);
        ans.pop();
        while (!ans.empty()) {
            printf("-%s", head[ans.front()]);
            ans.pop();
        }
        printf("\n");
        int max = -1, maxi;
        for (register int i = 0; i < V; i++)
            if (Info[i].t > max) {
                max = Info[i].t;
                maxi = i;
            }
        stack<int> s;
        bool tflag = 1;
        while (tflag) {
            tflag = 0;
            s.push(maxi);
            tp = Info[maxi].pre;
            while (tp->next) {
                s.push(tp->next->p);
                tp = Info[s.top()].pre;
            }
            printf("%s", head[s.top()]);
            s.pop();
            while (!s.empty()) {
                now = s.top(); 
                printf("-%s", head[now]);
                tp = Info[now].pre;
                if (tp->next->next && !tflag) {
                    tflag = 1;
                    tmpp = tp->next->next;
                    delete tp->next;
                    tp->next = tmpp;
                }
                s.pop();
            }
            printf("\n"); 
        }
    } else printf("NO TOPOLOGICAL PATH\n");
    return 0;
}