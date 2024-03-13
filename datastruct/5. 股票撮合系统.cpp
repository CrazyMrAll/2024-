#include <stdio.h>
#include <stdlib.h>

typedef struct stock
{
    int orderid;
    int stocknum;
    double price;
    int amount;
    char bs;
    struct stock* next = NULL;
} Stock, *List;
int cnt;
List sellfront = (List)malloc(sizeof(Stock));
List buyfront = (List)malloc(sizeof(Stock));

void inline apply() {
    cnt++;
    printf("orderid: %04d\n", cnt);
    List t = (List)malloc(sizeof(stock));
    scanf("%d %lf %d %c", &t->stocknum, &t->price, &t->amount, &t->bs);
    t->orderid = cnt;
    t->next = NULL;
    List p, s = sellfront, b = buyfront, tmp;
    if (t->bs == 'b') {
        // trade
        while (s->next) {
            if (t->stocknum == s->next->stocknum) {
                if (t->price >= s->next->price) {
                    if (t->amount <= s->next->amount) {
                        s->next->amount -= t->amount;
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", 
                            (t->price+s->next->price)/2, t->amount, t->orderid, s->next->orderid);
                        t->amount = 0;
                        if (!s->next->amount) {
                            tmp = s->next;
                            s->next = s->next->next;
                            free(tmp);
                        }
                        break;
                    } else {
                        t->amount -= s->next->amount;
                        printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", 
                            (t->price+s->next->price)/2, s->next->amount, t->orderid, s->next->orderid);
                        tmp = s->next;
                        s->next = s->next->next;
                        free(tmp);
                        continue;
                    }
                }
            }
            s = s->next;
        }
        // add
        if (t->amount) {
            p = buyfront;
            while (p->next) {
                if (p->next->price < t->price) {
                    t->next = p->next;
                    break;
                }
                p = p->next;
            }
            p->next = t;
        } else free(t);
    } else {
        // trade
        while (b->next) {
            if (t->stocknum == b->next->stocknum) {
                if (b->next->price >= t->price) {
                    if (b->next->amount <= t->amount) {
                        t->amount -= b->next->amount;
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", 
                            (b->next->price+t->price)/2, b->next->amount, t->orderid, b->next->orderid);
                        tmp = b->next;
                        b->next = b->next->next;
                        free(tmp);
                        if (!t->amount) break;
                        else continue;
                    } else {
                        b->next->amount -= t->amount;
                        printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", 
                            (b->next->price+t->price)/2, t->amount, t->orderid, b->next->orderid);
                            t->amount = 0;
                        break;
                    }
                }
            }
            b = b->next;
        }
        // add
        if (t->amount) {
            p = sellfront;
            while (p->next) {
                if (p->next->price > t->price) {
                    t->next = p->next;
                    break;
                }
                p = p->next;
            }
            p->next = t;
        } else free(t);
    }
}

void inline check() {
    List s = sellfront, b = buyfront;
    int tsn;
    scanf("%d", &tsn);
    printf("buy orders:\n");
    while (b->next) {
        b = b->next;
        if (b->stocknum == tsn) 
            printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", b->orderid, b->stocknum, b->price, b->amount, b->bs);
    }
    printf("sell orders:\n");
    while (s->next) {
        s = s->next;
        if (s->stocknum == tsn) 
            printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", s->orderid, s->stocknum, s->price, s->amount, s->bs);
    }
}

void inline disapply() {
    List s = sellfront, b = buyfront, t;
    int to;
    int flag = 1;
    scanf("%d", &to);
    while (b->next) {
        if (b->next->orderid == to) {
            flag = 0;
            t = b->next;
            printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", t->orderid, t->stocknum, t->price, t->amount, t->bs);
            b->next = b->next->next;
            free(t);
            break;
        } 
        b = b->next; 
    }
    while (s->next && flag) {
        if (s->next->orderid == to) {
            flag = 0;
            t = s->next;
            printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", t->orderid, t->stocknum, t->price, t->amount, t->bs);
            s->next = s->next->next;
            free(t);
            break;
        }  
        s = s->next;
    }
    if (flag) printf("not found\n");
}

int main()
{
    int operation;
    sellfront->next = buyfront->next = NULL;
    while (scanf("%d", &operation) && operation) {
        switch (operation) {
            case 1: apply(); break;
            case 2: check(); break;
            case 3: disapply(); break;
        }
    }
    return 0;
}