#include <iostream>
using namespace std;
#define MAXN 10

void max (int a[]) {
    int max = 1, m = a[0];
    for ( int i=0; i<MAXN-1; i++ ) {
        if ( m<a[i+1] ) {
            max=i+2;
            m = a[i+1];
        }
    }
    printf("%d\n", max);
    a[max-1] = -1;
    for ( int i=0; i<MAXN; i++ ) {
        if ( a[i]==m ) printf("%d\n", i+1);
    }
}

int main()
{
    int a[MAXN];
    for ( int i=0; i<MAXN; i++ ) {
        scanf("%d", &a[i]);
    }
    max(a);
    return 0;
}