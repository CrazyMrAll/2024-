#include <iostream>
using namespace std;

class Counted
{
private:
    int id;
    static int count;
public:
    Counted(): id(count++) {cout << "Call Constructor" << endl;}
    ~Counted() {cout << "id = " << id << endl;}
};

int Counted::count = 0;

int main()
{
    Counted* p;
    p = new Counted;
    delete p;
    p = new Counted[6];
    delete []p;
    p = new Counted[6];
    delete p;
    return 0;
}