#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> s;

char operations[7] = {'+', '-', '*', '/', '(', ')', '^'};
char map[7][7] = {
    {'>', '>', '<', '<', '<', '>', '<', },
    {'>', '>', '<', '<', '<', '>', '<', },
    {'>', '>', '>', '>', '<', '>', '<', },
    {'>', '>', '>', '>', '<', '>', '<', },
    {'<', '<', '<', '<', '<', '=', '<', },
    {'>', '>', '>', '>', ' ', '>', '>', },
    {'>', '>', '>', '>', '<', '>', '<', }};

char cmp(char a, char b) {
    int x, y;
    for (register int i = 0; i < 7; i++) 
        if (a == operations[i]) {
            x = i;
            break;
        }
    for (register int i = 0; i < 7; i++) 
        if (b == operations[i]) {
            y = i;
            break;
        } 
    return map[x][y];       
}

int main()
{
    int T;
    scanf("%d\n", &T);
    string str;
    for (register int g = 0; g < T; g++) {                                           
        cin >> str;
        for (register int i = 0; str[i] != '#'; i++) {
            if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
                printf("%c", str[i]);
            else {
                while (1) {
                    if (s.empty()) {
                        s.push(str[i]);
                        break;
                    } else {
                        char t = cmp(s.top(), str[i]);
                        if (t == '<') {
                            s.push(str[i]);
                            break;
                        } else if (t == '=') {
                            s.pop();
                            break;
                        } else {
                            t = s.top();
                            s.pop();
                            printf("%c", t);
                        }
                    }
                }
            }
        }
        char t;
        while (!s.empty()) {
            t = s.top();
            s.pop();
            printf("%c", t);
        }
        printf("\n");
    }
    return 0;
}