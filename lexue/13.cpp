#include <iostream>
using namespace std;

int len;
char b[101] = {0};
void sort ( int a[] ) {
    int cnt = 0;
    for ( int i=0; i<len; i++ ) {
        b[a[i]]++;
    }
    for ( int i=0; i<101; i++ ) {
        while ( b[i]!=0 && cnt<len ) {
            printf("%d", i);
            cnt++;
            b[i]--;
            if ( cnt<len ) printf(" ");
        }
        if ( cnt==len ) break;
    }
    printf("\n");
}

int main()
{
    scanf("%d", &len);
    int a[len];
    for ( int i=0; i<len; i++ ) {
        scanf("%d", &a[i]);
    }
    sort(a);
    return 0;
}