#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct point {
    double x, y;
};
point p[MAXN], tmp[MAXN];

bool cmp_x(point p1, point p2) {
    return p1.x < p2.x;
}

bool cmp_y(point p1, point p2) {
    return p1.y < p2.y;
}

double cal(point p1, point p2) {
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return sqrt(x*x + y*y);
}

double Findmin(int l, int r) {
    if (l+1 == r) return cal(p[l], p[r]);
    else if (l+2 == r) {
        double d1 = cal(p[l], p[l+1]);
        double d2 = cal(p[l], p[r]);
        double d3 = cal(p[l+1], p[r]);
        return min(d1, min(d2, d3));
    }
    int mi = (l+r) / 2;
    double d1 = Findmin(l, mi);
    double d2 = Findmin(mi+1, r);
    double d = min(d1, d2);
    int cnt = 0;
    for (register int i = l; i <= r; i++ )
        if (fabs(p[mi].x - p[i].x) <= d)
            tmp[cnt++] = p[i];
    sort(tmp, tmp+cnt, cmp_y);
    for (register int i = 0; i < cnt; i++)
        for (register int j = i+1; j < cnt; j++) {
            if (tmp[j].y - tmp[i].y >= d) break;
            d = min(d, cal(tmp[j], tmp[i]));
        }
    return d;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        for (register int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        sort(p, p+n, cmp_x);
        printf("%.2lf\n", Findmin(0, n-1)/2);
    }
    return 0;
}