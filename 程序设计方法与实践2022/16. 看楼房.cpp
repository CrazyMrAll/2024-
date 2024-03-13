#include <iostream>
using namespace std;
const int MAXN = 1000005;
int c[MAXN], h[MAXN], stack[MAXN];
bool color[MAXN];
int top = -1;

int main()
{
    int T;
    scanf("%d", &T);
    for (int m = 0; m < T; m++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) 
            scanf("%d", &c[i]);
        for (int i = 0; i < n; i++) 
            scanf("%d", &h[i]);
        for (int i = 0; i < n; i++) {
            if (top == -1 || h[i] < h[stack[top]]) {
                if (!color[c[i]]) {
                    stack[++top] = i;
                    color[c[i]] = 1;
                }
            } else {
                while (h[i] >= h[stack[top]] && top != -1) {
                    color[c[stack[top]]] = 0;
                    top--;
                }
                if (!color[c[i]]) {
                    stack[++top] = i;
                    color[c[i]] = 1;
                }
            }
            printf("%d", top+1);
            if (i == n-1) printf("\n");
            else printf(" ");
        }
        while (top != -1) 
            color[c[stack[top--]]] = 0;
    }   
    return 0;
}