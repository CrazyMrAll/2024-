#include <iostream>
#include <queue>
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
    queue<int> q;
    queue<int> q2;
    q.push(bottom);
    int l, r, now, f;
    for (register int i = 2; i <= n; i++) {
        scanf("%d", &now);
        cout << i << ": ";
        while(!q.empty()) {
            f = q.front();
            q.pop();
            l = min(arrow, f);
            r = max(arrow, f);
            if (now <= r && now >= l) {
                dp[i][r] = (dp[i][r] + dp[i-1][f]) % wtf;
                cout << r << " " << l << " ";
                q2.push(r);
                dp[i][l] = (dp[i][l] + dp[i-1][f]) % wtf;
                q2.push(l);
            } else if (now > r) {
                dp[i][l] = (dp[i][l] + dp[i-1][f]) % wtf;
                cout << l << " ";
                q2.push(l);
            } else {
                dp[i][r] = (dp[i][r] + dp[i-1][f]) % wtf;
                cout << r << " ";
                q2.push(r);
            }
        }
        while(!q2.empty()) {
            q.push(q2.front());
            q2.pop();
        }
        cout << endl;
        arrow = now;
    }
    long long ans = 0;
    for (register int i = 0; i <= MAXN; i++)
        if (dp[n][i])
            cout << i << " " << dp[n][i] << endl;
    for (register int i = 0; i <= MAXN; i++)
        ans = (ans + dp[n][i]) % wtf;
    printf("%lld\n", ans);
    return 0;
}