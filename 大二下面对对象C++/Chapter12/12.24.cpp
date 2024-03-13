#include <iostream>
#include <cstring>
using namespace std;

class A
{
private:
    string s;
public:
    A(string ss): s(ss) {cout << "Initialize A" << endl;}
    void print() {cout << s << endl;}
};

class B
{
private:
    A a;
public:
    B(string ss): a(ss) {cout << "Initialize B" << endl;}
    void print() {a.print();}
};

int main()
{
    B b1("Hello World!");
    B b2 = b1;
    b2.print();
    B b3(b1);
    b3.print();
    B b4("Hello BIT!");
    b3 = b4;
    b3.print();
    return 0;
}