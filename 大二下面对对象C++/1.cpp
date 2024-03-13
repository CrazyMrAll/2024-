#include <iostream>
using namespace std;

class A
{
    int a = 1;
public:
    int b = 2;
};

int main()
{
    A aa;
    int A::* p = &A::b;

    return 0;
}