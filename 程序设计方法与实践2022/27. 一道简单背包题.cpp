#include <iostream>
using namespace std;
const int wtf = 10000000;
const int MAXN = 2001;
long long dp[MAXN][MAXN];

int main()
{
    int n, v;
    scanf("%d%d", &n, &v);
    dp[0][0] = 1;
    int t;
    for (register int i = 1; i <= n; i++) {
        scanf("%d", &t);
        for (register int j = 0; j < v; j++) {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= wtf;
            dp[i][j] += dp[i-1][(j-t%v+v)%v];
            dp[i][j] %= wtf;
        }
    }
    printf("%lld\n", dp[n][0]-1);
    return 0;
}