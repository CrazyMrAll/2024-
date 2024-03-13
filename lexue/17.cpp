#include <iostream>
using namespace std;

void sort (int a[], int n) {
    for ( int i=1; i<n; i++ ) {
        int tmp = a[i];
        bool flag = 1;
        for ( int j=i-1; j>=0; j-- ) {
            if ( tmp < a[j] ) {
                a[j+1] = a[j];
                a[j] = tmp;
                flag = 0;
            } else break;
        } 
        if ( flag==0 )
            for ( int i=0; i<n; i++ ) {
                printf("%d", a[i]);
                ( i==n-1 ) ? printf("\n") : printf(" ");
            }
    }
    printf("Result: ");
    for ( int i=0; i<n; i++ ) {
        printf("%d", a[i]);
        ( i==n-1 ) ? printf("\n") : printf(" ");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for ( int i=0; i<n; i++ ) 
        scanf("%d", &a[i]);
    sort(a, n);
    return 0;
}