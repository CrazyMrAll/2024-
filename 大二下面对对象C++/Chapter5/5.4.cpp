#include <iostream>
using namespace std;

class A;

class B
{
public:
    friend class A;
    void pa(A* a) {
        cout << "Now A" << endl;
    }
};

class A
{
public:
    friend class B;
    void pb(B* b) {
        cout << "Now B" << endl;
    }
};

int main()
{
    A a;
    B b;
    a.pb(&b);
    b.pa(&a);
    return 0;
}