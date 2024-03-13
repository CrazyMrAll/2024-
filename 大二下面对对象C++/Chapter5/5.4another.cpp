#include <iostream>
using namespace std;

class B;

class A
{
private:
    void show() {
        cout << "Now call A" << endl;
    }
public:
    friend class B;//已提前声明B
    void pb(B* b);
};

class B
{
private:
    void show() {
        cout << "Now call B" << endl;
    }
public:
    friend class A;
    void pa(A* a) {
        (*a).show();
    }
};

void A::pb(B* b) {
    (*b).show();
}

int main()
{
    A a;
    B b;
    a.pb(&b);
    b.pa(&a);
    return 0;
}