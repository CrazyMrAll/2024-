#include <iostream> 
using namespace std; 
 
int main() 
{ 
    int n, m, t, a[10]={0}; 
    scanf("%d %d", &n, &m); 
    for ( int i=0; i<n; i++ ) { 
        scanf("%d", &t); 
        a[t]++; 
    } 
    for ( int i=9; i>=0 && m>0; i-- ) { 
        while ( a[i]!=0 && m>0 ) { 
            printf("%d", i); 
            a[i]--; 
            m--; 
        } 
    } 
    printf("\n"); 
    return 0; 
}  