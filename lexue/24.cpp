#include <iostream>
using namespace std;
#define MAXN 100

int main()
{
    char a[MAXN];
    cin.getline(a, 100);
    for ( int i=0; a[i]!='\0'; ) {
        for ( int j=i+1; a[j]!='\0'; j++ ) {
            if ( a[j]==a[i] )
                for ( int k=j; a[k]!='\0'; k++ ) {
                    a[k] = a[k+1];
                }
        }
        if ( a[i]!=a[i+1] ) i++;
    }
    cout << a << endl;
    return 0;
}