#include <iostream>
using namespace std;
const int MAXN = 100005;


int main()
{
    int n, m, x, y;
    int itemnum[MAXN];
    scanf("%d %d", &n, &m);
    int link[MAXN], now[MAXN];
    for (register int i = 1; i <= n; i++) {
        now[i] = i;
        link[i] = -1;
        itemnum[i] = 1;
    }   
    int tp;
    for (register int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        itemnum[y] += itemnum[x];
        itemnum[x] = 0;
        while (now[x] != -1) {
            tp = link[now[x]];
            link[now[x]] = now[y];
            now[y] = now[x];
            now[x] = tp;
        }
    }
    // for (int i = 1; i <= n; i++)
    //     printf("%d %d\n", now[i], link[i]);

    for (register int i = 1; i <= n; i++) {
        printf("%d", itemnum[i]);
        if (itemnum[i]) {
            while (now[i] != -1) {
                printf(" %d", now[i]);
                now[i] = link[now[i]];
            }
        }
        printf("\n");
    }
    return 0;
}