#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[101], t[11], str[11];
    cin.getline(s,101);
    cin.getline(t,11);
    cin.getline(str,11);
    int cnt = 0, len = strlen(t);
    char *p[99];
    for ( int i=0; s[i]!='\0'; i++ ) {
        if ( s[i]==t[0] ) {
            int j = 1;
            for ( ; s[i+j]==t[j] && s[i+j]!='\0'; j++ );
            if ( j==len ) {
                s[i]='\0';
                p[cnt++]=&s[i+len];
                i+=len-1;
            }
        }
    }
    cout << s;
    for ( int i=0; i<cnt; i++ ) cout << str << p[i];
    cout << endl;
    return 0;
}