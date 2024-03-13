#include <iostream>
using namespace std;
const int MAXN = 3000;
int q[MAXN + 1];

int main()
{
    int n, v;
    scanf("%d%d", &n, &v);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        q[a] += b;
    }
    int p = 1, left = v;
    long long int cnt = 0;
    for (int i = 1; i <= MAXN+1 && p <= MAXN; i++) {
        if (p+1 < i) p++;
        if (q[p] >= left) {
            // cout << "pick" << left << "at" << i;
            cnt += left;
            q[p] -= left;
        } else {
            // cout << "pick" << q[p] << "at" << i;
            cnt += q[p]; 
            p++;
            if (p <= i) {
                left -= q[p-1];
                i--;
                continue;
            }
        }
        left = v;
    }
    printf("%lld\n", cnt);
    // for (int i = 1; i <= n; i++)
    //     cout << q[i] << " ";
    return 0;
}