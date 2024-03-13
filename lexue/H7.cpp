#include <iostream>
using namespace std;

int main()
{
    int n, cnt=0;
    scanf("%d", &n);
    while ( n>0 ) {
        n /= 5;
        cnt += n;
    }
    printf("%d\n", cnt);
    return 0;
}