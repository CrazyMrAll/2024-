#include "Handle.h"
#include <iostream>
using namespace std;

// Define Handle's implementation:
struct Handle::Cheshire {
    int i;
};

// void Handle::initialize() {
//     smile = new Cheshire;
//     smile->i = 0;
// }

// void Handle::cleanup() {
//     delete smile;
// }

int Handle::read() {
    return smile->i;
}

void Handle::change(int x) {
    smile->i = x;
}

Handle::Handle() {
    cout << "create an object" << endl;
    smile = new Cheshire;
    smile->i = 0;
}

Handle::~Handle() {
    delete smile;
    cout << "free malloc" << endl;
}