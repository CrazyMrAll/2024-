#include <iostream>
#include <stack>
using namespace std;
stack<char> s;

int main()
{
    char ch;
    bool flag = 1;
    while ((ch = getchar()) != EOF) {
        // printf("chnow = %c\n", ch);
        if (ch == '(' || ch == '[') s.push(ch);
        else if (ch == ')') {
            if (s.empty()) {
                flag = 0;
                break;
            } else if (s.top() == '(') {
                // printf("pop %d\n", s.top());
                s.pop();
            } else {
                flag = 0;
                break;
            }
        } else if (ch == ']') {
            if (s.empty()) {
                flag = 0;
                break;
            } else if (s.top() == '[') s.pop();
            else {
                flag = 0;
                break;
            }
        }
    }
    if (flag) printf("Match succeed!\n");
    else printf("Match false!\n");
    return 0;
}