#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[81];
    cin.getline(s,80);
    bool flag = 1;
    int cnt = 0;
    for ( int i=0; i<5; i++ ) {
        if ( i==4 && !(s[i]>='0' && s[i]<='9')) {flag=0;break;}
        else if ( s[i]>='A' && s[i]<'Z' && s[i]!='I' && s[i]!='O' ) cnt++;
        else if ( !(s[i]>='0' && s[i]<='9') ) {flag=0;break;}
    }
    if ( flag && cnt>=2 ) printf("ok.\n");
    else printf("no.\n");
    return 0;
}
