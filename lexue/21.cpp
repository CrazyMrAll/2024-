#include <iostream>
using namespace std;

int main()
{
    int sum = 0, i = 0;
    char str[81];
    cin.getline(str,81);
    while ( str[i]==' ' ) ++i;
    while ( str[i]!='\0' ) {
        int sign = 1;
        int data = 0;
        if ( str[i]=='-' ) {sign=-1;++i;}
        if ( str[i]=='0' ) {
            ++i;
            if ( str[i]=='x' || str[i]=='X' ) {
                ++i;
                while ( str[i]!='\0' && str[i]!=' ' ) {
                    data *= 16;
                    if ( str[i]<='F' && str[i]>='A' ) data += str[i++]-'A'+10;
                    else if ( str[i]<='f' && str[i]>='a' ) data += str[i++]-'a'+10;
                    else data += str[i++]-'0';
                }
            } else  while ( str[i]!='\0' && str[i]!=' ' ) {
                        data = data*8 + str[i++]-'0';
                    }
        } else  while ( str[i]!='\0' && str[i]!=' ' ) {
                    if ( str[i]<='9' && str[i]>='0' ) data = data*10 + str[i]-'0';
                    ++i;
                }
        sum += data * sign;
        while ( str[i]==' ' ) ++i;
    }
    printf("sum = %d\n", sum);
    return 0;
}