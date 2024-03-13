#include <iostream>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int num[n];
    for (register int i = 0; i < n; i++) 
        scanf("%d", &num[i]);
    bool flag = 1;
    int cnt = 0;
    while (flag) {
        flag = 0;
        for (register int i = 0; i < n-k+1; i++) {
            for (register int j = i+1; j < i+k; j++) {
                int tmp = num[j];
                int q;
                for (q = j; q > i && num[q-1] > tmp; q--) {
                    num[q] = num[q-1];
                    flag = 1;
                }
                num[q] = tmp;
            }
        }
        if (flag) cnt++;
        // for (register int i = 0; i < n; i++) {
        //     printf("%d ", num[i]);
        // } printf("\n");
        // for (register int i = 0; i < n-1; i++) {
        //     if (num[i] > num[i+1]) {
        //         flag = 1;
        //         break;
        //     }
        // }
    }
    printf("%d\n", cnt);
    return 0;
}