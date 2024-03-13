#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

typedef struct node* AVLTree;
typedef struct node
{
    char ch;
    AVLTree Left, Right;
} Node;
typedef struct treemap
{
    char ch;
    int depth;
} Tnode;

queue<char> PreOrder;
queue<char> InOrder;
queue<char> PostOrder;
stack<Tnode> s;

int max(int a, int b) {
    return a>b ? a : b;
}

int GetHeight(AVLTree root) {
    if (!root) return 0;
    else return max(GetHeight(root->Left), GetHeight(root->Right)) + 1;
}

AVLTree Adjust(AVLTree root) {
    int h = GetHeight(root->Left) - GetHeight(root->Right);
    if (abs(h) <= 1) return root;
    else {
        // cout << "Nodenow = " << root->data << endl;
        if (h > 0) {
            AVLTree t = root->Left;
            int H = GetHeight(t->Left) - GetHeight(t->Right);
            if (H > 0) { //LL旋转
                root->Left = t->Right;
                t->Right = root;
                return t;
            } else { //LR旋转
                AVLTree T = t->Right;
                t->Right = T->Left;
                root->Left = T->Right;
                T->Left = t;
                T->Right = root;
                return T;
            }
        } else {
            AVLTree t = root->Right;
            int H = GetHeight(t->Left) - GetHeight(t->Right);
            if (H > 0) { //RL旋转
                AVLTree T = t->Left;
                t->Left = T->Right;
                root->Right = T->Left;
                T->Left = root;
                T->Right = t;
                return T;
            } else { //RR旋转
                root->Right = t->Left;
                t->Left = root;
                return t;
            } 
        }
    }
}

AVLTree Insert(AVLTree root, int X) {
    if (!root) {
        root = (AVLTree)malloc(sizeof (struct node));
        root->ch = X;
        root->Left = root->Right = NULL;
    } else {
        if (X < root->ch) root->Left = Insert(root->Left, X);
        else if (root->ch < X) root->Right = Insert(root->Right, X); 
        root = Adjust(root);
    }
    return root;
}

void Order(Node* t, int depth) {
    PreOrder.push(t->ch);
    if (t->Left) Order(t->Left, depth+1);
    InOrder.push(t->ch);
    {
        Tnode tnode;
        tnode.ch = t->ch;
        tnode.depth = depth;
        s.push(tnode);
    }
    if (t->Right) Order(t->Right, depth+1);
    PostOrder.push(t->ch);
}

int main()
{
    char tch;
    AVLTree root = NULL;
    while (scanf("%c", &tch) && tch != '\n') 
        root = Insert(root, tch);
    Order(root, 0);
    printf("Preorder: ");
    while (!PreOrder.empty()) {
        printf("%c", PreOrder.front());
        PreOrder.pop();
    }
    printf("\nInorder: ");
    while (!InOrder.empty()) {
        printf("%c", InOrder.front());
        InOrder.pop();
    }
    printf("\nPostorder: ");
    while (!PostOrder.empty()) {
        printf("%c", PostOrder.front());
        PostOrder.pop();
    }
    printf("\nTree:\n");
    Tnode tmp;
    while (!s.empty()) {
        tmp = s.top();
        s.pop();
        for (register int i = 0; i < tmp.depth; i++)
            printf("    ");
        printf("%c\n", tmp.ch);
    }
    return 0;
}