#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <string.h>
using namespace std;
const int MAXN = 300005;
bool visited[MAXN];
vector<list<int>> v(MAXN);
queue<int> q;
list<int> num;

int main()
{ 
    int n, m, ans = -1;
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        bool Isexit = 1;
        // for (auto i = v[a].begin(); i != v[a].end(); ++i) {
        //     if (b == *i) {
        //         Isexit = 0;
        //         break;
        //     }
        // }
        // if (Isexit) v[a].push_back(b);
        v[a].push_back(b);
        bool IsUesed[MAXN];
        if (!visited[a] || !visited[b]) {
            visited[a] = visited[b] = 1;
        } else {
            int t = b;
            IsUesed[t] = 1;
            // printf("Push %d\n", t);
            q.push(t);
            bool flag = 1;
            while (!q.empty() && flag) {
                int f = q.front();
                // printf("Pop %d\n", f);
                q.pop();
                for (auto i = v[f].begin(); i != v[f].end(); ++i) {
                    if (*i == a) {
                            flag = 0;
                            break;
                    }
                    if (!IsUesed[*i]) {
                        // printf("Push %d\n", *i);
                        q.push(*i);
                        IsUesed[*i] = 1;
                    }
                }
                    
            }
            if (!flag) {
                ans = i + 1;
                break;
            } 
        }
    }
    printf("%d\n", ans);
    return 0;
}