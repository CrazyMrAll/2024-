#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
const int MAXN = 26;
int add[MAXN], order[MAXN];//定位用
bool vis[MAXN];//是否碰到过这个字母
char s[2*MAXN], posts[2*MAXN];
char operations[7] = {'!', '&', '|', '-', '+', '(', ')'};
char map[7][7] = {
    {'>', '>', '>', '>', '>', '<', '>'},
    {'<', '>', '>', '>', '>', '<', '>'},
    {'<', '>', '>', '>', '>', '<', '>'},
    {'<', '<', '<', '>', '>', '<', '>'},
    {'<', '<', '<', '>', '>', '<', '>'},
    {'<', '<', '<', '<', '<', '<', '='},
    {'>', '>', '>', '>', '>', '>', '>'},};

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

int main()
{
    scanf("%s", s);
    int index = 0, cnt = 0;
    // 转换为后缀表达式
    {
        stack<char> tmp;
        char now;
        for (register int i = 0; s[i] != '\0'; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (!vis[s[i]-'a']) {
                    vis[s[i]-'a'] = 1;
                    order[cnt] = s[i]-'a';
                    add[s[i]-'a'] = cnt++;
                }
                posts[index++] = s[i];
            } else {
                if (tmp.empty()) tmp.push(s[i]);
                else {
                    bool flag = 1;
                    while (!tmp.empty()) {
                        now = cmp(tmp.top(), s[i]);
                        // printf("%c %c %c\n", tmp.top(), now, s[i]);
                        if (now == '=') {
                            tmp.pop();
                            flag = 0;
                            break;
                        } else if (now == '<') {
                            tmp.push(s[i]);
                            flag = 0;
                            break;
                        } else {
                            posts[index++] = tmp.top();
                            tmp.pop();
                        }
                    }
                    if (flag) tmp.push(s[i]);
                }
            }
        }
        while (!tmp.empty()) {
            posts[index++] = tmp.top();
            tmp.pop();
        }
    }
    // printf("%s\n", posts);
    // 每次运算
    stack<bool> cal;
    int rate = pow(2, cnt);
    bool num[cnt];
    for (register int i = 0; i < rate; i++) {
        int t = i;
        for (register int j = cnt-1; j >= 0; j--) {
            num[add[order[j]]] = t%2;
            // printf("order[j] = %d, add[order[j]] = %d, num = %d\n", order[j], add[order[j]], num[add[order[j]]]);
            t /= 2;
        }
        // for (register int j = 0; j < cnt; j++) {
        //     printf("%c = %d, ", order[j]+'a', num[j]);
        // } printf("\n");
        bool a, b, tmp;
        for (register int k = 0; k < index; k++) {
            if (posts[k] >= 'a' && posts[k] <= 'z') {
                cal.push(num[add[posts[k] - 'a']]);
            } else if (posts[k] == '!') {
                tmp = cal.top();
                cal.pop();
                tmp ^= 1;
                cal.push(tmp);
            } else {
                a = cal.top();
                cal.pop();
                b = cal.top();
                cal.pop();
                if (posts[k] == '&') tmp = a&&b;
                else if (posts[k] == '|') tmp = a||b;
                else if (posts[k] == '-') {
                    tmp = 1;
                    if (a && !b) tmp = 0;
                } else {
                    tmp = 0;
                    if ((a && b) || (!a && !b)) tmp = 1;
                }
                cal.push(tmp);
            }
        }
        tmp = cal.top();
        if (tmp) {
            printf("YES\n");
            return 0;
        }
        cal.pop();
    }
    printf("NO\n");
    return 0;
}