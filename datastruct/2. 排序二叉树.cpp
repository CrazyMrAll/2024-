#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 100000;
int node[MAXN];
queue<int> q;

typedef struct node
{
    int date = 0;
    node *left = NULL;
    node *right = NULL;
}Node;

Node* Insert(int X, Node *root) {
    if (!root) {
        root = new Node;
        root->date = X;
    }
    else if (X > root->date) root->right = Insert(X, root->right);
    else root->left = Insert(X, root->left);
    return root;
}

void Order(Node* t, int depth) {
    if (t->left) Order(t->left, depth+1);
    for (register int i = 0; i < depth; i++)
        printf("    ");
    printf("%d\n", t->date);
    q.push(t->date);
    if (t->right) Order(t->right, depth+1);
}

int main()
{
    int t;
    Node *root = NULL;
    for (register int i = 1; ; i++) {
        scanf("%d", &t);
        if (t) root = Insert(t, root);
        else break;
    }
    if (root) {
        Order(root, 0);
        printf("\n");
    }
    while (!q.empty()) {
        printf(" %d", q.front());
        q.pop();
    }
    if (root) printf("\n");
    return 0;
}