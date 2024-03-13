#include <iostream>
using namespace std;

class Mammal
{
public:
    virtual void Speak() {cout << "Mammal" << endl;}
};

class Dog: public Mammal
{
public:
    void Speak() {cout << "Dog" << endl;}
};

class Pug: public Dog
{
public:
    void Speak() {cout << "Pug" << endl;}
};

void Talk(Mammal& A) {
    A.Speak();
}

int main()
{
    Mammal m;
    Dog d;
    Pug p;
    Dog d2 = p;
    Mammal& m2 = p;
    Talk(m);
    Talk(d);
    Talk(p);
    Talk(d2);
    Talk(m2);
    return 0;
}

// output:
// Mammal
// Dog   
// Pug   
// Dog   
// Pug