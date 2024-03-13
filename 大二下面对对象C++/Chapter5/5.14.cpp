#include "5.14.h"
#include <iostream>
using namespace std;

class StackOfint::StackImp
{
public:
    int length;
    int* stack;
    int top;
};

void StackOfint::initialize(int length) {
    p = new StackImp;
    p->length = length;
    p->stack = new int[length];
    p->top = -1;
    cout << "initialize succeed" << endl;
}

void StackOfint::push(int X) {
    p->stack[++(p->top)] = X;
    cout << "push " << X << endl;
}

void StackOfint::pop() {
    cout << "pop " << p->stack[(p->top)--] << endl;
}

void StackOfint::print() {
    cout << "from base to the top:" << endl;
    for (register int i = 0; i <= p->top; i++)
        cout << p->stack[i] << " ";
    cout << endl;
}
