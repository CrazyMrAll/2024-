#include<iostream>
using namespace std;
const int MAXN = 30;
int ans;
int table[MAXN];

void inline count(int n,int m) {
    if (n < m+1) return;
    else if (n == m+1) {
        ans += 1;
        return;
    } else {
        n -= m+1;
        ans++;
        int depth = 1;
        if (n == 0 || depth > m) return;
        int t;
        t = table[depth] - 1;
        while (n > t) {
            ans += table[depth-1];
            depth++;
            n -= t;
            t = table[depth] - 1;
            if (depth > m) return;
        }
        if (n == t) {
            ans += table[depth-1];
            return; 
        } else count(n, depth-1);
    }
}

int main() {
    int n, m, T;
    scanf("%d", &T);
    table[0] = 1;
    for (register int i = 1; i <= MAXN-1; i++)
        table[i] = table[i-1] * 2;
    for (register int g = 0; g < T; g++) {
        scanf("%d%d", &n, &m);
        ans = 0;
        count(n, m);
        printf("%d\n", ans);
    }
    return 0;
}