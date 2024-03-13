#include <iostream>
using namespace std;
const int MAXN = 100001;
int L[MAXN+1], R[MAXN+1];

int main()
{
    int n;
    scanf("%d\n", &n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        char tmp;
        int l = 0, r = 0;
        while (scanf("%c", &tmp) && tmp != '\n') {
            if (tmp == '(') l++;
            else if (l) l--;
            else r++;
        }
        if (!l && !r) L[0]++;
        else if (l && !r) L[l]++;
        else if (r && !l) R[r]++;
        if (l > max) max = l;
        if (r > max) max = r;
    }
    int cnt = 0;
    cnt += L[0]/2;
    for (int i = 1; i <= max; i++)
        cnt += L[i]<R[i] ? L[i] : R[i];
    printf("%d\n", cnt);
    return 0;
}