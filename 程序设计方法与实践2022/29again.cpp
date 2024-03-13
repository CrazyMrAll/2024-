#include <iostream>
#include <vector>
#include <list>
using namespace std;
const int MAXN = 200005;
vector<list<int>> v(MAXN);
bool vis[MAXN];
int a[MAXN], b[MAXN];
long long ans, t, o;
bool d;

void inline dfs(int root) {
    // printf("visit %d d = %d\n", root, d);
    vis[root] = 1;
    t++;
    if (d) o++;
    for (auto i = v[root].begin(); i != v[root].end(); i++) {
        if (!vis[*i]) {
            d ^= 1;
            dfs(*i);
            d ^= 1;
        }
    }
    vis[root] = 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (register int i = 0; i < n-1; i++) {
        scanf("%d %d", &a[i], &b[i]);
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    for (register int i = 0; i < n-1; i++) {
        vis[b[i]] = 1;
        o = d = 0;
        dfs(a[i]);
        t = d = 0;
        vis[a[i]] = 1;
        dfs(b[i]);
        // printf("%d round: t = %lld o = %lld\n", i+1, t, o);
        ans += (t * (n-t) + o) / 2;
        vis[b[i]] = vis[a[i]] = 0;
    }
    printf("%lld\n", ans);
    return 0;
}