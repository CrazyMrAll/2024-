#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num[10] = {0X7D, 0X50, 0X37, 0X57, 0X5A, 0X4F, 0X6F, 0X54, 0X7F, 0X5F};
    char n[6];
    while ( cin>>n && !(n[0]=='0' && n[1]=='\0') ) {
        int len = strlen(n);
        if ( len<5 )
            for ( int i=0; i<5-len; i++ )
                printf("%0X ", num[0]);
        for ( int i=0; n[i]!='\0'; i++ ) {
            printf("%0X", num[n[i]-'0']);
            (n[i+1]=='\0') ? printf("\n") : printf(" ");
        }
    }
    return 0;
}