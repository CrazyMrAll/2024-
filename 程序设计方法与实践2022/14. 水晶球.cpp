#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
struct size {
    int a, b, c, i;
} item[MAXN];

int cmp(const void* n, const void* m) {
    struct size *A = (struct size *)n;
    struct size *B = (struct size *)m;
    if (A->a != B->a) return B->a - A->a;
    else if (A->b != B->b) return B->b - A->b;
    else return B->c - A->c;
}

int main()
{
    int n;
    scanf("%d", &n);
    int tmp[3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &tmp[0], &tmp[1], &tmp[2]);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2-i; j++) {
                if (tmp[j] < tmp[j+1]) {
                    int t = tmp[j];
                    tmp[j] = tmp[j+1];
                    tmp[j+1] = t;
                }
            }
        }
        item[i].a = tmp[0], item[i].b = tmp[1], item[i].c = tmp[2], item[i].i = i;
    } 
    qsort(item, n, sizeof(item[0]), cmp);
    long long solomax = 0, doublemax = 0;
    int soloi = -1, maxi = -1, maxj = -1;
    // printf("\n");
    // for (int i = 0; i < n; i++)
    //     printf("%d %d %d\n", item[i].a, item[i].b, item[i].c);
    for (int i = 0; i < n; i++) {
        if (solomax < item[i].c) {
            solomax = item[i].c;
            soloi = item[i].i;
        }
        if (i < n-1) {
            if (item[i].a == item[i+1].a && item[i].b == item[i+1].b) {
                long long min, t;
                t = (long long)item[i].c + (long long)item[i+1].c;
                min = t<(long long)item[i].b ? t : (long long)item[i].b;
                if (doublemax < min) {
                    doublemax = min;
                    maxi = item[i].i;
                    maxj = item[i+1].i;
                }
            }
        }
    }
    // printf("%d\n", solomax);
    // printf("%d\n", doublemax);
    if (solomax >= doublemax) printf("1\n%d\n", soloi+1);
    else printf("2\n%d %d\n", (maxi<maxj ? maxi : maxj)+1, (maxi<maxj ? maxj : maxi)+1);
    return 0;
}