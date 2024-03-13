/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int    coef, exp;
    struct node  *next;
} NODE;

void multiplication( NODE *, NODE * , NODE * );
void input( NODE * );
void output( NODE * );

void input( NODE * head )
{   int flag, sign, sum, x;
	char c;

    NODE * p = head;

	while ( (c=getchar()) !='\n' )
	{
		if ( c == '<' )
	    {    sum = 0;
	         sign = 1;
	         flag = 1;
        }
		else if ( c =='-' )
             sign = -1;
		else if( c >='0'&& c <='9' )
		{    sum = sum*10 + c - '0';
        }
		else if ( c == ',' )
        {    if ( flag == 1 )
             {    x = sign * sum;
                  sum = 0;
                  flag = 2;
		  sign = 1;
             }
        }
		else if ( c == '>' )
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );
             p->next->coef = x;
             p->next->exp  = sign * sum;
             p = p->next;
             p->next = NULL;
             flag = 0;
        }
    }
}

void output( NODE * head )
{
    while ( head->next != NULL )
    {   head = head->next;
        printf("<%d,%d>,", head->coef, head->exp );
    }
    printf("\n");
}

int main()
{   NODE * head1, * head2, * head3;

    head1 = ( NODE * ) malloc( sizeof(NODE) );
    input( head1 );

    head2 = ( NODE * ) malloc( sizeof(NODE) );
    input( head2 );

    head3 = ( NODE * ) malloc( sizeof(NODE) );
    head3->next = NULL;
    multiplication( head1, head2, head3 );

	output( head3 );
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void multiplication( NODE *h1, NODE *h2, NODE *h3) {
    short n[490000];
    for (register int i = 0; i < 490000; i++)
        n[i] = 0;
    int tn, te, max = 0;
    NODE *t;
    NODE *tail = new node;
    tail->next = NULL;
    bool flag1 = 1;
    while (h1->next) {
        h1 = h1->next;
        t = h2;
        while (t->next) {
            t = t->next;
            tn = h1->coef * t->coef;
            te = h1->exp + t->exp;
            if (te >= 490000) {
                flag1 = 0;
                NODE *t3 = tail;
                bool flag2 = 1;
                if (t3->next) {
                    while (te >= t3->next->exp) {
                        // t3 = t3->next;
                        // printf("h3now<%d,%d>\n", t3->coef, t3->exp);
                        if (te == t3->next->exp) {
                            // printf("adjust<%d,%d>\n", t3->coef+n, e);
                            t3->next->coef += tn;
                            flag2 = 0;
                            if (!t3->next->coef) {
                                NODE *tmp = t3->next;
                                t3->next = t3->next->next;
                                free(tmp);
                            }
                            break;
                        } else if (te < t3->next->exp) {
                            break;
                        }
                        t3 = t3->next;
                        if (!t3->next) break;
                    }
                }
                if (flag2) {
                    // printf("new<%d,%d>\n", n, e);
                    NODE *tp = ( NODE * ) malloc( sizeof(NODE) );
                    tp->coef = tn;
                    tp->exp = te;
                    tp->next = t3->next;
                    t3->next = tp;
                }
            } else {
                n[te] += tn;
                // printf("new<%d,%d>\n", n[te], te);
                if (n[te]) {
                    if (max < te)
                        max = te;
                } 
            }
            
        }
    }
    // printf("max = %d\n", max);
    t = h3;
    for (register int i = 0; i <= max; i++) {
        if (n[i]) {
            h3->next = ( NODE * ) malloc( sizeof(NODE) );
            h3 = h3->next;
            h3->coef = n[i];
            h3->exp = i;
            h3->next = NULL;
            flag1 = 0;
        }
    }
    if (flag1) {
        h3->next = ( NODE * ) malloc( sizeof(NODE) );
        h3 = h3->next;
        h3->coef = h3->exp = 0;
        h3->next = NULL;
    }
    h3->next = tail->next;
    h3 = t;
}