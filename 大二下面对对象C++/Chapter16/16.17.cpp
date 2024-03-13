//: C16:TPStash2Test.cpp
#include "16.17.h"
#include <iostream>
#include <vector>
#include <cstring>
#include "../require.h"
using namespace std;

template <typename T>
class Auto {
    T i;
public:
    Auto(T ii = 0) : i(ii) {
        cout << ">" << i << ' ';
    }
    ~Auto() { cout << "~" << i << ' '; }
    operator T() const { return i; }
    friend ostream&
        operator<<(ostream& os, const Auto& x) {
        return os << "Auto: " << x.i;
    }
    friend ostream&
        operator<<(ostream& os, const Auto* x) {
        return os << "Auto: " << x->i;
    }
};

int main() {
{ // To force destructor call
    PStash<Auto<double>> ints;
    for(double i = 1.2; i < 30; i++)
        ints.add(new Auto<double>(i));
    cout << endl;
    PStash<Auto<double>>::iterator it = ints.begin();
    it += 5;
    PStash<Auto<double>>::iterator it2 = it + 10;
    for(; it != it2; it++)
        delete it.remove(); // Default removal
    cout << endl;
    for(it = ints.begin();it != ints.end();it++)
    if(*it) // Remove() causes "holes"
        cout << *it << endl;
} // "ints" destructor called here
    // cout << "\n-------------------\n";  
    // ifstream in("16.17.cpp");
    // assure(in, "16.17.cpp");
    // // Instantiate for String:
    // PStash<string> strings;
    // string line;
    // while(getline(in, line))
    //     strings.add(new string(line));
    // PStash<string>::iterator sit = strings.begin();
    // for(; sit != strings.end(); sit++)
    //     cout << **sit << endl;
    // sit = strings.begin();
    // int n = 26;
    // sit += n;
    // for(; sit != strings.end(); sit++)
    //     cout << n++ << ": " << **sit << endl;
} ///:~