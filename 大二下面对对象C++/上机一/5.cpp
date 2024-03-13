#include "5.h"
#include <iostream>
#include <cmath>
using namespace std;

Triangle::Triangle(double x, double y, double z) {
    a = x, b = y, c = z;
}

double Triangle::Area() {
    double p = (a + b + c) / 2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

bool Triangle::IsTrig() {
    if (a+b > c && a+c > b && b+c > a) return 1;
    else return 0;
}

double SumArea(Triangle& m, Triangle& n) {
    if (m.IsTrig() && n.IsTrig()) {
        return m.Area() + n.Area();
    } else cout << "error" << endl;
}