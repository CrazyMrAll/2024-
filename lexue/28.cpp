#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x)
{
	if ( !(x%2) ) return 0;
    else {
        bool flag = 1;
        for ( int i=3; i<=(int)sqrt(x); i+=2 ) {
            if ( !(x%i) ) {flag=0;break;}
        }
        if ( flag ) return 1;
        else return 0;
    }
} 

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for ( int i=a; i<=b; i++ ) {
        if ( isPrime(i) ) {
            int cnt = 0, rate1 = 1, rate2 = 10;
            int t = i;
            bool flag = 1;
            while ( t>9 ) {
                t /= 10;
                rate1 *= 10;
                cnt++;
            }
            for ( int j=0; j<(cnt+1)/2; j++ ) {
                int l = i / rate1;
                int r = i % rate2;
                if ( l%10!=r/(rate2/10) ) { flag=0; break;}
                rate1 /= 10;
                rate2 *= 10;
            }
            if ( flag ) printf("%d\n", i);
        }
    }
    return 0;
}