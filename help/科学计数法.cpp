#include <stdio.h>

int main()
{
    char num[50], ans[50];
    char a;
    int hexd;
    bool flag = 0;
    scanf("%s %c %d", num, a, hexd);
    if ( hexd)
    printf("%s %c %d\n", ans, a, hexd);
    return 0;
}
