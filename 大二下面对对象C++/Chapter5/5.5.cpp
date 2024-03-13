#include <iostream>
using namespace std;

class A;

class C
{
public:
    void show(A& a);
};

class A
{
private:
    int data;
public:
    A(int x) {data = x;}
    void show() {
        cout << data << endl;
    }
    friend class B;
    friend void C::show(A& a);
};

void C::show(A& a) {
    a.show();
}

class B
{
public:
    void show(A& a) {
        cout << a.data << endl;
    }
};

int main()
{
    A a(231);
    B b;
    C c;
    a.show();
    b.show(a);
    c.show(a);
    return 0;
}