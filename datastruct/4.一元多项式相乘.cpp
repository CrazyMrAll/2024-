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
    NODE *t = h2, *t3;
    int n, e;
    while (h1->next) {
        h1 = h1->next;
        // printf("h1now<%d,%d>\n", h1->coef, h1->exp);
        t = h2;
        while (t->next) {
            t = t->next;
            // printf("h2now<%d,%d>\n", t->coef, t->exp);
            n = h1->coef * t->coef;
            e = h1->exp + t->exp;
            // printf("multinow<%d,%d>\n", n, e);
            if (n) {
                t3 = h3;
                int flag = 1;
                if (t3->next) {
                    while (e >= t3->next->exp) {
                        // t3 = t3->next;
                        // printf("h3now<%d,%d>\n", t3->coef, t3->exp);
                        if (e == t3->next->exp) {
                            // printf("adjust<%d,%d>\n", t3->coef+n, e);
                            t3->next->coef += n;
                            flag = 0;
                            if (!t3->next->coef) {
                                NODE *tmp = t3->next;
                                t3->next = t3->next->next;
                                free(tmp);
                            }
                            break;
                        } else if (e < t3->next->exp) {
                            break;
                        }
                        t3 = t3->next;
                        if (!t3->next) break;
                    }
                }
                if (flag) {
                    // printf("new<%d,%d>\n", n, e);
                    NODE *tp = ( NODE * ) malloc( sizeof(NODE) );
                    tp->coef = n;
                    tp->exp = e;
                    tp->next = t3->next;
                    t3->next = tp;
                }
            }
        }
    }
    if (!h3->next) {
        t = ( NODE * ) malloc( sizeof(NODE) );
        t->coef = t->exp = 0;
        t->next = NULL;
        h3->next = t;
    }
}