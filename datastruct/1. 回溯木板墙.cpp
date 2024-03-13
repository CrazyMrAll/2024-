#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 100005;

struct block {
    int i;
    long long h;
    int p;
};
block item[MAXN];

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        for (register int i = 0; i < n; i++) {
            scanf("%lld", &item[i].h);
            item[i].p = 0;
            item[i].i = i;
        }
        stack<block> s;
        long long ans = 0;
        for (register int i = 0; i < n; i++) {
            while (!s.empty() && item[i].h < s.top().h) {
                block tmp = s.top();
                s.pop();
                item[i].p += tmp.p + 1;//因为写成等于没过
                ans = max(ans, tmp.h * (long long)(i - tmp.i + tmp.p));
            }
            s.push(item[i]);
        }    
        while (!s.empty()) {
            block tmp = s.top();
            s.pop();
            ans = max(ans, tmp.h * (long long)(n - tmp.i + tmp.p));
        }
        printf("%lld\n", ans);
    }
    return 0;
}