#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double xi, ave;
    int cnt = 0;
    while (cin>>xi && !fabs(xi)<1e-6) {
        cnt++;
        ave += xi;
    }
    ave /= cnt;
    cout << "Average=" << ave << endl;
    return 0;
}