#include <iostream>
using namespace std;

int main()
{
    for ( int i=2; i<=1000; i++ ) {
        int sum = 0;
        for ( int j=1; j<=i/2; j++ ) {
            if ( !(i%j) ) sum += j;
        }
        if ( sum==i ) {
            printf("%d,its factors are 1", i);
            for ( int j=2; j<=i/2; j++ ) {
                if ( !(i%j) ) printf(",%d", j);
            }
            printf("\n");
        }
            
    }
    return 0;
}