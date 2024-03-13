#include "5.h"
#include <iostream>
using namespace std;

int main()
{
    Triangle a(3, 4, 5);
    Triangle b(6, 8, 10);
    cout << "sum of area is: " << SumArea(a, b) << endl;
    return 0;
}