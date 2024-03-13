/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;

void output( NODE * );
void change( int, int, NODE * );

void output( NODE * head )
{   int k=0;

	printf("0.");
	while ( head->next != NULL && k<50 )
	{   printf("%d", head->next->data );
		head = head->next;
		k ++;
	}
	printf("\n");
}

int main()
{   int n, m;
	NODE * head;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;
	change( n, m, head );
	output( head );
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void change (int n, int m, NODE *head) {
    NODE * t = head;
    NODE *num = (NODE *)malloc( sizeof(NODE) );
    num->data = -1;
    num->next = NULL;
    int now = 0, next = n;
    while (1) {
        now = next*10 / m;
        next = next*10 %m;
        // printf("now = %d, next = %d\n", now, next);
        bool flag = 0;
        NODE *p = num, *tp = t;
        while (p->next) {
            if (p->next->data == next && tp->next->data == now) {
                flag = 1;
                break;
            }
            p = p->next;
            tp = tp->next;
        }
        if (flag) {
            head->next = tp->next;
            break;
        } else {
            p->next = (NODE *)malloc( sizeof(NODE) );
            p = p->next;
            p->data = next;
            p->next = NULL;
            head->next = (NODE *)malloc( sizeof(NODE) );
            head = head->next;
            head->data = now;
            if (!next) {
                head->next = NULL;
                break;
            }
        }
    } 
}