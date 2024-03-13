#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double xi, ave, crediti;
    int cnt = 0;
    while (cin>>xi>>crediti && !fabs(xi)<1e-6) {
        cnt++;
        ave += xi * crediti;
    }
    ave /= cnt;
    cout << "Average=" << ave << endl;
    return 0;
}