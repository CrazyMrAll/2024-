#include <iostream>
using namespace std;

void swap1(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap2(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int a = 231;
    int b = 123;
    cout << "a = " << a << ", b = " << b << endl;
    swap1(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;
    swap2(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}