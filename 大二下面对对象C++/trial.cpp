#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
struct Node* creatlist()
{
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}
struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insert(struct Node* head,int data) {
    struct Node* newNode = creatNode(data);
    for (; head->next; head = head->next);
    newNode->next = head->next;
    head->next = newNode;
}
void compare(struct Node* headNode1, struct Node* headNode2) {
    struct Node* p1 = headNode1->next;
    struct Node* p2 = headNode2->next;
    while (p1 != NULL) {
        while (p2 != NULL) {
            if (p1->data == p2->data) {
                cout <<p1->data << " ";
                break;
            }
            else {
                p2 = p2->next;
            }
        }
        p1 = p1->next;
        p2 = headNode2;
    }
}

int main() {
    struct Node* list1 = creatlist();
    struct Node* list2 = creatlist();
    int t;
    while (cin >> t) {
        if (cin.get()=='\n') break;
        else insert(list1, t);
       
    }
    while (cin >> t) {
        insert(list2, t);
    }
    compare(list1, list2);
    return 0;
}