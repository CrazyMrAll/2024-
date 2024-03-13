#include <iostream>
using namespace std;

class Number
{
private:
    double num;
public:
    Number() {};
    Number(double n): num(n) {};
    void print() {cout << "num = " << num << endl;}
    operator double() {return num;}
    friend const Number operator+ (const Number& N1, const Number& N2);
    friend const Number operator- (const Number& N1, const Number& N2);
    friend const Number operator* (const Number& N1, const Number& N2);
    friend const Number operator/ (const Number& N1, const Number& N2);
};

const Number operator+ (const Number& N1, const Number& N2) {
    return Number(N1.num + N2.num); 
}

const Number operator- (const Number& N1, const Number& N2) {
    return Number(N1.num - N2.num); 
}

const Number operator* (const Number& N1, const Number& N2) {
    return Number(N1.num * N2.num); 
}

const Number operator/ (const Number& N1, const Number& N2) {
    return Number(N1.num / N2.num); 
}

int main()
{
    Number N1(2.5), N2(3.14), N3;
    cout << "N1 = " << double(N1) << endl;
    N3 = N1 + N2;
    N3.print();
    N3 = N1 - N2;
    N3.print();
    N3 = N1 * N2;
    N3.print();
    N3 = N1 / N2;
    N3.print();
    return 0;
}