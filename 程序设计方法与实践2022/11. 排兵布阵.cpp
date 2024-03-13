#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
const int MAXN = 100005;
int n;

int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

// void heapsort(int *p) {
//     for (int i = 0; i < n-1; i++) {
//         for (int j = (n-i)/2-1; j >= 0; j--) {
//             if (2*j+2 <= n-1-i) {
//                 if (p[j] > p[2*j+2]) {
//                     int t = p[j];
//                     p[j] = p[2*j+2];
//                     p[2*j+2] = t; 
//                 }  
//             }
//             if (p[j] > p[2*j+1]) {
//                 int t = p[j];
//                 p[j] = p[2*j+1];
//                 p[2*j+1] = t; 
//             }
//         }
//         p++;
//     }
// }

int main()
{
    scanf("%d", &n);
    long long cnt = 0;
    int x[MAXN], y[MAXN];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);
    // heapsort(x);
    // heapsort(y);
    qsort(x, n, sizeof(x[0]), cmp);
    qsort(y, n, sizeof(y[0]), cmp);
    int midy = y[n/2];
    for (int i = 0; i < n; i++)
        cnt = cnt + abs(midy - y[i]);
    for (int i = 0; i < n; i++)
        x[i] = x[i] - i;
    // heapsort(x);
    qsort(x, n, sizeof(x[0]), cmp);
    int midx = x[n/2];
    for (int i = 0; i < n; i++)
        cnt = cnt + abs(midx - x[i]);
    printf("%lld\n", cnt);
    return 0;
}