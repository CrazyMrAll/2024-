#include <iostream>
using namespace std;

int main()
{
    int x, y, z, d;
    long long sum = 1;
    scanf("%d %d %d", &x, &y, &z);
    d = x + y + z;
    for ( int i=d; i>(d-x); i-- ) sum *= i;
    d -= x;
    for ( int i=d; i>z; i-- ) sum *= i;
    for ( int i=1; i<=x; i++ ) sum /= i;
    for ( int i=1; i<=y; i++ ) sum /= i;
    printf("%lld\n", sum);
    return 0;
}