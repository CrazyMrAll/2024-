#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int list[n];
    for ( int i=0; i<n; i++ ) 
        scanf("%d", &list[i]);
    int begin[n/2], end[n/2], equal_number[n/2], cnt=0;
    for ( int i=0; i<(n/2); i++ ) {
        equal_number[i] = 1;
    }
    for ( int i=1; i<n; i++ ) {
        int tmp = list[i-1];
        if ( tmp == list[i] ) {
            if ( equal_number[cnt]==1 ) begin[cnt]=i-1;
            equal_number[cnt]++;
            end[cnt] = i;
        } else if ( equal_number[cnt]!=1 ) cnt++;
    }
    int max = equal_number[0];
    int realcnt = 0;
    for ( int i=0; i<cnt; i++ ) {
        if ( max < equal_number[i+1] ) { 
            equal_number[i] = 1;
            max = equal_number[i+1];
        } else if ( max > equal_number[i+1] ) equal_number[i+1]=1;
    }
    for ( int i=0; i<=cnt; i++ ) {
        if ( max==equal_number[i] && max!=1 ) {
            equal_number[realcnt] = equal_number[i];
            begin[realcnt] = begin[i];
            end[realcnt] = end[i];
            realcnt++;
        }
    }
    if ( realcnt==0 ) printf("No equal number list.\n");
    else {
        printf("The longest equal number list is from ");
        for( int i=0; i<realcnt; i++ ) {
            printf("%d to %d", begin[i], end[i]);
            ( i==realcnt-1 ) ? printf(".") : printf(",");
        }
        printf("\n");        
    }
    return 0;
}