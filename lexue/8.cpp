#include <iostream>
using namespace std;

int main()
{
    int n, m, x, i, l=0;
    scanf("%d %d %d", &n, &m, &x);
    for ( i=0; l<x; i++ ) {
        l += (n-i);
        if ( l>=x || l<0 )
            break;
        l -= m;
    }
    if ( l<0 )
        printf("青蛙不能爬出井。\n");
    else
        printf("青蛙能爬出井，且第 %d 天爬出井。\n", i+1);
    return 0;
}