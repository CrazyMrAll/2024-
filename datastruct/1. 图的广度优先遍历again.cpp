#include <iostream>
#include <queue>
using namespace std;

struct list {
    int n;
    list *next = NULL;
};

int main()
{
    int cnt = 0;
    char ch, head[50];
    while (scanf("%c", &ch) && ch != '*') {
        head[cnt++] = ch;
        getchar();
    } 
    list *table[cnt];
    for (register int i = 0; i < cnt; i++) 
        table[i] = new list;
    int a, b; 
    list *tmp, *tp;
    while (scanf("%d,%d", &a, &b) && a != -1 && b != -1) {
        tmp = table[a];
        while (tmp->next && tmp->next->n > b) tmp = tmp->next;
        tp = tmp->next;
        tmp->next = new list;
        tmp->next->n = b;
        tmp->next->next = tp;

        tmp = table[b];
        while (tmp->next && tmp->next->n > a) tmp = tmp->next;
        tp = tmp->next;
        tmp->next = new list;
        tmp->next->n = a;
        tmp->next->next = tp;
    }   
    printf("the ALGraph is\n");
    for (register int i = 0; i < cnt; i++) {
        printf("%c", head[i]);
        tmp = table[i];
        while (tmp->next) {
            tmp = tmp->next;
            printf(" %d", tmp->n);
        }
        printf("\n");
    }
    printf("the Breadth-First-Seacrh list:");
    bool vis[cnt];
    for (register int i = 0; i < cnt; i++)
        vis[i] = 0;
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    int t;
    for (register int i = 0; i < cnt; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            q.push(i);
        }
        while (!q.empty()) {
            t = q.front();
            printf("%c", head[t]);
            q.pop();
            tmp = table[t];
            while (tmp->next) {
                tmp = tmp->next;
                if (!vis[tmp->n]) {
                    q.push(tmp->n);
                    vis[tmp->n] = 1;
                }
            }
        }
    }
    printf("\n");
    return 0;
}