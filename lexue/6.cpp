#include <iostream>
using namespace std;
#define p1 20
#define p2 12
#define p3 8

int main()
{
    int n, m;
    while (cin >> n >> m) {
        int flag = 1;
        for ( int i=m/p1, cnt=0; i>=0; i-- ) {
            int j = (m - 8*n - 12*i)/4;
            int k = n - i - j;
            if ( p1*i + p2*j + p3*k == m && j>=0 && k>=0 ) {
                if ( cnt==0 )
                    printf("KFC  McDonald  PissaHut\n");
                printf("%d %d %d\n", i, j, k);
                flag = 0;
                cnt = 1;
            }
        }
        if ( flag )
            printf("No Solution!\n");
    }
    return 0;
}