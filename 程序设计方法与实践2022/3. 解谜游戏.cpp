#include <iostream>
#include <limits.h>
using namespace std;
const int MAXN = 16;
bool map[MAXN][MAXN];
bool t[MAXN][MAXN];
bool method[MAXN];
int n, m;

void Press(int i, int j) {
    t[i][j] ^= 1;
    if (i-1 >= 0) 
        t[i-1][j] ^= 1;
    if (i+1 < n)
        t[i+1][j] ^= 1;
    if (j-1 >= 0)
        t[i][j-1] ^= 1;
    if (j+1 < m)
        t[i][j+1] ^= 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
            char tmp[m+1];
            scanf("%s", tmp);
            for (int j = 0; j < m; j++)
                t[i][j] = map[i][j] = tmp[j] - '0';
    }
    int ans = INT_MAX, flag = 0, round = 0;;
    bool tmpflag = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            if (map[i][j]) {
                tmpflag = 0;
                break;
            }
    if (tmpflag) {
        ans = 0;
    } else {
        while (flag < m) {
            flag = 0;
            if (round) { //第一次
                if (!method[0])
                    method[0] = 1;
                else {
                    int i = 0;
                    for ( ; method[i]; i++) 
                        method[i] = 0;
                    method[i] = 1;
                }
                // for (int i = m-1; i >= 0; i--)  
                //     cout << method[i];
                // cout << endl;  
                for (int i = 0; i < m; i++)
                    flag += method[i];
            }
            int cnt = 0;
            for (int i = 0; i < m; i++) 
                if (method[i]) {
                    Press(0, i);
                    cnt++;
                    // {
                    //     for (int i = 0; i < n; i++) {
                    //         for (int j = 0; j < m; j++)
                    //             cout << t[i][j];
                    //         cout << endl;
                    //     } cout << endl;     
                    // }
                }        
            for (int i = 1; i < n; i++) 
                for (int j = 0; j < m; j++) 
                    if (t[i-1][j]) {
                        Press(i, j);
                        cnt++;
                        // {
                        //     for (int i = 0; i < n; i++) {
                        //         for (int j = 0; j < m; j++)
                        //             cout << t[i][j];
                        //         cout << endl;
                        //     } cout << endl; 
                        // }
                    }            
            bool right = 1;
            for (int j = 0; j < m; j++)
                if (t[n-1][j]) {
                    right = 0;
                    break;
                }
            if (right) 
                if (cnt < ans)  
                    ans = cnt;
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < m; j++) 
                    t[i][j] = map[i][j];
            round++;
        }
    }
    printf("%d\n", ans);
    return 0;
}