#include <iostream>
using namespace std;

int main()
{
    int l, b, i, j;
    cin >> l >> b;
    for ( i=1; i<=l; i++ ) {
        for ( j=1; j<=3*l-i-1; j++ ) {
            if (i==1 || i==l) {
                if ( j<i )
                    cout << " ";
                else if ( j<=(3*l-2)/2 )
                    cout << (b+j-1)%10;
                else
                    cout << (b+3*l-j-2)%10;
            }
            else {
                if ( j==i || j==3*l-i-1 )
                    cout << (b+i-1)%10;
                else        
                    cout << " ";
            }

            if ( j!=3*l-i-1)
                cout << " ";
            else
                cout << endl;

        }
    }
    return 0;
}