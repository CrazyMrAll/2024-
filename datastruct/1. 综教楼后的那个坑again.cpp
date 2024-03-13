#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 100005;

struct node
{
    long long w, h;
    stack<int> order;
    node *next, *before;
};

int main()
{
    int n;
    long long ans[MAXN], tnow = 0, maxh = 0;
    node* head = new node;
    node* t = head;
    scanf("%d", &n);
    for (register int i = 0; i < n; i++) {
        t->next = new node;
        t->next->before = t;
        t = t->next;
        t->order.push(i);
        scanf("%lld%lld", &t->w, &t->h);
        if (maxh < t->h) maxh = t->h;
    }
    head->before = t;
    t->next = head;
    head->h = maxh + 2;
    head->w = 0;
    t = head->next;
    bool flag;
    node *tmpnext, *tmpbefore;
    while(head->next != head) {
        while(t->h > t->next->h) 
            t = t->next;
        if (t->h == t->next->h) {
            t->w += t->next->w;
            while (!t->next->order.empty()) {
                t->order.push(t->next->order.top());
                t->next->order.pop();
            }
            tmpnext = t->next;
            t->next = t->next->next;
            t->next->before = t;
            delete tmpnext;
        } else {
            if (t->before->h > t->next->h) flag = 1;
            while (!t->order.empty()) {
                ans[t->order.top()] = tnow + t->w;
                t->order.pop();
            }
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
    }
    delete head;
    for (register int i = 0; i < n; i++) 
        printf("%lld\n", ans[i]);
    return 0;
}