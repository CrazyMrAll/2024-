#include <iostream>
#include <cstring>
using namespace std;
struct Node
{
    char name[21];
    Node *next = NULL;
};
char s1[7] = "Arrive";
char s2[6] = "Leave";
char s3[10] = "QueueHead";
char s4[10] = "QueueTail";
char s5[12] = "Empty queue";

int main()
{
    int n;
    scanf("%d", &n);
    Node *h, *t;
    h = t = NULL;
    char tmp[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        if (!strcmp(tmp, s1)) {
            Node *tp = new Node;
            scanf("%s", tp->name);
            if (t) t->next = tp;
            t = tp;
            if (!h) h = tp;
            // printf("h = %s\n", h->name);
            // printf("t = %s\n\n", t->name);
        } else if(!strcmp(tmp, s2)) {
            Node *tp = h;
            if (h) h = h->next;//之前漏写if(h)
            if (tp == t) t = NULL;
            delete tp;//若不写上一行 t仍可以访问
            // printf("h = %s\n", h->name);
            // printf("tp = %s\n", tp->name);
            // printf("t = %s\n\n", t->name);
        } else if(!strcmp(tmp, s3)) {
            if (h) printf("%s\n", h->name);
            else printf("%s\n", s5);
        } else if(!strcmp(tmp, s4)) {
            if (t) printf("%s\n", t->name);
            else printf("%s\n", s5);
        }
    }
    return 0;
}