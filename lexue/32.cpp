#include <iostream>
using namespace std;

int divisor (int u, int d) {
    return u%d==0 ? d : divisor(d,u%d);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", divisor(a, b));
    return 0;
}