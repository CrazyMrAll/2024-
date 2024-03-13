#include <iostream>
using namespace std;
const int MAXN = 2000005;
int a[MAXN], cnt;

void Swap(int *a, int *b) {
    int t = *b;
    *b = *a;
    *a = t;
}

int Partition(int *a, int l, int r) {
    int p = a[r];
    // printf("p = %d\n", p);
    // printf("l = %d, r = %d\n", l, r);
    if (r-1 == l) {
        if (a[l] > a[r]) Swap(&a[l], &a[r]);
        return l;
    } else {
        int i = l, j = r-1;
        while (i < j) {
            while (a[i] < p) i++;
            while (a[j] > p) j--;
            if (i < j) Swap(&a[i], &a[j]);
        }
        Swap(&a[i], &a[r]);
        // printf("i = %d, j = %d\n", i, j);
        // for (register int j = 0; j < cnt; j++)
        //     printf("%d\n", a[j]);
        return i;
    }
}

int Select(int *a, int l, int r, int k) {
    int pi = Partition(a, l, r);
    int n = pi - l + 1;
    // printf("n = %d, k = %d\n", n, k);
    if (n == k) return a[pi];
    else if (k < n) return Select(a, l, pi-1, k);
    else return Select(a, pi+1, r, k-n);
}

int main()
{
    int x;
    while(scanf("%d,%d", &x, &a[cnt]) != EOF) cnt++;
    printf("%d\n", Select(a, 0, cnt-1, (cnt+1)/2));
    return 0;
}