#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 50;
char node[MAXN];
queue<char> PreOrder;
queue<char> InOrder;
queue<char> PostOrder;
int LeafNum;

void Order(int t, int depth) {
    for (register int i = 0; i < depth; i++)
        printf("    ");
    printf("%c\n", node[t]);
    PreOrder.push(node[t]);
    bool flag = 1;
    if (node[2*t] != '\0') {
        Order(2*t, depth+1);
        flag = 0;
    }
    InOrder.push(node[t]);
    if (node[2*t+1] != '\0') {
        Order(2*t+1, depth+1);
        flag = 0;
    }
    if (flag) LeafNum++;
    PostOrder.push(node[t]);
}

void SwapOrder(int t, int depth) {
    for (register int i = 0; i < depth; i++)
        printf("    ");
    printf("%c\n", node[t]);
    PreOrder.push(node[t]);
    if (node[2*t+1] != '\0') SwapOrder(2*t+1, depth+1);
    InOrder.push(node[t]);
    if (node[2*t] != '\0') SwapOrder(2*t, depth+1);
    PostOrder.push(node[t]);
}

void inline Print() {
    printf("pre_sequence  : ");
    while(!PreOrder.empty()) {
        printf("%c", PreOrder.front());
        PreOrder.pop();
    }
    printf("\nin_sequence   : ");
    while(!InOrder.empty()) {
        printf("%c", InOrder.front());
        InOrder.pop();
    }
    printf("\npost_sequence : ");
    while(!PostOrder.empty()) {
        printf("%c", PostOrder.front());
        PostOrder.pop();
    }
}

int main()
{
    char ch;
    for (register int i = 1; ; i++) {
        scanf("%c", &ch);
        if (ch == '\n') break;
        else if (ch != '#') node[i] = ch;
    }
    printf("BiTree\n");
    Order(1, 0);
    Print();
    printf("\nNumber of leaf: %d\n", LeafNum);
    printf("BiTree swapped\n");
    SwapOrder(1, 0);
    Print();
    printf("\n");
    return 0;
}