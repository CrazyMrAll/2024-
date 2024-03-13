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
    int tmp, max, left, right, tmpleft, tmpright;
    left = tmpleft = tmp = max = 0;
    right = n - 1;
    for (int i = 0; i < n; i++) {
        tmpright = i;
        tmp += q[i];
        if (tmp > max || (tmp == 0 && max==0)) {
            max = tmp;
            left = tmpleft;
            right = tmpright;
        }
        if (tmp < 0) {
            tmpleft = i + 1;
            tmp = 0;
        }         
    }
    cout << max << " " << q[left] << " " << q[right];
    return 0;
}