#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 70

int main()
{
    char s[MAXN];
    char code[(MAXN/3+(MAXN%3!=0))*4];
    bool num[MAXN*8+16];
    cin.getline(s,MAXN);
    int len = strlen(s);
    if ( len%3 )
        for ( int i=(3-len%3)*8; i>0; i-- )
            num[len*8+i-1] = 0;
    for ( int i=len; i>0; i-- ) {
        int k = s[i-1] - '0';
        for ( int j=8; j>0; j-- ) {
            num[i*8+j-1] = k % 2;
            k /= 2;
        }
    }
    int i;
    for ( i=0; i<(len/3+(len%3!=0))*4; i++ ) {
        int letter = 0;
        int rate = 1;
        for ( int j=5; j>=0; j-- ) {
            letter += num[i*6+j] * rate;
            rate *= 2;
        }
    }
    code[i] = '\0';
    cout << code << endl;
    return 0;
}