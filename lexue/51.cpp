/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

typedef int ElemType; 
class List
{
	private:
		typedef struct node {
			ElemType data;
			struct node* next;
			node() {
				data = -1;
				next = NULL;
			}
			node(int x, struct node* pnext) {
				data = x;
				next = pnext;
			}
		} node;
		node * head;
	public:
		List() {
			head = new node;
		}
		~List() {
			MakeEmpty();
		}
		void insert(const ElemType x); 	//将元素x插入到L的头部 
		void input( const ElemType flag);
		void output();
		void sort();
		void MakeEmpty();
};

void List::MakeEmpty()
{
	node *p;
	while ( head->next != NULL ) {
		p = head->next;
		head->next= p->next;
		delete p;
	}
}

void List::insert(const ElemType x) 	//将元素x插入到链表的头部 
{
	node * p = new node;
	p->data = x;
	p->next = head->next;
	head->next = p;
}

void List::input( const ElemType flag)	//flag：数据结束标记
{
	ElemType tmp;
	cin >> tmp;
	while ( tmp != flag ) {
		insert (tmp );
		cin >> tmp;
	}
}

int main()
{
	List L;
	L.input(0);
	L.sort();
	L.output();
	return 0;
}

void List::output()
{
	node *p = head->next;;
	while ( p->next!= NULL ) {
		cout << p->data << ",";
		p = p->next;
	}
	cout << p->data << endl;
}
void List::sort()
{
	bool flag = 1;
	while (flag) {
		flag = 0;
		node *ahead = head;
		node *middle = ahead->next;
		node *behind = middle->next;
		while ( behind!=NULL ) {
			if ( middle->data>behind->data ) {
				ahead->next = behind;
				middle->next = behind->next;
				behind->next = middle;
				flag = 1;
			}
			ahead = ahead->next;
			middle = ahead->next;
			behind = middle->next;
		}
	}
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */