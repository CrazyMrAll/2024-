#include <iostream>
using namespace std;
#define MAXN 101

int main()
{
    int cnt[10];
    for ( int i=0; i<10; i++ )
        cnt[i] = 0;
    char num[MAXN];
    cin >> num;
    for ( int i=0; num[i]!='\0'; i++ ) 
        cnt[num[i]-'0']++;
    for ( int i=9; i>=0; i--) {
        while ( cnt[i]!=0 ) {
            cout << i;
            cnt[i]--;
        }
    }
    cout << endl;
    return 0;
}