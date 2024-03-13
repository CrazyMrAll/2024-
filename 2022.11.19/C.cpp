#include <iostream>
using namespace std;
const int MAXN = 200005;

struct block
{
    int a;
    block *next;
    block *end;
};
block *table[MAXN];
int order;

int update(block *now) {
    // printf("now = %d\n", now->a);
    if (now == now->next) {
        table[order]->end = now;
        return now->a;
    } else return now->a = update(now->next);
}

block *alterend(block *now) {
    if (now == now->next) {
        return now;
    } else return now->end = alterend(now->next);
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (register int i = 1; i <= n ; i++) {
        table[i] = new block;
        scanf("%d", &table[i]->a);
        table[i]->end = table[i]->next = table[i];
    }
    int choice, a, b;
    for (register int i= 0; i < q; i++) {
        scanf("%d%d%d", &choice, &a, &b);
        if (choice == 1) {
            table[a]->a = b;
        } else if (choice == 2) {
            table[a]->next = table[b];
            table[a]->end = alterend(table[a]);
            // table[a]->a = update(table[a]);
        } else {
            int ans = 0;
            for (register int j = a; j <= b; j++) {
                order = j;
                if (table[j]->a != table[j]->end->a)
                    table[j]->a = update(table[j]);
                ans += table[j]->a;
            } 
            // printf("\n");
            printf("%d\n", ans);
        }
    }
    return 0;
}