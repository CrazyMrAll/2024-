#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 50;
char InOrder[MAXN];
char PostOrder[MAXN];
int len;
int l[MAXN];
int r[MAXN];
queue<int> q;

int Build(int li, int ri, int Ini) {
    // printf("li = %d, ri = %d, Ini = %d\n", li, ri, Ini);
    if (li == ri) return li;
    else if (li > ri) return 0;
    else {
        int llen = 0;
        for (register int i = Ini; InOrder[i-1] != PostOrder[ri-1]; i++)
            llen++;
        l[ri] = Build(li, li+llen-1, Ini);
        // printf("%c's left is %c\n", PostOrder[ri-1], PostOrder[l[ri]-1]);
        r[ri] = Build(li+llen, ri-1, Ini+llen+1);
        // printf("%c's right is %c\n", PostOrder[ri-1], PostOrder[r[ri]-1]);
    }
    return ri;
}

int main()
{
    scanf("%s", InOrder);
    scanf("%s", PostOrder);
    for (register int i = 0; InOrder[i] != '\0'; i++)
        len++;
    q.push(Build(1, len, 1));
    int t;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        printf("%c", PostOrder[t-1]);
        if (l[t]) q.push(l[t]);
        if (r[t]) q.push(r[t]);
    }
    printf("\n");
    return 0;
}