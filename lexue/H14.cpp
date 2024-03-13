#include <iostream>
using namespace std;

int main()
{
    char a[30];
    int num[10], cnt = 0;
    for ( int i=0; i<10; i++ )
        num[i] = 0;
    cin.getline(a,30);
    for ( int i=0; a[i]!='\0'; i++ ) {
        if ( a[i]=='-' && a[i+1]>='0' && a[i+1]<='9' || a[i]>='0' && a[i]<='9' ) {
            int sign = 1;
            if ( a[i]=='-' ) {sign = -1;i++;}
            while ( 1 ) {
                num[cnt] = num[cnt]*10*sign + a[i]-'0';
                if ( a[i+1]=='\0' ) break;
                else if ( a[i+1]==' ' ) {cnt++;i++;break;}
                else i++;
            } 
        }
        
        else 
            switch ( a[i] ) {
                case '+' : num[cnt-2] += num[cnt-1]; num[--cnt] = 0 ; break;
                case '-' : num[cnt-2] -= num[cnt-1]; num[--cnt] = 0 ; break;
                case '*' : num[cnt-2] *= num[cnt-1]; num[--cnt] = 0 ; break;
                case '/' : num[cnt-2] /= num[cnt-1]; num[--cnt] = 0 ; break;
            }
    }
    printf("%d\n", num[0]);
    return 0;
}