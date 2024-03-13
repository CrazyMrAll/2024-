#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next = NULL;
    node* before = NULL;
};

int main()
{
    int n, k, m;
    scanf("%d,%d,%d", &n, &k, &m);
    if (!n || !k || !m) {
        printf("n,m,k must bigger than 0.\n");
    } else if (k > n) {
        printf("k should not bigger than n.\n");
    } else {
        node* head = new node;
        node* t = head;
        for (register int i = 1; i < n; i++) {
            head->data = i;
            head->next = new node;
            head->next->before = head;
            head = head->next;
        }
        head->data = n;
        head->next = t;
        t->before = head;
        node* t2;
        for (register int i = 0; i < k; i++)
            head = head->next;
        t2 = t = head;
        int cnt = n;
        while (1) {
            // printf("now = %d\n", t->data);
            for (register int i = 0; i < m-1; i++) {
                t = t->next;
                t2 = t2->before; 
            }
            if (t2->data == t->data) {
                printf("%d,", t->data);
            } else {
                printf("%d-%d,", t->data, t2->data);
                t2->before->next = t2->next;
                t2->next->before = t2->before;
                delete t2;
                cnt--;
            }
            t->before->next = t->next;
            t->next->before = t->before;
            delete t; 
            cnt--;
            // {
            //     node* t = head;
            //     cout << endl;
            //     while (1) {
            //         cout << head->data << " ";
            //         head = head->next;
            //         if (head == t) break;
            //     }
            //     cout << endl;
            // } 
            if (cnt) {
               t2 = t2->before;
                t = t->next; 
            } else break;
        }
        printf("\n");
    }
    return 0;
}