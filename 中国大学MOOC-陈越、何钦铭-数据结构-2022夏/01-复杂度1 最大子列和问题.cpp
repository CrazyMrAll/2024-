#include <iostream>
using namespace std;
#define MAXN 100000
int q[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    int tmp, max;
    tmp = max = 0;
    for (int i = 0; i < n; i++) {
        tmp += q[i];
        if (tmp < 0)
            tmp = 0;
        if (tmp > max)
            max = tmp;
    }
    cout << max;
    return 0;
}