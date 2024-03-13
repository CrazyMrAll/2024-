/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node() {
		data = -1;
		next = NULL;
	}
	Node(int x, Node *p=NULL) {
		data = x;
		next = p;
	}
};

class List
{
	protected:
		Node * first;
	public:
		List() {
			first = new Node;
		}
		~List() {
			makeEmpty();
		}
		void makeEmpty();
		void insert();
		void output();
		void split(List& A, List& B);
};

void List::makeEmpty()
{
	Node * del;
	while ( first->next != NULL ) {
		del = first->next;
		first->next = del->next;
		delete del;
	}
}

void List::insert()
{
	int num;
	Node *last = first;
	cin >> num;
	while ( num != -1 ) {
		last->next = new Node( num );
		last = last->next;
		cin >> num;
	}
	last->next = NULL;
}

void List::output()
{
	Node *p = first->next;
	while ( p!=NULL ) {
		cout << p->data << ",";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	List L, A, B;
	L.insert();
	cout << "L="; L.output();
	L.split(A, B);
	cout << "A="; A.output();
	cout << "B="; B.output();
	cout << "L="; L.output();
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void List::split(List& A, List& B) {
    Node *p = first->next;
    Node *pa = A.first;
    Node *pb = B.first;
	while ( p!=NULL ) {
        int t = p->data;
		if ( t%2 ) {
            pa->next = new Node( t );
		    pa = pa->next;
        } else {
            pb->next = new Node( t );
		    pb = pb->next;
        }
        p = p->next;
	}
}