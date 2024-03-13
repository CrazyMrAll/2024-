#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int MAXN = 200005;
struct dd
{
    int x, y;
}dragon[MAXN];

int cmp(const void* a, const void* b) {
    struct dd *c = (struct dd *)a;
    struct dd *d = (struct dd *)b;
    if (c->y < 0 && d->y < 0) return (d->x+d->y) - (c->x+c->y);
    else if (c->y < 0 && d->y > 0) return 1;
    else if (d->y < 0 && c->y > 0) return -1;
    else return c->x - d->x;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &dragon[i].x, &dragon[i].y);
    qsort(dragon, n, sizeof(dragon[0]), cmp);
    long long money = 0, A = 0;
    for (int i = 0; i < n; i++) {
        if (A >= dragon[i].x) A += dragon[i].y;
        else {
            money += dragon[i].x - A;
            A = (long long)dragon[i].x + dragon[i].y;
        }
    }
    // for (int i = 0; i < n; i++)
    //     printf("%d %d\n", dragon[i].x, dragon[i].y);
    printf("%lld\n", money);
    return 0;
}