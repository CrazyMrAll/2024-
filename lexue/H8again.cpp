#include <iostream>
using namespace std;
#define wtf 10000007

int main()
{
   int n;
   scanf("%d", &n);
   int a[n];
   for ( int i=0; i<n; i++ )
      a[i] = 1;
   for ( int i=1; i<n; i++ ) {
        for ( int j=0; j<n; j++ ) {
            if ( j==0 ) a[j] += a[j+1];
            else if ( j==n-1 ) a[j] += a[j-1];
            else a[j] += a[j+1] + a[j-1];
            a[j] %= wtf;
        }
   }
   printf("%d\n", a[n-1]);
   return 0;
}