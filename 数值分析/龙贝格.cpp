#include <iostream>
#include <cmath>
using namespace std;

double cal(double x) {
    return 1.0/(1.0 + x);
}

double calT(double T, int t) {
    double tmp = 0, h = 1.0/t;
    for (double i = h; fabs(1-i) > 1e-6 && i < 1; i+=2*h) {
        tmp += cal(i);
    }
    return 0.5*T + h*tmp;
}

int main()
{
    double T1, T2, S1, S2, C1, C2, R;
    int t, s, c, r;
    t = s = c = r = 1;
    double e, ans;
    cout << "计算f(x) = 1 / (1 + x)在0-1的积分" << endl;
    cout << "请输入允许误差e:(机器精度为1e-6)" << endl;
    cin >> e;
    while (1) {
        if (t == 1) T2 = 0.5 * (cal(0) + cal(1));
        else {
            T1 = T2;
            T2 = calT(T1, t);
        }
        printf("T%d = %lf\n", t, T2);
        t *= 2;
        if (t >= 4) {
            S1 = S2;
            S2 = (4*T2 - T1) / 3.0;
            printf("S%d = %lf\n", s, S2);
            s *= 2;
            if (fabs(S2-T2) <= e) {
                ans = S2;
                break;
            }
        }
        if (s >= 4) {
            C1 = C2;
            C2 = (16*S2 - S1) / 15.0;
            printf("C%d = %lf\n", c, C2);
            c *= 2;
            if (fabs(C2-S2) <= e) {
                ans = C2;
                break;
            }
        }
        if (c >= 4) {
            R = (64*C2 - C1) / 63.0;
            printf("R%d = %lf\n", r, R);
            r *= 2;
            if (fabs(R-C2) <= e) {
                ans = R;
                break;
            }
        }
    }
    printf("求得积分值为%lf\n", ans);
    return 0;
}