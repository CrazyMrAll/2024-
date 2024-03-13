#include <iostream>
using namespace std;

int is_power(int num, int base) {
    if ( num==1 ) return 1;
    int t = num / base;
    if ( t*base==num ) {
        if ( t==1 ) return 1;
        is_power(num, base*base);
    } else return 0;
}

int main()
{
    int num, base;
    cin >> num >> base;
    cout << is_power(num, base) << endl;
    return 0;
}