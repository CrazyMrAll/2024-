/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

class Joseph
{
	private:
		struct node {
			int data;
			node * next;

			node(int d, node *n=NULL) : data(d), next(n) {	}
		};
		node * head;
	public:
		Joseph(int n);			//构造函数
		void simulate(int m);	//对约瑟夫环中的结点进行计数，以m为步长将结点依次出环 
		~Joseph();				//析构函数
};

Joseph::Joseph(int n)		//构造函数
{
	node *tail;
	//建立链表
	head = tail = new node(0);		//创建第一个结点，head指向表头，tail指向表尾
	for ( int i=1; i<n; ++i ) {
		tail->next = new node(i);
		tail = tail->next;
	}
	tail->next = head;				//头尾相连
	head = tail;					//head指向第一个数据结点“0”的前一个 
}

Joseph::~Joseph()
{
	node *p;
	if (head==NULL) return;
	while (head->next!=head) {
		p = head->next;
		head->next = p->next;
		delete p;
	}
	delete head;
}

int main()
{	int n, m;	//n个 

	cin >> n >> m;
	Joseph h(n);
	h.simulate(m);
	return 0;
}

void Joseph::simulate(int m)
{
    node *tail = head;
    head = head->next;
    for ( int i=1; head->data!=0; i++ ) {
        head->data = i;
        tail = head;
        head = head->next;
    }
    while ( 1 ) {
        for ( int i=0; i<m-1; i++ ) {
            tail = head;
            head = head->next;
        }
        printf("%d", head->data);
        if ( head->next==head ) {printf("\n");break;} 
        else printf(",");
        node *p = head;
        head = head->next; 
        tail->next = head;
        delete p;
    } 
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */