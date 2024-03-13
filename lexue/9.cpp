#include <iostream>
using namespace std;

int main()
{
    bool flag = 1, flag2 = 1;
    int y, m, d, W;
    cin >> y >> m >> d;
    if ( m<1 || m>12 ) flag=0;
    if ( (m<=7 && m%2==1) || (m>=8 && m%2==0) ) {
        if ( d<1 || d>31 ) flag2=0;
    }
    else if ( m==2 ) {
        if ( d<1 || d>28+((y%4==0 && y%100!=0) || y%400==0) ) flag2=0;
    }
    else {
        if ( d<1 || d>30 ) flag2=0;
    }
    if ( flag==1 && flag2==1 ) {
        if ( m==1 || m==2 ) {m+=12; y--;}
        W = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1) % 7;
        printf("%d\n", W);
    } else if ( flag2==1 ) printf("month is wrong.\n");
    else if ( flag==1 ) printf("day is wrong.\n");
    else printf("month and day are wrong.\n"); 
    return 0;
}