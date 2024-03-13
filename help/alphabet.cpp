#include <iostream>
using namespace std;

void equal(int len) {
    if ( len==0 ) {
        cout << endl;
        return;
    }
    cout << "=";
    equal(len-1);
}

void blank(int n) {
    if ( n==0 ) return;
    cout << " ";
    blank(n-1);
}

void line(int m) {
    if ( m==0 ) {
        cout << 'A';
        return;
    }
    cout << (char)('A' + m);
    line(m-1);
    cout << (char)('A' + m);
}

void image(int m, int n) {
    if ( n==-1 ) return;
    blank(n);
    line(m);
    cout << endl;
    image(m+1, n-1);
    if ( n==0 ) return;
    blank(n);
    line(m);
    cout << endl;
}

int main()
{
    cout << "请输入结束字符(A~Z)" << endl;
    char letter;
    cin >> letter;
    int n = letter - 'A';
    int len = 2*n + 1;
    equal(len);
    cout << "菱形(" << letter << "->A)" << endl;
    equal(len);
    image(0,n);
    return 0;
}