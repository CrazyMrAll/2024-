#include <iostream>
using namespace std;

int fun(int n) {
    if (n == 1) return 1;
    else return n * fun(n-1);
}

int main()
{
    int n;
    int (*p) (int n);
    p = fun;
    cout << "input a number" << endl;
    cin >> n;
    cout << "invoke fun: " << n << "! = " << fun(n) << endl;
    cout << "by pointer of fun: " << n << "! = " << (*p)(n) << endl;
    return 0;
}