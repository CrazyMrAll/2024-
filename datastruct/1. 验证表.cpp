#include <iostream>
#include <string.h>
using namespace std;
struct node
{
    int n;
    char name[20];
    node* next;
};


int main()
{
    int n;
    scanf("%d", &n);
    node* head = new node;
    node* t = head;
    for (register int i = 0; i < n; i++) {
        head->next = new node;
        head = head->next;
        scanf("%d %s", &head->n, head->name);
        head->next = NULL;
    }
    scanf("%d", &n);
    if (n) {
        int num;
        char name[20];
        bool flag = 1;
        node* tp;
        for (register int i = 0; i < n; i++) {
            scanf("%d %s", &num, name);
            tp = t;
            bool tmp = 1;
            while (tp->next) {
                if (tp->next->n == num) {
                    if (strcmp(name, tp->next->name)) {
                        printf("%d %s is not in LIST1.\n", num, name);
                        flag = 0;
                    }
                    tmp = 0;
                    break;
                }
                tp = tp->next;
            }
            if (tmp) {
                flag = 0;
                printf("%d %s is not in LIST1.\n", num, name);
            }
        } 
        if (flag) printf("the records of LIST2 are all in the LIST1.\n");
    } else printf("the LIST2 is NULL.\n");
        
    return 0;
}