#include <iostream>
using namespace std;
#define MAXN 100

int main()
{
    char a[MAXN], b[MAXN], c[MAXN];
    int i = 0, j = 0, k = 0;
    cin.getline(a, MAXN);
    cin.getline(b, MAXN);
    while ( a[i]!='\0' || b[k]!='\0' ) {
        if ( a[i]=='\0' ) 
            while ( b[k]!='\0' ) c[j++]=b[k++];
        else if ( b[k]=='\0' )
            while ( a[i]!='\0' ) c[j++]=a[i++];
        else {
            if ( a[i]<b[k] ) {c[j++]=a[i++];}
            else if ( a[i]>b[k] ) {c[j++]=b[k++];}
            else {c[j++]=a[i++];c[j++]=b[k++];}
        }
    }
    c[j] = '\0';
    cout << c << endl;
    return 0;
}