#include <iostream>
using namespace std;
const int MAXN = 12;
bool table[MAXN][MAXN];

int main()
{
    char ch;
    int n = 0;
    while (scanf("%c", &ch) && ch != '\n') {
        if (ch != ' ') table[0][n++] = ch - '0';
    }
    for (register int i = 1; i < n; i++)
        for (register int j = 0; j < n; j++)
            scanf("%d", &table[i][j]);
    for (register int g = 0; g < n; g++)
        for (register int i = 0; i < n; i++)
            for (register int j = 0; j < n; j++)
                for (register int k = 0; k < n; k++)
                    if (table[i][j] || (table[i][k] && table[k][j])) {
                        // if (!table[i][j]) 
                        //     printf("i = %d, j = %d, k = %d\n", i, j, k);
                        table[i][j] = 1;
                        break;
                    }
    // printf("\n");
    for (register int i = 0; i < n; i++) 
        for (register int j = 0; j < n; j++) {
            printf("%d", table[i][j]);
            if (j == n-1) printf("\n");
            else printf(" ");
        }  
    return 0;
}