#include <iostream>
#include <limits.h>
using namespace std;
const int MAXN = 500005;
int a[MAXN];
long long dp[4][MAXN];

long long max(long long a, long long b) {
    if (a > b) return a;
    else return b;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    dp[1][1] = a[1];
    for (register int j = 2; j <= n; j++) {
        dp[1][j] = max(dp[1][j-1]+a[j], a[j]);
    }
    long long lmax = INT_MIN;
    for (register int i = 2; i < 4; i++) {
        lmax = INT_MIN;
        dp[i][i] = dp[i-1][i-1] + a[i];
        for (register int j = i+1; j <= n; j++) {
            lmax = max(lmax, dp[i-1][j-1]);
            dp[i][j] = max(lmax, dp[i][j-1]) +a[j];
        }
    }
    lmax = INT_MIN;
    for (register int i = 3; i <= n; i++) 
        lmax = max(lmax, dp[3][i]); 
    printf("%lld\n", lmax);
    return 0;
}