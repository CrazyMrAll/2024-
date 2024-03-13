#include <iostream>
using namespace std;
const int wtf = 2147483647;
const int MAXN = 2001;
long long dp[MAXN][MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    int bottom, arrow;
    scanf("%d%d", &bottom, &arrow);
    dp[1][bottom] = 1;
    int l, r, now;
    for (register int i = 2; i <= n; i++) {
        scanf("%d", &now);
        for (register int j = 1; j <= MAXN; j++) {
            if (dp[i-1][j]) {
                l = min(arrow, j);
                r = max(arrow, j);
                if (now <= r && now >= l) {
                    dp[i][r] = (dp[i][r] + dp[i-1][j]) % wtf;
                    dp[i][l] = (dp[i][l] + dp[i-1][j]) % wtf;
                } else if (now > r) {
                    dp[i][l] = (dp[i][l] + dp[i-1][j]) % wtf;
                } else {
                    dp[i][r] = (dp[i][r] + dp[i-1][j]) % wtf;
                }
            }
        }
        arrow = now;
    }
    long long ans = 0;
    for (register int i = 0; i <= MAXN; i++)
        ans = (ans + dp[n][i]) % wtf;
    printf("%lld\n", ans);
    return 0;
}