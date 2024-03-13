#include <iostream>
using namespace std;
const int MAXN = 100005;
struct Node
{
    int num;
    Node* next = NULL;
    Node(int t) {
        num = t;
    }
};
Node *p[MAXN];


int main()
{
    int n, m, x, y;
    int itemnum[MAXN];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        p[i] = new Node(i);
        itemnum[i] = 1;
    }   
    Node *t; 
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        itemnum[y] += itemnum[x];
        itemnum[x] = 0;
        while (p[x]) {
            t = p[y];
            p[y] = p[x];
            p[x] = p[x]->next;
            p[y]->next = t;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d", itemnum[i]);
        if (itemnum[i]) {
            while (p[i]) {
                printf(" %d", p[i]->num);
                p[i] = p[i]->next;
            }
        }
        printf("\n");
    }
    return 0;
}