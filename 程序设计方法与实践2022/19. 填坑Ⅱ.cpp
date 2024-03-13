#include <iostream>
#include<ios>
#include<limits>
#include <cmath>
using namespace std;
const int MAXN = 200005;
int stack[MAXN];
int top = -1;

int main()
{
    int n, t, max = 0;
    while (scanf("%d", &n) != EOF) {
        top = -1;
        max = 0;
        for (register int i = 0; i < n; i++) {
            scanf("%d", &t);
            if (max < t) max = t;
            if (top == -1) stack[++top] = t;
            else {
                if (t < stack[top]) stack[++top] = t;
                else if (t == stack[top]) top--;
                else {top++; break;}
            }
            // cout << "aa" << endl;
        }
        // cout << "bb" << endl;
        if (top <= 0) {
            if (top == 0) {
                if (stack[top] == max) printf("YES\n");
                else printf("NO\n");
            } else printf("YES\n");
        } else printf("NO\n");
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return 0;
}