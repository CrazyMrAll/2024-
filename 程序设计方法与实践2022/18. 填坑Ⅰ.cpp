#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 200005;
int stack[MAXN];
int top = -1;

int main()
{
    int n, t, h;
    while (cin >> n) {
        top = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            if (top == -1) stack[++top] = t;
            else {
                h = abs(t - stack[top]);
                if (h%2) stack[++top] = t;
                else top--;
            }
        }
        if (top <= 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}