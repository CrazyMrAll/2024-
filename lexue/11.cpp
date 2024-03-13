#include <iostream>
using namespace std;

int main()
{
    int x, n, m;
    long long rate = 1, mul = 1;
    scanf("%d %d %d", &x, &n, &m);
    for ( int i=0; i<=m ; i++ ) {
        rate *= 10;
    }
    for ( int i=0; i<n; i++ ) {
        mul *= x;
        if ( mul>=rate ) mul %= (rate/10);
    }
    printf("%lld\n", mul%(rate/10));
    return 0;
}