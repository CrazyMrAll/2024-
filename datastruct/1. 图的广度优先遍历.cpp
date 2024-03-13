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
        table[i] = NULL;
    int a, b; 
    list *tmp;
    while (scanf("%d,%d", &a, &b) && a != -1 && b != -1) {
        tmp = new list;
        tmp->n = b;
        tmp->next = table[a];
        table[a] = tmp;
        tmp = new list;
        tmp->n = a;
        tmp->next = table[b];
        table[b] = tmp;
    }   
    printf("the ALGraph is\n");
    for (register int i = 0; i < cnt; i++) {
        printf("%c", head[i]);
        tmp = table[i];
        while (tmp) {
            printf(" %d", tmp->n);
            tmp = tmp->next;
        }
        printf("\n");
    }
    printf("the Breadth-First-Seacrh list:");
    bool vis[cnt];
    for (register int i = 0; i < cnt; i++)
        vis[i] = 0;
    vis[0] = 1;
    priority_queue<int> q;
    q.push(0);
    int t;
    while (!q.empty()) {
        t = q.top();
        printf("%c", head[t]);
        q.pop();
        tmp = table[t];
        while (tmp) {
            if (!vis[tmp->n]) {
                q.push(tmp->n);
                vis[tmp->n] = 1;
            }
            tmp = tmp->next;
        }
    }
    printf("\n");
    return 0;
}