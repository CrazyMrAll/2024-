#include <iostream>
using namespace std;

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    if ( n<0 ) {n -= INT32_MIN;cnt++;}
    while ( n>0 ) {
        if ( n%2 ) cnt++;
        n /= 2;
    }
    printf("%d\n", cnt);
    return 0;
}