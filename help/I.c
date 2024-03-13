#include <stdio.h>
#define LL long long
LL t[1000100];

int main()
{
    LL n, k;
    LL a = 0, num = 0, sum = 0;
    scanf("%lld%lld", &n, &k);
    for (LL i = 1; i <= n; ++i) {
        scanf("%lld", &t[i]);
        if (num * (t[i] - t[i - 1]) >= k) {
            sum += (k + a);
            num = 0, a = 0;
        }
        a += num * (t[i] - t[i - 1]);
        num++;
    }
    if (num != 0) sum += (a + k);
    printf("%lld", sum);
    return 0;
}