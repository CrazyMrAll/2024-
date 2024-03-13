#include <iostream>
using namespace std;
const int MAXN = 105;
int c, n, w[MAXN], Max, tmp, leftover;
bool now[MAXN], ans[MAXN], flag;

void solve(int index) {
    // printf("index = %d, tmp = %d\n", index, tmp);
    if (index >= n) {
        if (Max < tmp) {
            Max = tmp;
            for (register int i = 0; i < n; i++)
                ans[i] = now[i];
            if (Max == c) flag = 1;//这一行减少了很多时间
        }
        return;
    }
    if (flag) return;
    leftover -= w[index];
    if (tmp+w[index] <= c) {
        now[index] = 1;
        tmp += w[index];
        solve(index+1);
        tmp -= w[index];
    }
    if (tmp+leftover > Max) {
        now[index] = 0;
        solve(index+1);
    }
    leftover += w[index];
}

int main()
{
    scanf("%d%d", &c, &n);
    for (register int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        leftover += w[i];
    }    
    solve(0);
    printf("%d\n", Max);
    for (register int i = 0; i < n; i++)
        if (ans[i]) printf("%d ", i+1);
    printf("\n");
    return 0;
}