#include <iostream>
#include <cstring>
using namespace std;

class A
{
public:
    virtual void f() {cout << "A::f1()" << endl;}
    virtual void f(string s) {cout << "A::f2()--" << s << endl;}
    virtual int f(int a, int b) {
        cout << "A::f3()--" << a+b << endl; 
        return a+b;
    }
};

class B: public A
{
public:
    // void f() {cout << "B::f()" << endl;}
};

int main()
{
    B b;
    b.f();
    // error befor remove overriden definition in the derived class
    b.f("Hello world");
    b.f(1, 2);
    A *a = &b;
    a->f();
    a->f("Hello world");
    a->f(1, 2);
    return 0;
}