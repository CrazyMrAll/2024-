#include <iostream>
using namespace std;

struct node {
    int num, e;
    node* next;
};

typedef struct {
    node* head = new node;
}polynomial;


polynomial& CreatePolyn(polynomial &P, int m) {
    node *t = P.head;
    for (register int i = 0; i < m; i++) {
        t->next = new node;
        t = t->next;
        t->next = NULL;
        scanf("%d%d", &t->num, &t->e);
    }
    return P;
}

void PrintPolyn(polynomial P) {
    bool flag = 0;
    while (1) {
        P.head = P.head->next;
        if (P.head) {
            if (P.head->num) printf("<%d,%d>", P.head->num, P.head->e);
            else flag = 1;
        } else flag = 1;
        if (P.head->next && !flag) printf(",");
        else {
            if (flag) printf("<0,0>");
            printf("\n");
            break;
        }
    }
}

polynomial& AddPolyn(polynomial &Pa, polynomial Pb) {
    node *ta = Pa.head, *tb = Pb.head, *t;
    while (tb->next) {
        tb = tb->next;
        t = ta;
        while (t->next) {
            t = t->next;
            if (tb->e >= t->e) {
                if (t->e == tb->e) {
                    t->num += tb->num;
                    break;
                } else if (t->next) {
                    if (tb->e < t->next->e) {
                        node *tmp = new node;
                        tmp->e = tb->e;
                        tmp->num = tb->num;
                        tmp->next = t->next;
                        t->next = tmp;
                        break;
                    }
                } else {
                    node *tmp = new node;
                    tmp->e = tb->e;
                    tmp->num = tb->num;
                    tmp->next = t->next;
                    t->next = tmp;
                    break;
                }
            } 
        }
    }
    return Pa;
}

int main()
{
    int flag;
    scanf("%d", &flag);
    if (flag) {
        int m;
        polynomial A, B, C;
        scanf("%d", &m);
        A = CreatePolyn(A, m);
        scanf("%d", &m);
        B = CreatePolyn(B, m);
        scanf("%d", &m);
        C = CreatePolyn(C, m);
        PrintPolyn(A);
        PrintPolyn(B);
        PrintPolyn(C);
        A = AddPolyn(A, B);
        PrintPolyn(A);
        C = AddPolyn(C, A);
        PrintPolyn(C);
    }
    return 0;
}