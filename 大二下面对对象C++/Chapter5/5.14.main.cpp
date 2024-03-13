#include "5.14.h"
#include <iostream>

int main()
{
    StackOfint s;
    s.initialize(5);
    s.push(2);
    s.push(3);
    s.push(1);
    s.print();
    s.pop();
    s.print();
    return 0;
}