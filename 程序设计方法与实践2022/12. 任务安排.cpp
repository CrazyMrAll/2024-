#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 300005;
int n;
typedef struct timetable {
    int begin;
    int end;
} Timetable;
Timetable timetable[MAXN];

int cmp(const void *a , const void *b)
{
    struct timetable *c = (Timetable *)a;
    struct timetable *e = (Timetable *)b;
    return c->end == e->end ? c->begin - e->begin : c->end - e->end;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &timetable[i].begin, &timetable[i].end);
    qsort(timetable, n, sizeof(timetable[0]), cmp);
    // for (int i = 0; i < n; i++)
    //     printf("%d %d\n", timetable[i].begin, timetable[i].end);
    int t = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (timetable[i].begin >= t) {
            t = timetable[i].end;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}