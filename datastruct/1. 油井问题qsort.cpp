#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2000005;
int a[MAXN], cnt;

int main()
{
    int x;
    while(scanf("%d,%d", &x, &a[cnt]) != EOF) cnt++;
    sort(a, a+cnt);
    printf("%d\n", a[(cnt+1)/2-1]);
    return 0;
}