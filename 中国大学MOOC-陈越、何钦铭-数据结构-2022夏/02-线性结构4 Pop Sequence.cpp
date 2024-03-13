#include <iostream>
using namespace std;
#define MAXN 1000
int tmp[MAXN];
int stack[MAXN];
int contain, n, m;

int push(int *stack, int j, int *top) {
    if (*top < contain - 1) {
        stack[++(*top)] = j;
        // cout << "push" << j << endl;
        // cout << "topnow=" << *top << endl;
        return 1;
    } else return 0;
}

int pop(int *stack, int *top) {
    if (*top >= 0) {
        // cout << "pop" << stack[*top] << endl;
        stack[(*top)--] = 0;
        // cout << "topnow=" << *top << endl;
        return 1;
    } else return 0;
}

int main()
{
    cin >> contain >> n >> m;
    for (int i = 0; i < m; i++) {
        int top = -1;
        bool flag = 1;
        for (int j = 0; j < n; j++) 
            cin >> tmp[j];
        int now = 0;
        for (int j = 1; j <= n && flag; j++) {
            flag = push(stack, j, &top);
            while (flag && now < n && stack[top] == tmp[now]) {
                flag = pop(stack, &top);
                now++;
            }
        }
        if (top == -1 && flag) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}