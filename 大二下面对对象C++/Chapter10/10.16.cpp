#include "10.16.h2.h"
#include <iostream>
using namespace std;
namespace ms = myspace;

int ms::add(int a, int b) {
    return a + b;
}

int ms::minus(int a, int b) {
    return a - b;
}

void ms::hello() {
    cout << "hello world" << endl;
}

int main()
{
    cout << ms::add(1, 2) << endl;
    {
        using namespace ms;
        hello();
    }
    return 0;
}