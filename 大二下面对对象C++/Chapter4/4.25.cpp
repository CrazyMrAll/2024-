#include <iostream>
using namespace std;

class Link
{
private:
    int cnt;
    Link *next;
public:
    Link* Make_Link(int length);
    void Print_Link();
};

Link* Link::Make_Link(int length) {
    next = new Link;
    next->cnt = 0;
    Link* p = next;
    for (register int i = 1; i <= length; i++) {
        p->next = new Link;
        p = p->next;
        p->cnt = i;
    }
    p->next = NULL;
    return next;
}

void Link::Print_Link() {
    Link* head = next;
    cout << "This is head pointer " << head->cnt;
    while(head->next) {
        head = head->next;
        cout << "->node " << head->cnt;
    }
    cout << endl;
}

int main()
{
    Link l;
    l.Make_Link(9);
    l.Print_Link();
    return 0;
}