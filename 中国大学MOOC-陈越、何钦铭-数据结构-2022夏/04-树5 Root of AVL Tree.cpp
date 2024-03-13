#include <iostream>
#include <math.h>
using namespace std;

typedef struct node* AVLTree;
typedef struct node
{
    int data;
    AVLTree Left, Right;
} Node;

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
        root->data = X;
        root->Left = root->Right = NULL;
    } else {
        if (X < root->data) root->Left = Insert(root->Left, X);
        else if (root->data < X) root->Right = Insert(root->Right, X); 
        root = Adjust(root);
    }
    return root;
}

int main()
{ 
    int n;
    cin >> n;
    AVLTree AVLT = NULL;
    for (int i = 0; i < n; i++) {
        int X;
        cin >> X;
        AVLT = Insert(AVLT, X);
    }
    cout << AVLT->data;
    return 0;
}