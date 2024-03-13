#include <iostream>
using namespace std;

class A{
public:
    void hello() {cout << "hello" << endl;}
    void world() const {cout << "world" << endl;}
};

void f1(A a) {
    a.hello();
    a.world();
}

void f2(A& a) {
    a.hello();
    a.world();
}

void f3(const A& a) {
    // a.hello(); //wrong
    a.world();
}

int main()
{
    A a;
    f1(a);
    f2(a);
    f3(a);
    return 0;
}