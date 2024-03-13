#include <iostream>
using namespace std;

class A{
private:
    static const int size = 6;
    int array[size];
    const int v1;
    static int v2;
public:
    inline A(int a):v1(a) {
        cout << "set v1 = " << a << endl;
    }
    static void printv2() {
        cout << "v2 = " << v2 << endl;
    }
    inline void print() {
        for (register int i = 0 ; i < size; i++)
            cout << "a[" << i << "] = " << array[i] << endl;
        printv2();
    }
};

int A::v2 = 123;

int main()
{
    A c(231);
    c.print();
    return 0;
}