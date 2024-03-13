#include "5.14.h"
#include <iostream>
#include <vector>
using namespace std;

class StackOfint::StackImp
{
public:
    int length;
    vector<int> stack;
};

void StackOfint::initialize(int length) {
    p = new StackImp;
    cout << "initialize succeed" << endl;
}

void StackOfint::push(int X) {
    p->stack.push_back(X);
    cout << "push " << X << endl;
}

void StackOfint::pop() {
    cout << "pop " << p->stack.back() << endl;
    p->stack.pop_back();
}

void StackOfint::print() {
    cout << "from base to the top:" << endl;
    for (vector<int>::iterator i = p->stack.begin(); i < p->stack.end(); i++)
        cout << *i << " ";
    cout << endl;
}
