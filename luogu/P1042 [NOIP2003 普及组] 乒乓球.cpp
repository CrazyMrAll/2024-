#include <iostream>
using namespace std;

int num = 0, W = 0, L = 0;
char s[100001];

void newcount (char s[]) {
    for ( int i=0; i<=num; i++ ) {
        if ( s[i]=='W' ) W++;
        else if ( s[i]=='L' ) L++;
        if ( ((L>=11 || W>=11) && (L>W ? L-W>=2 : W-L>=2)) || i==num ) {
            printf("%d:%d\n", W, L);
            W = L = 0;
        }
    }
    printf("\n");
}

void oldcount (char s[]) {
    for ( int i=0; i<=num; i++ ) {
        if ( s[i]=='W' ) W++;
        else if ( s[i]=='L' ) L++;
        if ( ((L>=21 || W>=21) && (L>W ? L-W>=2 : W-L>=2)) || i==num ) {
            printf("%d:%d\n", W, L);
            W = L = 0;
        }
    }
    printf("\n");
}

int main()
{
    while ( cin >> s[num] && s[num]!='E' ) { num++; }
    newcount(s);
    oldcount(s);
    return 0;
}