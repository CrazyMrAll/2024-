#include "4.h"
#include <iostream>
#include <cmath>
using namespace std;

CQuadEq::CQuadEq() {
    a = b = c = 0;
}

CQuadEq::CQuadEq(double x, double y, double z) {
    a = x, b = y, c = z;
}

void CQuadEq::FindRoot() {
    if (fabs(a) <= 1e-6) {
        if (fabs(b) <= 1e-6) cout << "error!" << endl;
        else x1 = x2 = -c / b;
    } else {
        d = b*b - 4*a*c;
        if (fabs(d) <= 1e-6 || d < -1e-6) x1 = x2 = -b / 2*a;
        else {
            x1 = (-b - sqrt(d)) / 2*a;
            x2 = (-b + sqrt(d)) / 2*a;
        } 
    }
}

void CQuadEq::Show() {
    if (fabs(a) <= 1e-6) {
        cout << "x = " << x1 << endl;
    } else {
        if (fabs(d) <= 1e-6) cout << "x1 = x2 = " << x1 << endl;
        else if (d > 1e-6) {
            x1 = (-b - sqrt(d)) / 2*a;
            x2 = (-b + sqrt(d)) / 2*a;
            cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        } else cout << "x1 = " << x1 << " + " << sqrt(-d)<< "i, x2 = " << x2 << " + " << sqrt(-d) << "i" << endl;
    }
}