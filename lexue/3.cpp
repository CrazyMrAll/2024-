#include <iostream>
using namespace std;
#define Months 12

int main()
{
    int y1, m1, d1, y2, m2, d2, i, j, t, is;
    char month[Months] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    t = 0;
    for ( i=y1; i<=y2; i++ ) {
        is = (i%4==0 && i%100!=0 || i%400==0);
        for ( (i==y1) ? j=m1 : j=0; j<Months; j++ ) {
            if ( (y1==y2 && j==m2) || (i==y2 && j+1==m2) )
                break;
            else
                t += month[j];       
        }
        if ( (i==y1 && is==1 && m1<=2) || (i==y2 && is==1 && m2>=3) || (i!=y1 && i!=y2 && is==1) )
            t += is;
    }
    if ( y1==y2 && m1==m2 )
        t = d2 - d1;
    else
        t += d2 + month[m1-1] - d1;
    cout << t << ((t==1) ? " day" : " days") << endl;
    return 0;
}