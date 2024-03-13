#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <string.h>
using namespace std;
const int MAXN = 300005;
bool IsUesed[MAXN];
queue<int> q;
vector<list<int>> v(MAXN);
list<int> num;

int main()
{ 
    int n, m, ans = -1;
    scanf("%d %d", &n, &m);
    int a, b;
    bool flagn = 1, flag = 1;
    for (int i = 0; i < m && flag; i++) {
        // cout << i+1 << " round: " << endl;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        flagn = 1;
        for (list<int>::iterator it = num.begin(); it != num.end(); it++) {
            if (*it == a) {
                flagn = 0;
                break;
            }
        }
        if (flagn) num.push_back(a);
        // for (auto p = num.begin(); p != num.end(); ++p) {
        // 	cout << *p << ": ";
        //     for (auto j = v[*p].begin(); j != v[*p].end(); ++j)
        //         cout << *j << "->";
        //     cout << endl;
        // }
        // auto tb = num.begin(), te = num.end();
        // printf("begin = %d end = %d\n", *tb, *te);
        for (auto it = num.begin(); it != num.end() && flag; ++it) {
                int t = *it;
                IsUesed[t] = 1;
                // printf("Push %d\n", t);
                q.push(t);
                while (!q.empty() && flag) {
                    int f = q.front();
                    // printf("Pop %d\n", f);
                    q.pop();
                    for (auto i = v[f].begin(); i != v[f].end(); ++i) 
                        if (!IsUesed[*i]) {
                            // printf("Push %d\n", *i);
                            q.push(*i);
                            IsUesed[*i] = 1;
                        } else {
                            if (*i == t) {
                                // printf("Change!!\n");
                                flag = 0;
                                break;
                            }
                        }
                }
                if (!flag) {
                    ans = i + 1;
                    break;
                } else {
                    while(!q.empty()) q.pop();
                    memset(IsUesed, 0, sizeof(IsUesed));
                }
                // cout << endl;
        }
    }
    // for (auto p = num.begin(); p != num.end(); ++p) {
	// 	cout << *p << ": ";
    //     for (auto j = v[*p].begin(); j != v[*p].end(); ++j)
    //         cout << *j << "->";
    //     cout << endl;
	// }
    printf("%d\n", ans);
    return 0;
}