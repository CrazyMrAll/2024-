#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 200005;
vector<int> v[MAXN];
bool vis[MAXN];
long long ans, d, ansup[MAXN], o, e;
int t[MAXN], dis[MAXN];

void inline dfs(int root) {
    dis[root] = d;
    ansup[1] += (d + 1) / 2;
    t[root] = 1;
    vis[root] = 1;
    for (auto i = v[root].begin(); i != v[root].end(); i++) {
        if (!vis[*i]) {
            if (d&1 == 1) e++;
            else o++;
            d++;
            dfs(*i);
            d--;
            t[root] += t[*i];
        }
    }
    vis[root] = 0;
}

void inline dp(int root) {
    vis[root] = 1;
    for (auto j = v[root].begin(); j != v[root].end(); j++) {
        if (!vis[*j]) {
            ansup[*j] = ansup[root] + (dis[root]&1 == 1 ? o-1 : e) - t[*j] + 1;
            ans += ansup[*j];
            dp(*j);
        }
    }
    vis[root] = 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a, b;
    for (register int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // {
    //     dfs(1);
    //     for (register int i = 1; i <= n; i++)
    //         printf("dis[%d] = %d, ansup[%d] = %d, e = %d, o = %d\n", i, dis[i], i, ansup[i], e, o);
    // }
    dfs(1);
    ans += ansup[1];
    dp(1);
    printf("%lld\n", ans/2);
    return 0;
}