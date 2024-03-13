//: C14:Combined.cpp
// Inheritance & composition
#include <iostream>
using namespace std;

class A {
    int i;
public:
    A(int ii) : i(ii) {cout << "Call the constructor of A" << endl;}
    ~A() {cout << "Call the destructor of A" << endl;}
    void f() const {}
};

class B {
    int i;
public:
    B(int ii) : i(ii) {cout << "Call the constructor of B" << endl;}
    ~B() {cout << "Call the destructor of B" << endl;}
    void f() const {}
};

class C : public B {
    A a;
public:
    C(int ii) : B(ii), a(ii) {cout << "Call the constructor of C" << endl;}
    ~C() {cout << "Call the destructor of C" << endl;} // Calls ~A() and ~B()
    void f() const {  // Redefinition
        a.f();
        B::f();
    }
};

class D: public B
{
private:
    C c;
public:
    D(int ii): D::B(ii), c(ii) {cout << "Call the constructor of D" << endl;}
    ~D() {cout << "Call the destructor of D" << endl;} 

};

int main() {
    {
       C c(47); 
    }
    cout << endl;
    D d(231);
} ///:~