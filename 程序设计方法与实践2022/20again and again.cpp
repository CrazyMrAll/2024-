#include <iostream>
using namespace std;
const int MAXN = 100005;
struct Node
{
    int l = 0, r = 0;
} node[MAXN];

struct Line
{
    int up, down;
} line[MAXN];


int main()
{
    int n, m, x, y;
    int itemnum[MAXN];
    scanf("%d %d", &n, &m);
    for (register int i = 1; i <= n; i++) {
        line[i].up = line[i].down = i;
        itemnum[i] = 1;
    }   
    for (register int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        itemnum[y] += itemnum[x];
        itemnum[x] = 0;
        if (line[x].up && line[x].down) {
            if (!line[y].up && !line[y].down) {
                line[y].up = line[x].down;
                line[y].down = line[x].up;
            } else {
                if (!node[line[x].up].r) node[line[x].up].r = line[y].up;
                else node[line[x].up].l = line[y].up;
                if (!node[line[y].up].r) node[line[y].up].r = line[x].up;
                else node[line[y].up].l = line[x].up;
                line[y].up = line[x].down;
            }
            line[x].up = line[x].down = 0;
        }
    }
    // for (int i = 1; i <= n; i++) 
    //     printf("%d %d\n", node[i].l, node[i].r);

    for (register int i = 1; i <= n; i++) {
        printf("%d", itemnum[i]);
        if (itemnum[i]) {
            int t = line[i].up;
            while (1) {
                printf(" %d", line[i].up);
                if (line[i].up == line[i].down) break;
                if (!node[line[i].up].l) {
                    line[i].up = node[line[i].up].r;
                } else if (!node[line[i].up].r) {
                    line[i].up = node[line[i].up].l;
                } else if (node[line[i].up].l == t) {
                    t = line[i].up;
                    line[i].up = node[line[i].up].r;
                } else {
                    t = line[i].up;
                    line[i].up = node[line[i].up].l;
                }
            }
        }
        printf("\n");
    }
    return 0;
}