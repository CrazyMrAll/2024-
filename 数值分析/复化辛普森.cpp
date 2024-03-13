#include <iostream>
#include <cmath>
using namespace std;

double cal(long double x) {
    return 1.0/(1.0 + x);
}

int main()
{
    int M;
    double e;
    cout << "计算f(x) = 1 / (1 + x)在0-1的积分" << endl;
    cout << "请输入允许误差e:(机器精度为1e-6)" << endl;
    cin >> e;
    M = 2 * (int(pow(24/(2880.0*e), 0.25)) + 1);
    printf("M = %d, 即对区间进行%d等分\n", M, M);
    double ans = 0, h = 1.0 / M, t;
    ans += cal(0) + cal(1);
    bool flag = 1;
    for (double i = h; fabs(1-i) > 1e-6; i+=h) {
        t = cal(i);
        printf("f(%lf) = %lf\n", i, t);
        if (flag) ans += 4 * t;
        else ans += 2 * t;
        flag ^= 1;
    }
    ans *= h/3.0;
    printf("求得积分值为%lf\n", ans);
    return 0;
}