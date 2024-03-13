#include <iostream>
using namespace std;

template <typename T>
T fibonacci(T n) {
    const int sz = 100;
    if (n >= sz) {return -1;}
    else {
        static T f[sz]; // Initialized to zero
        f[0] = f[1] = 1;
        // Scan for unfilled array elements:
        int i;
        for(i = 0; i < sz; i++)
            if(f[i] == 0) break;
        while(i <= n) {
            f[i] = f[i-1] + f[i-2];
            i++;
        }
        return f[int(n)];
    }
} ///:~

int main()
{
    cout << fibonacci(6) << endl;
    cout << fibonacci(6.6) << endl;
    cout << fibonacci(99) << endl;
    cout << fibonacci(99.5) << endl;
    cout << fibonacci<long long>(99) << endl;
    cout << fibonacci(10000000000) << endl;
    return 0;
}