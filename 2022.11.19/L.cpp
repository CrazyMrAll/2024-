#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    double t, num = 0;
    for (register int i = 0; i < n; i++) {
        cin >> t;
        num += t*t*t;
    }
    double x = 1;
    x /= 3;
    double ans = double(pow(num, x));
    printf("%lf\n", ans);
    return 0;
}