#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
int num[MAXN];
int ans[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for (register int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    sort(num, num+n);
    // for (register int i = 0; i < n; i++)
    //     printf("%d ", num[i]);
    int leaves = (n + 1) / 2;
    int height = 0;
    {
        int t = n;
        while (t) {
            t /= 2;
            height++;
        }
    }
    printf("leaves = %d, height = %d\n", leaves, height);
    printf("%d", ans[0]);
    for (register int i = 1; i < n; i++)
        printf(" %d", ans[i]);
    return 0;
}