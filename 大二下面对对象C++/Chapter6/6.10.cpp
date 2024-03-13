#include <iostream>
using namespace std;

class A
{
private:
    int data;
};

class B
{
private:
    int data;
public:
    B(int X) {
        cout << "create an object of class B." << endl;
        data = X;
    }
};


int main()
{
    A a;
    // B b; wrong
    B b(231);
    return 0;
}