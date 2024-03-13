#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int MAXN = 100;
int vis[MAXN][MAXN];
bool map[MAXN][MAXN];

struct node {
    int x, y;
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (register int i = 0; i < n; i++)
        for (register int j = 0 ; j < m; j++)
            scanf("%d", &map[i][j]);
    queue<node> q;
    node tnode;
    tnode.x = tnode.y = 0;
    vis[0][0] = -1;
    if (!map[0][0]) q.push(tnode);
    int x, y;
    bool win = 0;
    while (!q.empty()) {
        tnode = q.front();
        q.pop();
        x = tnode.x, y = tnode.y;
        // printf("y = %d, x = %d\n", y, x);
        if (y == n-1 && x == m-1 ) {
            win = 1;
            break;
        } else {
            if (y < n-1 && !map[y+1][x] && !vis[y+1][x]) {
                vis[y+1][x] = 1;
                tnode.x = x;
                tnode.y = y + 1;
                q.push(tnode);
            }
            if (x < m-1 && !map[y][x+1] && !vis[y][x+1]) {
                vis[y][x+1] = 2;
                tnode.x = x + 1;
                tnode.y = y;
                q.push(tnode);
            }
            if (y > 0 && !map[y-1][x] && !vis[y-1][x]) {
                vis[y-1][x] = 3;
                tnode.x = x;
                tnode.y = y - 1;
                q.push(tnode);
            }if (x > 0 && !map[y][x-1] && !vis[y][x-1]) {
                vis[y][x-1] = 4;
                tnode.x = x - 1;
                tnode.y = y;
                q.push(tnode);
            }
        }
    }
    if (win) {
        stack<node> s;
        s.push(tnode);
        while (vis[y][x] != -1) {
            // printf("y = %d, x = %d, dir = %d\n", y, x, vis[y][x]);
            switch (vis[y][x]) {
            case 1:
                y--;
                tnode.y--;
                s.push(tnode);
                break;
            case 2:
                x--;
                tnode.x--;
                s.push(tnode);
                break;
            case 3:
                y++;
                tnode.y++;
                s.push(tnode);
                break;
            case 4:
                x++;
                tnode.x++;
                s.push(tnode);
                break;
            }
        }
        while (!s.empty()) {
            printf("<%d,%d> ", s.top().y+1, s.top().x+1);
            s.pop();
        }
        printf("\n");
    } else printf("There is no solution!\n");
    return 0;
}