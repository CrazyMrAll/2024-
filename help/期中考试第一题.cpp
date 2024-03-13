#include<stdio.h>

int main()
{
    int n;
    char ch;
    scanf("%d %c", &n, &ch);
    char map[n][n];
    if ( !((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) )
        printf("Input error!\n");
    else {
        if (ch>='a' && ch<='z') ch += 'A' - 'a';
        for ( int i=0; i<n; i++ ) {
            for ( int j=0; j<n; j++ ) {
                if ( i==0 ) map[i][j] = ch + j;
                else if ( j==0 ) map[i][j] = ch + i;
                else if ( i==n-1 ) map[i][j] = ch + j + n-1;
                else if ( j==n-1 ) map[i][j] = ch + i + n-1;
                else map[i][j] = ' ';
                if ( map[i][j] != ' ' ) 
                	while ( map[i][j]>'Z' ) map[i][j] -= 'Z' - 'A' + 1;  
            }
        }
        for ( int i=0; i<n; i++ ) {
	        for ( int j=0; j<n; j++ ) {
	            printf("%c", map[i][j]);
	            (j==n-1) ? printf("\n") : printf(" ");
	        }
	    } 
    }
    return 0;
}