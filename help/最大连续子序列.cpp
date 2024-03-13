#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a>b) ? a : b;
}

int main() {
    int a[1000], b[1000] = {0}, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    b[0] = a[0];
    for (int i = 1; i < n; i++)
        b[i] = max(b[i], a[i]+b[i-1]);
    int max = b[0];
    for (int i = 1; i < n; i++)
        if (max < b[i]) max = b[i];
    printf("%d",max);
    return 0;
}