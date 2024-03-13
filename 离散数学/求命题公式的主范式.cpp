#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
const int MAXN = 26;
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
                    cnt++;
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
    int rate = pow(2, cnt);
    bool ans[rate], num[cnt];
    int order[MAXN];//定位用
    {
        int t = cnt;
        int i = MAXN;
        while (t--) {
            while (1) {
                i--;
                if (vis[i]) {
                    order[i] = t;
                    break;
                }
            }
        }
    }
    bool tflag = 1, fflag = 1;
    for (register int i = 0; i < rate; i++) {
        int t = i;
        for (register int j = cnt-1; j >= 0; j--) {
            num[j] = t%2;
            t /= 2;
        }
        // printf("%d round:\n", i);
        // for (register int j = 0; j < cnt; j++) {
        //     printf("%d, ", num[j]);
        // } 
        stack<bool> cal;
        bool a, b, tmp;
        for (register int k = 0; k < index; k++) {
            if (posts[k] >= 'a' && posts[k] <= 'z') {
                // printf("order = %d, num = %d\n", order[posts[k] - 'a'], num[order[posts[k] - 'a']]);
                cal.push(num[order[posts[k] - 'a']]);
            } else if (posts[k] == '!') {
                tmp = cal.top();
                cal.pop();
                tmp ^= 1;
                cal.push(tmp);
            } else {
                b = cal.top();
                cal.pop();
                a = cal.top();
                cal.pop();
                if (posts[k] == '&') tmp = a&b;
                else if (posts[k] == '|') tmp = a|b;
                else if (posts[k] == '-') {
                    tmp = 1;
                    if (a && !b) tmp = 0;
                } else {
                    tmp = 0;
                    if ((a && b) || (!a && !b)) tmp = 1;
                }
                // printf("%d %c %d = %d\n",a , posts[k], b, tmp);
                cal.push(tmp);
            }
        }
        tmp = cal.top();
        cal.pop();
        ans[i] = tmp;
        if (tmp) fflag = 0;
        if (!tmp) tflag = 0;
    }
    bool flag = 0;
    if (fflag) printf("0 ");
    else for (register int i = 0; i < rate; i++) {
        if (ans[i]) {
            if (flag) printf("∨ ");
            flag = 1;
            printf("m%d ", i);
        }
    }
    flag = 0;
    printf(";");
    if (tflag) printf(" 1");
    else for (register int i = 0; i < rate; i++) {
        if (!ans[i]) {
            if (flag) printf(" ∧");
            flag = 1;
            printf(" M%d", i);
        }
    }
    printf("\n");
    return 0;
}