#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 100005;
char a[MAXN], b[MAXN];
bool ans[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%s %s", a, b);
        int lena = strlen(a), lenb = strlen(b);
        lena--; lenb--;
        {
            int next = 0, i = 0;
            for ( ; lena >= i || lenb >= i; i++) {
                int now = (lena>=i ? (a[lena-i]-'0') : 0) 
                        + (lenb>=i ? (b[lenb-i]-'0') : 0) + next;
                if (now > 1) {
                    next = 1;
                    now -= 2;
                } else next = 0;
                // cout << now << endl;
                ans[i] = now;
            }
            lena++; lenb++;
            if (next) ans[i++] = next;
            int maxlenth = i + 2;
            // cout << maxlenth << endl;
            for (int i = 0; i < maxlenth - lena; i++)
                printf(" ");
            printf("%s\n+", a);
            for (int i = 1; i < maxlenth - lenb; i++)
                printf(" ");
            printf("%s\n", b);
            for (int i = 0; i < maxlenth; i++)
                printf("-");
            printf("\n  ");
            for (int j = 1; i >= j; j++)
                printf("%d", ans[i-j]);
            printf("\n");
        } 
    }
    return 0;
}