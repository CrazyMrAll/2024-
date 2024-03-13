#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (register int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    sort(num, num+n);
    long long ans = 0;
    for (register int i = n-1; i > 0; i--)
        ans += num[i];
    printf("%lld\n", ans);
    return 0;   
}