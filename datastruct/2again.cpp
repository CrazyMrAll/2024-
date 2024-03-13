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
    int num[50];
    for (register int i = 1; i < 50; i++)
        num[i] = 0;
    NODE * t = head;
    int now = 0, next = n;
    while (1) {
        now = next*10 / m;
        next = next*10 %m;
        // printf("now = %d, next = %d\n", now, next);
        bool flag = 0;
        NODE *tp = t;
        int i;
        for (i = 0; i < 50; i++) {
            if (!num[i]) break;
            else if (num[i] == next && tp->data == now) {
                flag = 1;
                break;
            }
            tp = tp->next;
        }
        if (flag) {
            head->next = tp;
            // printf("head = %d, tp = %d\n", head->data, tp->data);
            break;
        } else {
            num[i] = next;
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