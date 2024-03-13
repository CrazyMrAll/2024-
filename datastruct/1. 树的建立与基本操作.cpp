#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 50;
int sons[MAXN];
int totalsons[MAXN];
stack<int> node;
int order, depth;

int main()
{
    char ch;
    while (scanf("%c", &ch) && ch != '\n') {
        if (ch == '(') {
            scanf("%c", &ch);
            if (ch != ')') {
                for (register int i = 0; i < depth; i++)
                printf("    ");
                printf("%c\n", ch);
                if (!node.empty()) {
                    sons[node.top()]++;
                }
                node.push(order);
                order++;
                depth++;
            }
        } else if (ch == ')') {
            node.pop();
            depth--;
        }
    }
    int max = 0;
    for (register int i = 0; i < order; i++) {
        if (sons[i] > max) max = sons[i];
        totalsons[sons[i]]++;
    }
    printf("Degree of tree: %d\n", max);
    for (register int i = 0; i <= max; i++) 
        printf("Number of nodes of degree %d: %d\n", i, totalsons[i]);
    return 0;
}