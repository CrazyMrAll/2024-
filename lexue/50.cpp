#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int num):data(num), next(nullptr){};
    Node():data(0), next(nullptr){};
};

class List
{
    private:
        Node *head = new Node;
    public:
        void List_insert(int num);
        void List_output();
        ~List();
};

void List::List_insert(int num) {
    Node *p = head;
    while ( p->next!=NULL ) {
        Node *tail = p;
        p = p->next;
        if ( num==p->data ) return;
        else if ( num<p->data ) {
            Node *tmp = new Node(num);
            tail->next = tmp;
            tmp->next = p;
            return;
        }
    }
    p->next = new Node(num);
}

void List::List_output() {
    Node *p = head;
    while ( p->next!=NULL ) {
        p = p->next;
        cout << p->data << endl;
    }
}

List::~List() {
    Node *p = head;
    while ( p!=NULL ) {
        Node *tail = p->next;
        delete p;
        p = tail;
    }
};

int main()
{
    int num;
    List list;
    while ( cin>>num && num!=0 ) list.List_insert(num);
    list.List_output();
}