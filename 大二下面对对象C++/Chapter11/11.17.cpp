#include <iostream>
using namespace std;

class A
{
private:
    double *p;
public:
    A(double a) {
        cout << "Constructor" << endl;
        p = new double(a);
    }
    A(const A& b) {
        p = b.p;
        cout << "Copy" << endl;
    }
    ~A() {
        cout << "Destructor" << endl;
        cout << *p << endl;
        *p = -1;
        delete p;
        p = NULL;
    }
};

void f1(A b) {

}

int main()
{
    A a(3.14);
    f1(a);
    return 0;
}