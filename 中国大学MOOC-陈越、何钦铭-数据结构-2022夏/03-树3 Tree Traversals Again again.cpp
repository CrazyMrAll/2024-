#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 30
int stack[MAXN], top = -1;
int PostOrder[MAXN];

typedef struct node {
    int left = -1, right = -1;
} Node;
Node node[31];

int Push(int t) {
    stack[++top] = t;
    return t;
}

int Pop() {
    int t = stack[top];
    stack[top--] = 0;
    return t;
}

int main()
{
    int n;
    cin >> n;
    char movement[5];
    int root, p;
    cin >> movement >> root;
    p = Push(root);
    //建树
    for (int i = 1; i < 2 * n; i++) {
        cin >> movement;
        if (!strcmp(movement, "Push")) {
            int t;
            cin >> t;
            if (node[root].left == -1) node[root].left = Push(t);
            else node[root].right = Push(t);
            root = t;
        } else root = Pop();
        // cout << " root=" << root << endl;
    }
    root = p;
    int post = n - 1;
    while (root != -1 || top != -1) {
        while (root != -1) {
            PostOrder[post--] = Push(root);
            root = node[root].right;
        } 
        if (top != -1) {
            root = Pop();
            root = node[root].left;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << node[i].left << " " << node[i].right << endl;
    // }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << PostOrder[i];
    }
    return 0;
}