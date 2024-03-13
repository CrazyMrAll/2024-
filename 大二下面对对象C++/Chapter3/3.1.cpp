#include "3.1.h"
#include <iostream>
using namespace std;

void f1() {
    cout << "This is f1!\nIts argument list is void!\nIt returns void!" << endl;
}

char f2(char a) {
    cout << "This is f2!\nIts argument list is a char!\nIt returns another form of the letter" << endl;
    if (a >= 'a' && a <= 'z') return a += 'A' - 'a';
    else if (a >= 'A' && a <= 'Z') return a -= 'A' - 'a';
    else cout << "error" << endl;
}

int f3(int a, int b) {
    cout << "This is f3!\nIts argument list is 2 int!\nIt returns sum of 2 int numbers!" << endl;
    return a + b;
}

float f4(float a, float b) {
    cout << "This is f4!\nIts argument list is 2 float!\nIt returns sum of 2 float numbers!" << endl;
    return a + b;
}