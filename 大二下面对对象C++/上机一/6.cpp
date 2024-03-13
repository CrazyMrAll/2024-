#include "6.h"
#include <iostream>
using namespace std;

Circle::Circle(double x) {
    r = x;
}

void Circle::printArea() const {
    cout << "Area of the circle is: " << s << endl;
}

void Circle::getArea() {
    s = Pi * r * r;
}