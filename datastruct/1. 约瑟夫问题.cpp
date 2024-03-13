#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next = NULL;
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
        long long i = 1;
        for (; i < n; i++) {
            head->data = i;
            head->next = new node;
            head = head->next;
        }
        head->data = i;
        head->next = t;
        // 与后面统一操作，只到前一个节点
        
        for (register int i = 0; i < k-1; i++)
            head = head->next;
        int cnt = 0;
        while (head->next != head) {
            // 这里只到前一个节点
            for (register int i = 0; i < m-1; i++)
                head = head->next;
            t = head;
            head = head->next;
            printf("%d", head->data);
            cnt++;
            if (!(cnt%10)) printf("\n");
            else printf(" ");
            t->next = head->next;
            delete head;
            head = t;
        }
        printf("%d\n", head->data);
        delete head;
    }
    return 0;
}