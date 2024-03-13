#include <iostream>
using namespace std;
typedef struct node {
    int left = -1, right = -1;
} Node;
Node node[10];
int IsHead[11];
int q[11];
int front = -1, rear = -1;

void Addq(int *q, int root) {
    if (node[root].left != -1) {
        rear = (rear + 1) % 11;
        q[rear] = node[root].left;
    }
    if (node[root].right != -1) {
        rear = (rear + 1) % 11;
        q[rear] = node[root].right;
    }
}

bool IsEmpty() {
    return (front == rear);
}

int Deleteq(int *q) {
    front = (front + 1) % 11;
    int tmp = q[front];
    q[front] = 0;
    return tmp;
}

bool IsLeaf(int root) {
    if (node[root].left == node[root].right && node[root].left == -1) return 1;
    else return 0;
}

int main()
{
    int n;
    cin >> n;
    if (n) {
        for (int i = 0; i < n; i++) {
            char a, b;
            cin >> a >> b;
            int left = a - '0', right = b - '0';
            if (left <= 9 && left >=0) {
                node[i].left = left; 
                IsHead[left] = 1;
            }
            if (right <= 9 && right >=0) {
                node[i].right = right;
                IsHead[right] = 1;
            }
        }
        int root, cnt = 0;
        for (int i = 0; i <= n; i++)
            if (!IsHead[i]) {
                root = i;
                break;
            }
        q[++rear] = root;
        while (!IsEmpty()) {
            root = Deleteq(q);
            if (IsLeaf(root)) {
                if (cnt) cout << " ";
                cout << root;
                cnt++;
            }
            Addq(q, root);
        }
    }
    return 0;
}