#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 30
int PreOrder[MAXN], InOrder[MAXN];
int stack[MAXN], top = -1;

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

void FindRoot() {
    
}

int main()
{
    int n;
    cin >> n;
    char movement[5];
    {
        int pre, in;
        pre = in = 0;
        for (int i = 0; i < 2 * n; i++) {
            cin >> movement;
            if (!strcmp(movement, "Push")) {
                int t;
                cin >> t;
                PreOrder[pre++] = Push(t);
            } else InOrder[in++] = Pop();
        }
    }
    {
       
        int root = PreOrder[0];
        for (int i = 0; i < n; i++) {
            
        }
        node[root].left = FindRoot(0, m-1);
        node[root].right = FindRoot(m+1, n-1); 
    }
    
    return 0;
}