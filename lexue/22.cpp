#include <iostream>
using namespace std;


bool isRight (int n, int m) {
    if ( n==0 ) return 1;
    else { 
        int rate = n*n;
        if ( !(m%rate) ) 
            if ( isRight(n-1,m/10) ) return 1;
            else return 0;
        else return 0;
    }
}

int main()
{
    int n, range = 1, cnt = 0;
    scanf("%d", &n);
    if ( n==0 ) printf("0\n");
    else {
        {
            int t = n;
            while ( t>0 ) { t--; range*=10;}
        }
        for ( int i=range/10; i<range; i++ ) {
            if ( isRight(n,i) ) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}