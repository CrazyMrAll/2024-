#include <iostream>
using namespace std;


int main()
{
    int n, range = 1, cnt = 0;
    bool flag;
    scanf("%d", &n);
    if ( n==0 || n>=8 ) printf("0\n");
    else {
        {
            int t = n;
            while ( t>0 ) { t--; range*=10;}
        }
        for ( int i=range/10; i<range; i++ ) {
            flag = 1;
            {
                int t = i, m = n;
                while ( m>0 ) {
                    int rate = m * m;
                    if ( !(t%rate) ) {m--;t/=10;}
                    else { flag = 0;break;}
                }
            }
            if ( flag ) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}