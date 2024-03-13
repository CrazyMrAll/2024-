#ifndef StackOFINT_H
#define StackOFINT_H

class StackOfint
{
private:
    class StackImp;
    StackImp* p;
public:
    void initialize(int length);
    void push(int X);
    void pop();
    void print();
};

#endif