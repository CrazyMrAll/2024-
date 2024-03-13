#include <iostream>
using namespace std;

int isright ( int );

int main()
{
    int m, n, cnt=0;
    scanf("%d %d", &m, &n);
    if ( m>n ) { int i=n; n=m; m=i; }
    for ( int i=m; i<=n; i++ ) {
        if ( isright(i) ) { 
            if ( cnt!=0 && cnt%10==0 && i!=n ) printf("\n");
            printf("%d ", i);
            cnt++; 
        }
    }
    if ( cnt==0 ) printf("No output!");
    printf("\n");
    return 0;
}

int isright ( int num ) {
    int sum = 0, mul = 1, i;
    while ( num>0 ) {
        i = num % 10;
        sum += i;
        mul *= i;
        num /= 10;
    }
    if ( sum<mul ) return 1;
    else return 0;
}