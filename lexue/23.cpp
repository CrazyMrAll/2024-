#include <iostream>
using namespace std;

int main()
{
    int n, num, rate = 1;
    while ( cin>>n && n!=0 ) {
        rate = 1;
        while ( n>1 ) {
            n--;
            rate *= 2;
        }
        num += rate;
    }
    printf("%d\n", num);
    return 0;
}