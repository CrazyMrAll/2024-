#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 1000005;
struct node
{
    int n;
    node* next = NULL;
};
node *p[MAXN];
bool IsUsed[MAXN];
int ans = 0;
int ss, se, es, ee;
int sml, smr, eml, emr;

// 第一次居然想用DFS。。。
// void DFS(int entry) {
//     node *t = p[entry];
//     if (!t) {
//         // cout << endl;
//         return;
//     } else {
//         while (t) {
//             // cout << "cnt = " << cnt << endl;
//             if (t->n == es) {
//                 if (!ans) ans = cnt;
//                 else if (cnt < ans) ans = cnt;
//                 // cout << endl;
//                 return; 
//             }
//             if (IsUsed[t->n]) {
//                 // cout << endl;
//                 return;
//             } else {
//                 IsUsed[t->n] = 1;
//                 // printf("%d->", t->n);
//                 cnt++;
//                 DFS(t->n);
//                 IsUsed[t->n] = 0;
//                 cnt--;
//                 t = t->next;
//             }
//         }
//         // cout << endl;
//         return;
//     }
// } 

int main()
{
    int m;
    scanf("%d", &m);
    int a, b, c, d;
    for (register int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a != d) {
            node *tp = p[a];
            if (p[a]) {
                while (p[a]->next && p[a]->n != d) {
                    p[a] = p[a]->next;
                }
            }
            if (p[a]) {
                p[a]->next = new node;
                p[a]->next->n = d;
                p[a] = tp;
            } else {
                p[a] = new node;
                p[a]->n = d;
            }
        }
    }
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ss = a, sml = b, smr = c, se = d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    es = a, eml = b, emr = c, ee = d;
    if (ss == es && se == ee && sml == eml && smr == emr) {
        printf("1\n");
    } else if (se == es) {
        printf("2\n");
    } else {
        IsUsed[se] = 1;
        // printf("%d->", se);
        // DFS(se);
        queue<int> q;
        node *t;
        q.push(se);
        bool flag = 1;
        int f, b;
        b = q.back();
        while(!q.empty() && flag) {
            f = q.front();
            // cout << "Pop " << f << endl;
            q.pop();
            t = p[f];
            while(t) {
                if (!IsUsed[t->n]) {
                    if (t->n == es) {
                        flag = 0;
                        ans++;
                        break;
                    }
                    IsUsed[t->n] = 1;
                    // cout << "Push " << t->n << endl;
                    q.push(t->n);
                }
                t = t->next;
            }
            if (f == b && flag) {
                ans++;
                b = q.back();
            }
        }
        if (flag) printf("-1\n");
        else printf("%d\n", ans+2);
    }
    // for (int i = 1; i < MAXN; i++) {
    //     bool flag = 0;
    //     while (p[i]) {
    //         if (!flag) printf("%d->", i);
    //         flag = 1;
    //         printf("%d->", p[i]->n);
    //         p[i] = p[i]->next;
    //     }
    //     if (flag) printf("\n");
    // }
    return 0;
}