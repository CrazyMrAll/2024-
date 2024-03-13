#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 501

int main()
{
    int n;
    scanf("%d", &n);
    char a[MAXN], b[MAXN], c[2*MAXN];
    for ( int i=0; i<MAXN; i++ )
        a[i] = b[i] = '0';
    bool flag = 1;
    for ( int i=0; i<n; i++ ) {
        cin >> c;
        int j, k;
        j = k = 0;
        for ( int i=0; c[i]!='+' && c[i]!='-'; i++ )
            a[j++] = c[i];
        if ( c[j]=='-' ) flag = 0;
        for ( int i=j+1; c[i]!='\0'; i++ )
            b[k++] = c[i];
        if ( flag ) {
            int max = (j>k) ? j-1 : k-1;
            int sum, next = 0;
            int h;
            for ( h=0; max>=0; h++ ) {
                int t = a[max]-'0' + b[max]-'0' + next;
                sum = t % 10;
                next = t / 10;
                c[max] = sum + '0';
            }
            c[h] = '\0';
            cout << c;
        } else {

        }
    }
    return 0;
}