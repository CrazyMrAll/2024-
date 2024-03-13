#include <iostream>
#include <limits.h>
using namespace std;
const int MAXN = 100002;

int main()
{
    int w[MAXN], h[MAXN], n;
    long long ans[MAXN], t;
    h[0] = h[MAXN-1] = INT_MAX;//设置边界
    scanf("%d",&n);
    for (register int i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &h[i]);
    int j, minh;
    for (register int i = 1; i <= n; i++) {
        
        j = i;
        while (h[j] > h[j+1])
            j++;
        minh = min(h[j-1], h[j+1]);
        ans[j] = t + w[j];
        t = t + w[j]*(minh-h[j]);
        h[j] = minh;
    }
    for (register int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
// 斟酌了一下觉得循环链表更好