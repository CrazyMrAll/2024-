#include <iostream>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int l[n+1][k];
    int h[n+1][k];
    bool win[n+1];
    int cnt = 0;
    win[0] = 1;
    for (register int i = 1; i <= n; i++)
        win[i] = 0;
    for (register int j = 0; j < k; j++)
        l[0][j] = h[0][j] = 0;
    for (register int i = 1; i <= n; i++) {
        for (register int j = 0; j < k; j++) 
            scanf("%d", &l[i][j]);
        for (register int j = 0; j < k; j++)
            scanf("%d", &h[i][j]);
        bool flag = 1;
        for (register int j = 0; j < k; j++)
            if (l[i][j] != 0) {
                flag = 0;
                break;
            }
        if (flag) win[i] = 1;
    }
    for (register int i = 1; i <= n; i++) {
        bool flag = 0;
        for (register int j = 0; j <= n; j++) {
            if (win[j]) {
                bool tflag = 1;
                for (register int q = 0; q < k; q++) {
                    // printf("\n%d %d\n", l[i][q], h[j][q]);
                    if (l[i][q] > h[j][q]) {
                        tflag = 0;
                        break;
                    }
                }
                if (tflag) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) {
            cnt++;
            printf("now = %d\n", i);
            win[i] = 1;
        }
    }
    for (register int i = 1; i <= n; i++) {
        bool flag = 0;
        if (!win[i]) {
            for (register int j = 0; j <= n; j++) {
                if (win[j]) {
                    bool tflag = 1;
                    for (register int q = 0; q < k; q++) {
                        // printf("\n%d %d\n", l[i][q], h[j][q]);
                        if (l[i][q] > h[j][q]) {
                            tflag = 0;
                            break;
                        }
                    }
                    if (tflag) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag) {
                cnt++;
                printf("now = %d\n", i);
                win[i] = 1;
            }
            }
    }
    printf("%d\n", cnt);
    return 0;
}