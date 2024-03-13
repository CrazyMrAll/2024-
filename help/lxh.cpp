#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    cout << "the result is:" << endl;
    int a, b, c;
    a = 1000;
    for (; a++; a <= 9999)
        b = a % 100;
    c = (a - b) / 100;
    if (pow((b + c), 2) == a)
    cout << a;
    return 0;
}