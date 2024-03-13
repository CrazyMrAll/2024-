#include <iostream>
#include <cstring>
using namespace std;

class Traveler
{
protected:
    string name;
public:
    Traveler(string s = ""): name(s) {cout << "constructor of Traveler" << endl;}
    Traveler(const Traveler& T) {
        cout << "copy-constructor of Traveler" << endl;
        name = T.name;
    }
    Traveler& operator= (const Traveler& T) {
        cout << "assignment operator of Traveler" << endl;
        if (this != &T) name = T.name;
        return *this;
    }
    void print() const {cout << "name = " << name << endl;}
};

class Pager
{
protected:
    string num;
public:
    Pager(string s = ""): num(s) {cout << "constructor of Pager" << endl;}
    Pager(const Pager& P) {
        cout << "copy-constructor of Pager" << endl;
        num = P.num;
    }
    Pager& operator= (const Pager& P) {
        cout << "assignment operator of Pager" << endl;
        if (this != &P) num = P.num;
        return *this;
    }
    void print() const {cout << "num = " << num << endl;}
};

class BusinessTraveler: public Traveler
{
public:
    Pager p;
public:
    BusinessTraveler() {cout << "default constructor of BusinessTraveler" << endl;}
    BusinessTraveler(string s1, string s2): Traveler(s1), p(s2) {cout << "constructor of BusinessTraveler" << endl;}
    BusinessTraveler(const BusinessTraveler& BT): Traveler(BT.name), p(BT.p) {
        cout << "copy-constructor of BusinessTraveler" << endl;
    }
    BusinessTraveler& operator= (const BusinessTraveler& BT) {
        cout << "assignment operator of BusinessTraveler" << endl;
        if (this != &BT) {
            name = BT.name;
            p = BT.p;
        } 
        return *this;
    }
    void print() const {
        Traveler::print();
        p.print();
    }
};

int main()
{
    BusinessTraveler bt1;
    bt1.print();
    cout << endl;
    BusinessTraveler bt2("Tony", "231");
    bt2.print();
    cout << endl;
    BusinessTraveler bt3(bt2);
    bt3.print();
    cout << endl;
    bt1 = bt2;
    bt1.print();
    return 0;
}