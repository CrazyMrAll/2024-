#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 501;
int dp[MAXN][MAXN];
int w[MAXN], v[MAXN], g[MAXN];

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int n, q;
    scanf("%d%d", &n, &q);
    for (register int i = 1; i <= n; i++) {
        scanf("%d%d%d", &w[i], &v[i], &g[i]);
        for (register int j = MAXN-1; j >= w[i]; j--) {
            for (register int k = MAXN+v[i]; k >= v[i]; k--) {
                if (dp[j-w[i]][k-v[i]] != -1) {
                    dp[j][min(k,500)] = max(dp[j][min(k,500)], dp[j-w[i]][k-v[i]]+g[i]);
                }
            }
        }
    }
    int W, V;
    for (register int i = 0; i < q; i++) {
        scanf("%d%d", &W, &V);
        int max = -2;
        for (register int j = 0; j <= W; j++) {
            for (register int k = V; k < MAXN; k++) {
                if (max < dp[j][k]) max = dp[j][k];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}