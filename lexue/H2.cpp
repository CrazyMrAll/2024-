#include <iostream>
using namespace std;

#define Months 12

int main()
{
    int y1, m1, d1, d2, t, flag, i, j;
    char month[Months] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d %d %d %d", &y1, &m1, &d1, &t);
    for ( i=y1; t>0; i++ ) {
        flag = ((i%4==0 && i%100!=0) || i%400==0);
        for ( j=((i==y1) ? m1 : 1); j<=12; j++ ) {
            if ( t<=0 )
                break;
            t -= month[j-1] + ((j==2) ? flag : 0 );
        }
    }
    d2 = d1+t;
    if ( j!=13 || (j==13 && d2<=0) )
        i--;
    if ( d2 <= 0 ) {
        if ( j==2 || j==13 ) {
            d2 += month[11];
            j = 12;
        }
        else {
            d2 += month[j-2] + ((j==3) ? flag : 0 );
            j--;
        }
    }
    if ( j==13 )
        j = 1;
    printf("%d.%d.%d\n", i, j, d2);
    return 0;
}