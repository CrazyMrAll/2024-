#include <iostream>
using namespace std;
#define MAXN 100

int radix(char a[]) {
    int max = 0;
    for ( int i=0; a[i]!='\0'; i++ ) {
        int t = 0;
        if ( a[i]<='9' ) t = a[i] - '0';
        else t = 10 + a[i] - 'A';
        if ( max<t ) max = t;
    }
    return max+1;
}

int Atoi(char a[], int radix) {
    int sum = 0;
    for ( int i=0; a[i]!='\0'; i++ ) {
        if ( a[i]<='9' ) sum = sum*radix + a[i] - '0';
        else sum = sum*radix + a[i] - 'A' + 10;
    }
    return sum;
}

int main()
{
    char a[MAXN], b[MAXN];
    cin >> a >> b;
    int r1=radix(a), r2=radix(b);
    bool flag = 0;
    while (r1<=36 && r2<=36) {
        int A = Atoi(a,r1);
        int B = Atoi(b,r2);
        if ( A<B ) r1++;
        else if ( A>B ) r2++;
        else {flag=1;break;}
    }
    if ( flag ) printf("%s (base %d) = %s (base %d)\n", a, r1, b, r2);
    else printf("%s is not equal to %s in any base 2..36\n", a, b);
    return 0;
}