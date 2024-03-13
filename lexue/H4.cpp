#include <iostream>
using namespace std;

long long divisor (long long u, long long d) {
    return u%d==0 ? d : divisor(d,u%d);
}

int main()
{
    bool flag = 1;
    int n;
    scanf("%d", &n);
    long long u = 1, d = 1, divisor_num;
    for ( int i=0; i<n; i++ ) {
        int a, b;
        scanf("%d %d", &a, &b);
        if ( a==0 ) {flag = 0;break;}
        divisor_num = divisor(a,d);
        a /= divisor_num;
        d /= divisor_num;
        divisor_num = divisor(b,u);
        b /= divisor_num;
        u /= divisor_num;
        u *= a;
        d *= b;
    }
    divisor_num = divisor(u,d);
    u /= divisor_num;
    d /= divisor_num;
    if ( flag==0 ) printf("0\n");
    else {
        if ( d==1 ) printf("%lld\n", u);
        else printf("%lld/%lld\n", u, d);
    }
    return 0;
}