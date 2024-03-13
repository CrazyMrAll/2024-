#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 50;
char MidOrder[MAXN];
char PostOrder[MAXN];
int l[MAXN];
int r[MAXN];
int cnt;
int root;
int tmproot;
stack<int> s;
queue<int> q;

int main()
{
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    scanf("%s", MidOrder);
    scanf("%s", PostOrder);
    int i = 0;
    for ( ; MidOrder[i] != '\0'; i++) {
        if (MidOrder[i] == PostOrder[i-cnt]) s.push(i);
        else {
            if (!cnt) root = i;
            else r[tmproot] = i;
            cnt++;
            tmproot = i;
            while (!s.empty()) {
                l[tmproot] = s.top();
                tmproot = l[tmproot];
                s.pop();
            }
            tmproot = i;
        }
    }
    if (!s.empty()) {
        if (!cnt) {
            root = i - 1;
            tmproot = root;
        } else {
            r[tmproot] = s.top();
            s.pop();
            tmproot = r[tmproot];
        }
        while (!s.empty()) {
            if (root != s.top()) {
                l[tmproot] = s.top();
                tmproot = l[tmproot];
            }
            s.pop();
        }
    }
    q.push(root);
    while (!q.empty()) {
        tmproot = q.front();
        q.pop();
        printf("%c", MidOrder[tmproot]);
        if (l[tmproot] != -1) q.push(l[tmproot]);
        if (r[tmproot] != -1) q.push(r[tmproot]);
    }
    printf("\n");
    return 0;
}