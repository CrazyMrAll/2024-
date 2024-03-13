#include <iostream>
using namespace std;

int main()
{
    char a[50];
    cin.getline(a,50);
    for ( int i=0; a[i]!='\0'; i++ ) {
        if ( a[i+1]=='-' && a[i+2]>a[i] ) {
            bool flag = 0;
            if ( (a[i]>='0' && a[i]<='9' && a[i+2]<='9') || (a[i]>='a' && a[i]<='z' && a[i+2]<='z') || (a[i]>='A' && a[i]<='Z' && a[i+2]<='Z') ) 
                flag = 1;
            if ( flag ) {
                int dis = a[i+2] - a[i];
                for ( int j=0; j<=dis; j++ )
                    printf("%c", a[i]+j);
                i+=2;
            } else printf("%c", a[i]);;
        } else printf("%c", a[i]);
    }
    printf("\n");
    return 0;
}