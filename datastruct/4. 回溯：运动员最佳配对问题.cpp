#include <iostream>
using namespace std;
const int MAXN = 15;
int P[MAXN][MAXN], Q[MAXN][MAXN], limit[MAXN], n, tmp, ans;
bool vis[MAXN];

void solve(int order) {
    // printf("order = %d\n", order);
    if (order >= n) {
        if (ans < tmp) ans = tmp;
        return;
    }
    if (tmp + limit[n] - limit[order] < ans) return;
    for (register int i = 0; i < n; i++) {
        if (!vis[i]) {
            tmp += P[order][i] * Q[i][order];
            vis[i] = 1;
            solve(order+1);
            tmp -= P[order][i] * Q[i][order];
            vis[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (register int i = 0; i < n; i++)
        for (register int j = 0; j < n; j++)
            scanf("%d", &P[i][j]);
    for (register int i = 0; i < n; i++)
        for (register int j = 0; j < n; j++)
            scanf("%d", &Q[i][j]);   
    for (register int i = 0; i < n; i++) {
        for (register int j = 0; j < n; j++) 
            limit[i+1] = max(limit[i+1], P[i][j] * Q[j][i]);
        limit[i+1] += limit[i];
    }
    solve(0);   
    printf("%d\n", ans);  
    return 0;
}