#include <iostream>
using namespace std;

char a[] = {1,3,1,3,1,3,1,3,1,3,1,3,1};
char b[] = {10,9,8,7,6,5,4,3,2,1};
int main()
{
    bool flag = 1;
    char s[17];
    int i = 0;
    while ( cin >> s[i] ) {i++;}
    if ( i==13 ) {
        int cnt = 0, check = 0, i = 0;
        for ( int j=0; j<13; j++ ) {
            if ( s[j]>='0' && s[j]<='9' ) {check += (s[j]-'0') * b[i];i++;}
            else if ( s[j]=='-' ) {
                cnt++;
                if ( cnt>=4 ) {flag=0;break;}
            }
            else {flag=0;break;}
        }
        if ( flag==1 ) {
            if ( check%11 == 0 && cnt==3) printf("合法的10位ISBN.\n");
            else flag=0;
        }
    }
    else if ( i==17 ) {
        int cnt = 0, check = 0, i = 0;
        for ( int j=0; j<17; j++ ) {
            if ( s[j]>='0' && s[j]<='9' ) {check += (s[j]-'0') * a[i];i++;}
            else if ( s[j]=='-' ) {
                cnt++;
                if ( cnt>=5 ) {flag=0;break;}
            }
            else {flag=0;break;}
        }
        if ( flag==1 ) {
            if ( check%10 == 0 && cnt==4) printf("合法的13位ISBN.\n");
            else flag=0;
        }
    } else printf("非法的ISBN.\n");
    if ( flag==0 ) printf("非法的ISBN.\n");
    return 0;
}