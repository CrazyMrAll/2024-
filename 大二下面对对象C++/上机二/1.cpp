#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int x = 0, int y = 0): numerator(x), denominator(y) {}
    friend Fraction operator+(const Fraction& A, const Fraction& B);
    operator double();
    friend ostream& operator<<(ostream& ost, const Fraction& A);
};

Fraction operator+(const Fraction& A, const Fraction& B) {
    int a = A.numerator*B.denominator + A.denominator*B.numerator;
    int b = A.denominator * B.denominator;
    int m = a, n = b;
    while (m != n) {
        if (m > n) m = m - n;
        else n = n - m;
    }
    a /= n, b /= n;
    return Fraction(a, b);
}

Fraction::operator double() {
    double a = numerator, b = denominator;
    return a/b;
}

ostream& operator<<(ostream& ost, const Fraction& A) {
    ost << A.numerator << "/" << A.denominator;
    return ost;
}

int main( ) {
    Fraction R1(1, 2), R2(2, 3), R3;
    R3 = R1 + R2;
    double number = R3;
    cout << R3 << endl;
    cout << number << endl;
    return 0;
}

// output：
// 7/6    
// 1.16667