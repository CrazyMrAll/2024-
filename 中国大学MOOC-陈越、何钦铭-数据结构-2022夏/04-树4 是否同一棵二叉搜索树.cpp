#include <iostream>
using namespace std;
#define MAXN 10
typedef struct node {
    int l = -1, r = -1;
} Node;

void Insert(Node* node, int data, int root) {
    while (data != root) {
        if (data > root) {
            if (node[root].r == -1) node[root].r = data;
            root = node[root].r;
        } else {
            if (node[root].l == -1) node[root].l = data;
            root = node[root].l;
        }
    }
}

void Build(Node* node, int n) {
    int root;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (i == 1) root = t;
        Insert(node, t, root);
    }
}

bool IsEqual(Node* node, Node* tmp, int n) {
    for (int i = 1; i <= n; i++) 
        if (node[i].r == tmp[i].r && node[i].l == tmp[i].l) continue;
        else return 0;
    return 1;
}

int main()
{
    int n, l;
    while (cin >> n && n) {
        cin >> l;
        Node node[MAXN+1];
        Build(node, n);
        for (int j = 0; j < l; j++) {
            Node tmp[MAXN+1];
            Build(tmp, n);
            if (IsEqual(node, tmp, n)) cout << "Yes";
            else cout << "No";
            cout << endl;
        }
    }
    return 0;
}