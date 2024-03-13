#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[81];
    cin.getline(s,80);
    bool flag = 1;
    int len = strlen(s);
    for ( int i=0; i<len/2; i++ ) {
        if ( s[i]!=s[len-i-1] ) {flag=0;break;}
    }
    if ( flag ) printf("Yes\n");
    else printf("No\n");
    return 0;
}