//: C14:Combined.cpp
// Inheritance & composition
#include <iostream>
using namespace std;

class A {
    int i;
public:
    A(int ii) : i(ii) {}
    ~A() {}
    virtual void f() const {cout << "A::f()" << endl;}
};

class B : public A {
    int i;
public:
    B(int ii) : A(ii), i(ii) {}
    ~B() {}
    void f() const {cout << "B::f()" << endl;}
};

class C : public B {
public:
    C(int ii) : B(ii) {}
    ~C() {} // Calls ~A() and ~B()
    void f() const {cout << "C::f()" << endl;}
};

int main() {
    C c(231);
    c.f();
    cout << endl;
    B b1 = c;
    b1.f();
    cout << endl;
    B &b2 = c;
    b2.f();
    cout << endl;
    A a1 = c;
    a1.f();
    cout << endl;
    A &a2 = c;
    a2.f();
} ///:~