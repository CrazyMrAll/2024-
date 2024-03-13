#include <iostream>
#include <cmath>
using namespace std;

double distance(int x, int y = 0, int z = 0) {
    return sqrt(x*x + y*y + z*z);
}

double distance(double x, double y = 0.0, double z = 0.0) {
    return sqrt(x*x + y*y + z*z);
}

int main()
{
    cout << "the distance between (1.5, -1.5) and O is: " << distance(1.5, -1.5) << endl;
    cout << "the distance between (1, 1, 1) and O is: " << distance(1, 1, 1) << endl;
    return 0;
}