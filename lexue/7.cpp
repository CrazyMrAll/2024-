#include <iostream>
using namespace std;

int main()
{
    int n , m=1;
    scanf("%d", &n);
    if ( n==1 )
        printf("The monkey got 1 peach in the first day.\n");
    else {
        for ( int i=n-1; i>0; i-- ) {
            m += i;
            m *= 2;
        }
        printf("The monkey got %d peaches in the first day.\n", m);
    }
    return 0;
}