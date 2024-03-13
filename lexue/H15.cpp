#include <iostream>
#include <cstring>
using namespace std;
#define WTF 65536

int main()
{
    char s[100];
    bool flag = 1;
    while ( flag ) {
        cin.getline(s,100);
        if ( s[0]=='E' && s[1]=='N' && s[2]=='D' && s[3]=='\0' ) flag=0;
        else if ( s[0]=='$' && s[1]=='G' && s[2]=='P' && s[3]=='R' && s[4]=='M' && s[5]=='C' && s[18]=='A' ) {
            int h, min, sec, sum, ans, i;
            ans = 0;
            sum = s[1];
            for ( i=1; ; i++ ) {
                if ( s[i+1]=='*' ) {i+=2;break;}
                sum ^= s[i+1];
                sum %= WTF;
            }
            for ( ; s[i]!='\0'; i++ ) {
                if ( s[i]>='0'&& s[i]<='9') ans = ans*16 + s[i] - '0';
                else if ( s[i]>='a' && s[i]<='z' ) ans = ans*16 + s[i] - 'a' + 10;
                else ans = ans*16 + s[i] - 'A' + 10;
            }    
            if ( sum==ans ) {
                h = (s[7]-'0')*10 + s[8]-'0' + 8;
                min =  (s[9]-'0')*10 + s[10]-'0';
                sec =  (s[11]-'0')*10 + s[12]-'0';
                if ( h>=24 ) h-=24;
                printf("%02d:%02d:%02d\n", h, min, sec);
            } else continue;
        } else continue;     
    }
    return 0;
}