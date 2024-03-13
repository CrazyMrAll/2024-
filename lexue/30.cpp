#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Sqrt (double x, double p, double e) {
    if ( fabs(p*p-x)<e ) return p;
    else Sqrt(x, 0.5*(p+x/p), e);
}

int main()
{
    double x, e;
    cin >> x >> e;
    cout << fixed << setprecision(8) << Sqrt(x, 1, e) << endl;
    return 0;
}