#include <iostream>
using namespace std;
const int MAXN = 26;
bool map[MAXN][MAXN], vis[MAXN];

int main()
{
    char a, b;
    while (scanf("%c", &a) && a != '\n') {
        if (a != ',') vis[a-'a'] = 1;
    }
    while (1) {
        scanf("<%c,%c>", &a, &b);
        map[a-'a'][b-'a'] = 1;
        if (scanf("%c", &a) && a == '\n') break;
    }
    bool flag = 0;
    for (register int i = 0; i < MAXN; i++) 
        if (vis[i]) {
            bool tflag = 1;
            for (register int j = 0; j < MAXN; j++)
                if (map[j][i]) {
                    tflag = 0;
                    break;
                }
            if (tflag) {
                if (flag) printf(",");
                flag = 1;
                printf("%c", 'a'+i);
            }
        }
    printf("\n");
    flag = 0;
    for (register int i = 0; i < MAXN; i++) 
        if (vis[i]) {
            bool tflag = 1;
            for (register int j = 0; j < MAXN; j++)
                if (map[i][j]) {
                    tflag = 0;
                    break;
                }
            if (tflag) {
                if (flag) printf(",");
                flag = 1;
                printf("%c", 'a'+i);
            }
    }
    printf("\n");
    return 0;
}