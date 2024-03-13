#include <iostream>
using namespace std;
const int MAXN = 101;
bool map[MAXN][MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for (register int i = 0; i < n; i++)
        for (register int j = 0; j < n; j++)
            scanf("%d", &map[i][j]); 
    for (register int k = 0; k < n; k++)
        for (register int i = 0; i < n; i++)
            for (register int j = 0; j < n; j++)
                if (map[i][k] && map[k][j]) map[i][j] = 1;
    for (register int i = 0; i < n; i++)
        for (register int j = 0; j < n; j++)
            if (!map[i][j] && !map[j][i]) {
                printf("B\n");
                return 0;
            } else if (map[i][j] + map[j][i] == 1) {
                printf("C\n");
                return 0;
            }
    printf("A\n");
    return 0;
}