#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1005;
char a[MAXN], b[MAXN], t[MAXN], ans[MAXN];

int main()
{
    scanf("%s %s", a, b);
    int pa = strlen(a), pb = strlen(b);
    int lena = pa, lenb = pb; 
    bool flaga = 0, flagb = 0;
    for (int i = 0; a[i] != '\0'; i++)
        if (a[i] == '.') {
            pa = i;
            flaga = 1;
            break;
        }
    for (int i = 0; b[i] != '\0'; i++)
        if (b[i] == '.') {
            pb = i;
            flagb = 1;
            break;
        }
    int fa = 0, fb = 0;
    if (flaga) fa = lena - pa - 1;
    if (flagb) fb = lenb - pb - 1;
    int max = fa>fb ? fa : fb;
    int choose = 0;
    // cout << fa << " " << fb << endl;
    if (fa > fb) {
        choose = 1;
        strcpy(t, b);
        b[pb] = '.';
        int i = 1;
        for (; fb + i <= fa; i++)
            b[pb+fb+i] = '0';
        b[pb+fb+i] = '\0';
        lenb = pb+fb+i;
    } else {
        choose = 2;
        strcpy(t, a);
        a[pa] = '.';
        int i = 1;
        for (; fa + i <= fb; i++)
            a[pa+fa+i] = '0';
        a[pa+fa+i] = '\0';
        lena = pa+fa+i;
    }
    int next = 0, now = 0;
    // cout << lena << " " << lenb << " " << max << endl;
    for (int i = 1; i <= max; i++) {
        now = a[lena-i]-'0' + b[lenb-i]-'0' + next*10;
        next = now / 10;
        now %= 10;
        ans[i-1] = now + '0';
        // cout << ans[i-1];
    }
    if (max) ans[max] = '.';
    else max--;
    // cout << ans[max];
    int i = 1;
    for ( ; pa>=i || pb>=i; i++) {
        now = (pa>=i ? a[pa-i]-'0' : 0) +
              (pb>=i ? b[pb-i]-'0' : 0) + next;
        next = now / 10;
        now %= 10;
        ans[max+i] = now + '0';  
        // cout << ans[max+i];  
    }
    if (next) {
        ans[max+i] = 1 + '0';
        // cout << ans[max+i];
        i++;
    }
    int l = (pa>pb ? pa : pb) + max + 3 + (fa && fb);
    for (int i = 0; i < l-max-pa-1; i++)
        printf(" ");
    if (choose == 2) {
        printf("%s", t);
        lena = strlen(t);
    }
    else printf("%s", a);
    for (int i = l-max-pa+lena-1; i < l; i++)
        printf(" ");
    printf("\n+");
    for (int i = 1; i < l-max-pb-1; i++)
        printf(" ");
    if (choose == 1) {
        printf("%s", t);
        lenb = strlen(t);
    }
    else printf("%s", b);
    for (int i = l-max-pb+lenb-1; i < l; i++)
        printf(" ");
    printf("\n");
    for (int i = 0; i < l; i++)
        printf("-");
    printf("\n");
    for (int k = 0; k < l-max-i; k++)
        printf(" ");
    // cout << endl;
    bool tmpflag = 1;
    for (int j = l; j >= 0; j--)
        if (ans[j] == '\0') continue;
        else {
            if (tmpflag) {
                if (ans[j] == '0' && ans[j-1] != '.') {
                    printf(" ");
                } else {
                    printf("%c", ans[j]);
                    tmpflag = 0;
                }
            } else printf("%c", ans[j]);
        }
        
    printf("\n");
    // cout << a << endl << b << endl;    
    return 0;
}