#include <iostream>
using namespace std;

int main()
{
    string a, b, c;
    c = a = b = "";
    int n, m;
    scanf("%d%d", &n, &m);
    int lena, lenb;
    lena = lenb = 0;
    while (n) {
        a += n%2 + '0';
        n /= 2;
        lena++;
    }
    while (m) {
        b += m%2 + '0';
        m /= 2;
        lenb++;
    }
    while (lenb < lena) {
        b += '0';
        lenb++;
    }
    int lenc = 1;
    bool flag = 1;
    bool next;
    if (a[0] == '0' && b[0] == '1') {
        next = 1;
        c += '0';
    } else {
        next = 0;
        if (a[0] == '0' && b[0] == '0') c += '0';
        else c += '1';
    }
    // cout << a << endl;
    // cout << b << endl;
    for (register int i = 1; i <lenb; i++) {
        if (a[i] == '0' && b[i] == '0') {
            if (next) flag = 1;
            else flag = 0;
        }
        else if (a[i] == '0' && b[i] == '1') {
            next = 1;
            flag = 0;
        } else if (a[i] == '1' && b[i] == '0') {
            if (next) next = flag = 0;
            else flag = 1;
        } else if (a[i] == '1' && b[i] == '1') {
            flag = 0;
            next = 1;
        }
        if (flag) c += '1';
        else c += '0';
        lenc++;
    }   
    // cout << c << endl;
    long long t = 1, ans = 0;
    for (register int i = 0; i < lenc; i++) {
        ans += (long long)(t*(c[i]-'0'));
        t *= 2;
    }
    printf("%lld\n", ans);
    return 0;
}