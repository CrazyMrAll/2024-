#include <stdio.h>
#define type 4
#define MAXNLINE 20
#define MAXN 100

int main()
{
    char a[type], s[MAXN][MAXNLINE+1];
    int n, b[MAXNLINE];
    scanf("%d\n", &n);
    for ( int i=0; i<type; i++ ) 
        scanf("%c\n", &a[i]);
    for ( int i=0; i<n; i++ ) {
        b[i] = 0;
        scanf("%s", s[i]);
        for ( int j=0; s[i][j]!='\0'; j++ ) {
            b[i] *= type + 1;
            if ( s[i][j]==a[0] ) b[i]+=4;
            else if ( s[i][j]==a[1] ) b[i]+=3;
            else if ( s[i][j]==a[2] ) b[i]+=2;
            else if ( s[i][j]==a[3] ) b[i]+=1;
        }
    }  
    
    for ( int i=0; i<n; i++ ) {
        int maxi = 0;
        for ( int i=1; i<n; i++ ) 
            if ( b[maxi] < b[i] ) maxi = i;
        b[maxi] = -1;
        printf("%s\n", s[maxi]);
    }
    return 0;
}