#include <iostream>
using namespace std;

class A
{
public:
    inline A() {
        cout << "create an object of A" << endl;
    }
};

class B
{
public:
    inline B() {
        cout << "create an object of B" << endl;
    }
private:
    A a;
};

int main()
{
    B b[6];
    return 0;
}