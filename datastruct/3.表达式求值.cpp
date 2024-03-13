#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> s;
stack<int> n;

char operations[8] = {'+', '-', '*', '/', '(', ')', '^', '%'};
char map[8][8] = {
    {'>', '>', '<', '<', '<', '>', '<', '<'},
    {'>', '>', '<', '<', '<', '>', '<', '<'},
    {'>', '>', '>', '>', '<', '>', '<', '>'},
    {'>', '>', '>', '>', '<', '>', '<', '>'},
    {'<', '<', '<', '<', '<', '=', '<', '<'},
    {'>', '>', '>', '>', ' ', '>', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '<', '>'},
    {'>', '>', '>', '>', '<', '>', '<', '>'}};

char cmp(char a, char b) {
    int x, y;
    for (register int i = 0; i < 8; i++) 
        if (a == operations[i]) {
            x = i;
            break;
        }
    for (register int i = 0; i < 8; i++) 
        if (b == operations[i]) {
            y = i;
            break;
        } 
    return map[x][y];       
}

int calculate(char t) {
    if (t == '(' || t == ')') return 0;
    else if (n.size() < 2) return 0;
    else {
        int a, b, c = 1;
        b = n.top();
        n.pop();
        a = n.top();
        n.pop();
        // printf("cal: %d %c %d\n", a, t, b);
        switch (t) {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                if (b == 0) return -1;
                else c = a / b;
                break;
            case '^':
                if (b < 0) return 0;
                else 
                    while (b) {
                        c *= a;
                        b--;
                    }
                break;
            case '%':
                if (b == 0) return -1;
                else c = a % b;
                break;
            default:
                return 0;
                break;
        }
        // printf("pushnum %d\n", c);
        n.push(c);
        return 1;
    }
}

int main()
{
    int T;
    scanf("%d\n", &T);
    string str;
    bool sign = 1;//符号
    int tnum;
    for (register int g = 0; g < T; g++) {                                           
        cin >> str;
        if (str[0] == '-') sign = 0;
        int flag = 1;//是否出错(1正常、0error、-1Divide 0)
        bool numflag = 0;//是否是数字
        while (!s.empty()) s.pop();
        while (!n.empty()) n.pop();
        for (register int i = 0; flag == 1; i++) {
            tnum = 0;
            numflag = 0;
            if (!sign) i++;
            while (str[i]>='0' && str[i]<='9' && str[i] != '\0') {
                tnum = tnum*10 + str[i]-'0';
                numflag = 1;
                i++;
            }
            if (numflag) {
                // printf("sign = %d\n", sign);
                if (sign) {
                    // printf("pushnum %d\n", tnum);
                    n.push(tnum);
                } else {
                    // printf("pushnum %d\n", -tnum);
                    n.push(-tnum);
                }
                sign = 1;
            }
            if (str[i] == '(') {
                if (str[i+1] == '+' || str[i+1] == '*' || str[i+1] == '/' || 
                    str[i+1] == '^' || str[i+1] == '%' ) flag = 0;
                else {
                    if (str[i+1] == '-') sign = 0;
                    s.push(str[i]);
                }
                // printf("pushsyb %c\n", str[i]);
            } else {
                while (str[i] != '\0') {
                    if (s.empty()) {
                        if (str[i+1] == '-') sign = 0;
                        // printf("pushsyb %c\n", str[i]);
                        s.push(str[i]);
                        break;
                    } else {
                        char t = cmp(s.top(), str[i]);
                        if (t == '<') {
                            if (str[i+1] == '-') sign = 0;
                            // printf("pushsyb %c\n", str[i]);
                            s.push(str[i]);
                            break;
                        } else if (t == '=') {
                            // printf("popsyb %c\n", s.top());
                            s.pop();
                            break;
                        } else if (t == ' ') {
                            flag = 0;
                            break;
                        } else {
                            t = s.top();
                            s.pop();
                            flag = calculate(t);
                        }
                    }
                }
            }
            if (str[i] == '\0') break;
        }
        char t;
        // printf("ssize = %d, nsize = %d\n", s.size(), n.size());
        while (!s.empty() && flag == 1) {
            t = s.top();
            s.pop();
            flag = calculate(t);
        }
        // printf("ssize = %d, nsize = %d\n", s.size(), n.size());
        if (n.size() > 1) flag = 0;
        if (flag == 1) printf("%d\n", n.top());
        else if (flag == 0) printf("error.\n");
        else printf("Divide 0.\n");
    }
    return 0;
}