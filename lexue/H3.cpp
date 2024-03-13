// 麻了，真的整不会。
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 30

int main()
{
    int a, b, flag;
    char a[MAXN] = {0}, b[MAXN] = {0};
    unsigned long long u1, u2;
    flag = u1 = u2 = 1;
    scanf("%d %d", &a, &b);
    if ( ((b-a)<3 && a==1) || ((b-a)<2 && a!=1))
        printf("1\n");
    else {
        for ( int i=0; i<b-a; i++ ) {
            u2 += u1;
            i++;
            if ( i>=b-a ) {
                flag = 2;
                break;
            }
            u1 += u2;
        }
        printf("%lld\n",((flag==2) ? u1 : u2));
    }
    return 0;
}