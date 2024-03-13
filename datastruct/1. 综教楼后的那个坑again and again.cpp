#include <iostream>
using namespace std;
const int MAXN = 100005;

struct node
{
    unsigned long long int w, h;
    int order;
    node *next, *before;
};

int main()
{
    int n;
    unsigned long long int ans[MAXN], tnow = 0;
    node* head = new node;
    node *deepest = new node;
    deepest->h = 10 * MAXN;
    node* t = head;
    scanf("%d", &n);
    for (register int i = 0; i < n; i++) {
        t->next = new node;
        t->next->before = t;
        t = t->next;
        t->order = i;
        scanf("%lld%lld", &t->w, &t->h);
        if (t->h < deepest->h) deepest = t;
    }
    head->before = t;
    t->next = head;
    head->h = 10 * MAXN;
    head->w = 0;
    bool flag;
    node *tmpnext, *tmpbefore;
    t = deepest;
    while(head->next != head) {
        while(t->h > t->before->h)
            t = t->before;
        while(t->h > t->next->h)
            t = t->next;
        // printf("height = %d, wide = %d\n", t->h, t->w);
        flag = 0;
        if (t->before->h > t->next->h) flag = 1;
        ans[t->order] = tnow + t->w;
        if (flag) {
            tnow += t->w * (t->next->h - t->h);
            t->next->w += t->w;
        } else {
            tnow += t->w * (t->before->h - t->h);
            t->before->w += t->w; 
        }
        tmpnext = t->next;
        tmpbefore = t->before;
        t->before->next = tmpnext;
        t->next->before = tmpbefore;
        delete t;
        if (flag) t = tmpnext;
        else t = tmpbefore;
    }
    delete head;
    for (register int i = 0; i < n; i++) 
        printf("%lld\n", ans[i]);
    return 0;
}