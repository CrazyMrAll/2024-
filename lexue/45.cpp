#include <iostream>
using namespace std;
#define Months 12

int main()
{
    int y1, m1, d1, y2, m2, d2, i, j, t, isLeapYear;
    y1 = 2012, m1 = 4, d1 = 9; 
    char month[Months] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day[5] = {5, 1, 2, 3, 4};
    cin >> y2 >> m2 >> d2;
    t = 0;
    for ( i=y1; i<=y2; i++ ) {
        isLeapYear = ((i%4==0 && i%100!=0) || i%400==0);
        for ( (i==y1) ? j=m1 : j=0; j<Months; j++ ) {
            if ( (y1==y2 && j==m2) || (i==y2 && j+1==m2) )
                break;
            else
                t += month[j];       
        }
        if ( (i==y1 && isLeapYear && m1<=2) || (i==y2 && i!=y1 && isLeapYear && m2>=3) || (i!=y1 && i!=y2 && isLeapYear) )
            t += isLeapYear;
    }
    if ( y1==y2 && m1==m2 )
        t = d2 - d1;
    else
        t += d2 + month[m1-1] - d1;
    int begin = 3;
    int cnt = t / (13*7);
    begin -= cnt;
    while ( begin<=0 ) begin += 5;
    t %= 7;
    if ( t==5 || t==6 ) printf("Free.\n");
    else printf("%d and %d.\n", day[(begin+t)%5], (day[(begin+t)%5]+5)%10);
    return 0;
}