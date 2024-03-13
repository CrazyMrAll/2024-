#include <iostream>
using namespace std;

void min (double b[], int n) {
    double min = b[0];
    for ( int i=0; i<n-2; i++ ) {
        if ( min > b[i+1] ) min=b[i+1];
    }
    for ( int i=0; i<n-1; i++ ) {
        if ( min == b[i] ) printf("%d,", i+1);
    }
    printf("\n");
}

int main()
{
    int n, m;
    double total;
    scanf("%d %d %lf", &n, &m, &total);
    double b[n-1];
    for ( int i=0; i<n-1; i++ ) {
        int on, off;
        scanf("%d %d", &on, &off);
        total = total + on - off;
        b[i] = total / m;
    }
    for ( int i=0; i<n-1; i++ ) printf("%.3lf\n", b[i]);
    min(b, n);
    return 0;
}