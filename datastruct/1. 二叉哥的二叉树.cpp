#include <iostream>
using namespace std;

int main()
{
    int T, n, m, ans;
    scanf("%d", &T);
    for (register int g = 0; g < T; g++) {
        scanf("%d%d", &n, &m);
        // 贪心算法
        n -= m;
        ans = 0;
        if (n > 0) {
            bool flag = 1;
            int depth = 2, t = 2;
            ans++;
            while (1) {
                // printf("%d\n", n);
                if (flag) {
                    flag = 0;
                    n--;
                    if (n > 0) ans++;
                    else break;
                } else {
                    flag = 1;
                    n -= t;
                    if (t == 2) {
                        depth++;
                        t = depth;
                        if (depth > m+1) break;
                    } else t--;
                    if (n > 0) ans++;
                    else break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}