#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 30;
struct node {
    char name;
    node *left = NULL;
    node *right = NULL;
};
char MidOrder[MAXN];
char PostOrder[MAXN];
int index;
int cnt;
queue<node*> q;

node *Build() {
    node *t = NULL;
    if (MidOrder[index+cnt] != '\0') {
        printf("index = %d, cnt = %d\n", index, cnt);
        printf("%c, %c\n", PostOrder[index], MidOrder[index+cnt]);
        t = new node;
        t->name = MidOrder[index+cnt];
        if (PostOrder[index] == MidOrder[index+cnt]) {
            index++;
            Build();
        } else {
            cnt++;
            node *tmp = t;
            while (!s.empty()) {
                tmp->left = s.top();
                printf("%c's left is %c\n", tmp->name, tmp->left->name);
                tmp = tmp->left;
                s.pop();
            }
        }
        t->right = Build();
        printf("%c's right is %c\n", t->name, t->right->name);
    } 
    return t;
}

void LayOrder(node *root) {
    q.push(root);
    node *t;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        printf("%c", t->name);
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
}

int main() 
{
    scanf("%s", MidOrder);
    scanf("%s", PostOrder);
    LayOrder(Build());
    printf("\n");
    return 0;
}