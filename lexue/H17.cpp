#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    char s[11];
    for ( int i=0; i<n; i++ ) {
        scanf("%s", s);
        int sum = 0, len = strlen(s);
        if ( len==1 ) printf("%d\n", s[0]-'a'+1);
        else {
            int minus = 0;
            for ( int i=0; i<len-1; i++ ) {
                int t = s[i] - 'a' + 1;
                for ( ; t>0; t-- ) {
                    int tmp = 1;
                    for ( int j=i; j<len-1; j++ ) {
                        tmp *= t;
                    }
                    minus += tmp;
                }
            }
            for ( int i=0; s[i]!='\0'; i++ ) {
                sum = sum * (27-len+1) + s[i] - 'a' + 1;
            }
            sum -= minus;
            printf("%d\n", minus);
            printf("%d\n", sum);
        }
    }
    return 0;
}