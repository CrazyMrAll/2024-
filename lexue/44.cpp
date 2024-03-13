#include <iostream>
using namespace std;
#define type 4

int main()
{
    bool flag[type];
    int n;
    cin >> n;
    cin.ignore(1024,'\n');
    for ( int i=0; i<n; i++ ) {
        for ( int i=0; i<type; i++ )
            flag[i] = 0;
        int ret = 0, j;
        char pwd[21];
        cin.getline(pwd,21);
        for ( j=0; pwd[j]!='\0'; j++ ) {
            if ( pwd[j]>='0' && pwd[j]<='9' ) flag[0] = 1;
            else if ( pwd[j]>='a' && pwd[j]<='z' ) flag[1] = 1;
            else if ( pwd[j]>='A' && pwd[j]<='Z' ) flag[2] = 1;
            else flag[3] = 1;
        }
        if ( j>5 ) {
            for ( int i=0; i<type; i++ ) 
                ret += flag[i]; 
        }
        switch ( ret )
        {
        case 1 : cout << "Not Safe" << endl; break;
        case 2 : cout << "Medium Safe" << endl; break;
        case 3 : case 4 : cout << "Safe" << endl; break;
        default: cout << "Not Safe" << endl; break;
        }
    }
    return 0;
}