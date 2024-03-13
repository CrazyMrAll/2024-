#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream infile;
    char filename[100] = {"test.txt"}, s[80];
    infile.open(filename);
    if (!infile) {cerr << "error" << endl; return 1;}
    /*while (infile.eof()) {
        infile.getline(s, 80, '\n');
        cout << s << endl;
    }*/
    infile.close();
    return 0;
}