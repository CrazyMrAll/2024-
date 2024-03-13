/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

struct node
{	int  data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

void outlist( PNODE );
int ins_list( PNODE, int );
 
int main( )
{  	int num=1;
	PNODE head;

	head = new NODE;
	head->next = NULL;
	head->data = -1;

	while ( num!=0 )
	{  	cin >> num;
		if ( num!=0 )
			ins_list( head, num);
	}

	outlist( head );
	return 0;
}

void outlist( PNODE head )
{	PNODE p;
	p = head->next;
	while ( p != NULL )
	{	cout << p->data << endl;
		p = p->next;
	}
}

// This is an example for list. Please programme your code like it.

int ins_list( PNODE h, int num )
{
    while ( h->next!=NULL ) {
		h = h->next;
	}
    PNODE p = h->next = new NODE;
	p->data = num;
	p->next = NULL;
    h->next = p;
    return num;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */