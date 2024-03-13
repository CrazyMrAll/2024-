#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAXN = 500001;
long long dp[MAXN];

int main()
{
    long long ans = 0;
    int maxi[3] = {0};
    int n, t;
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if (t <= 0) dp[i] = t;
        else if (dp[i-1] > 0) {
            dp[i] = dp[i-1] + (long long)t;
            dp[i-1] = 0;
        } else dp[i] = t;
    }
    for (register int i = 0; i < 3; i++) {
        int max = INT_MIN;
        for (register int j = 1; j <= n; j++) {
            if (max < dp[j]) {
                bool flag = 1;
                if (i) {
                    for (register int k = 0; k < i; k++) 
                        if (j == maxi[k]) {
                            flag = 0;
                            break;
                        }
                }
                if (flag) {
                    maxi[i] = j;  
                    max = dp[j];
                }
            } 
        }
    }
    for (register int j = 0; j < 3; j++) 
        ans = ans + (long long) dp[maxi[j]];
    printf("%lld\n", ans);
    return 0;
}