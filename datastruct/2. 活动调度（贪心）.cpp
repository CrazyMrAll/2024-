#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int s[n], f[n];
    for (register int i = 0; i < n; i++)
        scanf("%d%d", &s[i], &f[i]);
    sort(s, s+n);
    sort(f, f+n);
    int i, j, cnt, ans;
    ans = cnt = i = j = 0;
    while (i < n && j < n) {
        if (s[i] < f[j]) {
            cnt++;
            i++;
            ans = max(ans, cnt);
        } else if (s[i] > f[j]) {
            cnt--;
            j++;
        } else {
            i++;
            j++;
        }
    }
    printf("%d\n", ans);
    return 0;
}