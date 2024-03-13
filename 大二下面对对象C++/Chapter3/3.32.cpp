#include <iostream>
using namespace std;

int fun(double i) {
    return i;
}

int main()
{
    int (*p) (double i);
    p = fun;
    cout << (*p) (3.1415) << endl;
    return 0;
}