#include <iostream>
using namespace std;
int n;

void inline Print(int *t, int size) {
    for (register int i = 1; i <= size; i++)
        printf("%d ", t[i]);
    printf("\n");
}

void inline Down(int *t, int i) {
    int tmp, child;
    for (tmp = t[i]; 2*i <= n; i = child) {
        child = 2*i;
        if (child < n && t[child] < t[child+1])
            child++;
        if (tmp < t[child])
            t[i] = t[child];
        else break;
    }
    t[i] = tmp;
}

void Build(int *t, int size) {
    for (register int i = size/2; i > 0; i--) 
        Down(t, i);
}

void Delete(int *t, int size) {
    int tmp = t[1];
    t[1] = t[size];
    t[size] = tmp;
    n--;
    Down(t, 1);
}

int main()
{
    scanf("%d", &n);
    int num[n+1];
    for (register int i = 1; i <= n; i++) 
        scanf("%d", &num[i]);
    Build(num, n);
    Print(num, n);
    Delete(num, n);
    Print(num, n);
    Delete(num, n);
    Print(num, n);
    return 0;
}