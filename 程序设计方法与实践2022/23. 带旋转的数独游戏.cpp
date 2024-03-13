#include <iostream>
using namespace std;
const int size = 16;
int map[size][size];
int num[size][size];
int step = 0;
int cnt = 0x7fffffff;
int s[size];
int ans[size];

void spin(int n, int r) {
    int i = n / 4, j = n % 4;
    int ii = 0;
    switch (r)
    {
    case 0: 
        for (register int a = i*4; a < (i+1)*4; a++) 
            for (register int b = j*4; b < (j+1)*4; b++) 
                map[a][b] = num[n][ii++];    
        break;
    case 1: 
        for (register int b = j*4; b < (j+1)*4; b++) 
            for (register int a = (i+1)*4-1; a >= i*4; a--) 
                map[a][b] = num[n][ii++];    
        break;
    case 2: 
        for (register int a = (i+1)*4-1; a >= i*4; a--) 
            for (register int b = (j+1)*4-1; b >= j*4; b--) 
                map[a][b] = num[n][ii++];    
        break;
    case 3: 
        for (register int b = (j+1)*4-1; b >= j*4; b--) 
            for (register int a = i*4; a < (i+1)*4; a++) 
                map[a][b] = num[n][ii++];    
        break; 
    }
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++)
    //         cout << map[i][j] << '\t';
    //     cout << endl;
    // } cout << endl;
}

// void erase(int n) {
//     int i = n / 4, j = n % 4;

// }

bool check(int n) {
    if (n < size) {
        int i = n / 4, j = n % 4;
        bool flag = 1;
        // 检查列
        for (register int b = 0; b < (j+1)*4 && flag; b++) {
            bool vis[size];
            for (register int i = 0; i < size; i++) 
                vis[i] = 0;
            for (register int a = 0; a < (i+1)*4; a++) {
                // cout << map[a][b] << " ";
                if (vis[map[a][b]]) {
                    flag = 0;
                    break;
                } else vis[map[a][b]] = 1;
            }
            // cout << endl;
        }
        if (flag) {
            // 检查行
            for (register int a = 0; a < (i+1)*4 && flag; a++) {
                bool vis[size];
                for (register int i = 0; i < size; i++) 
                    vis[i] = 0;
                for (register int b = 0; b < (j+1)*4; b++) {
                    // cout << map[a][b] << " ";
                    if (vis[map[a][b]]) {
                        flag = 0;
                        break;
                    } else vis[map[a][b]] = 1;
                }
                // cout << endl;
            }
        }
        return flag;   
    } else return 0;
}

void dfs(int n) {
    if (n == size) {
        if (step < cnt) {
            // for (int i = 0; i < size; i++) {
            //     for (int j = 0; j < size; j++)
            //         cout << map[i][j] << '\t';
            //     cout << endl;
            // } cout << endl;
            cnt = step;
            for (register int i = 0; i < size; i++)
                ans[i] = s[i];
        } else return;
    } else {
        for (register int i = 0; i < 4; i++) {
            spin(n, i);
            s[n] = i;
            if (check(n)) {
                // cout << "Entry!!" << endl;
                step += i;
                dfs(n+1);
                step -= i; 
            }
            // erase(n);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (register int r = 0; r < T; r++) {
        step = 0;
        cnt = 0x7fffffff;
        char t[size+1];
        for (register int i = 0; i < size; i++) {
            scanf("%s", t);
            for (register int j = 0; j < size; j++) {
                char tmp = t[j];
                if (tmp-'0' >= 0 && tmp-'0' <= 9)
                    num[i/4*4+j/4][4*(i-i/4*4)+j%4] = tmp - '0';
                else num[i/4*4+j/4][4*(i-i/4*4)+j%4] = 10 + tmp - 'A';
            }
        }   
        dfs(0);
        printf("%d\n", cnt);
        for (register int i = 0; i < size; i++) {
            if (ans[i]) {
                int a = i/4 + 1, b = i%4 + 1;
                for (register int j = 0; j < ans[i]; j++)
                    printf("%d %d\n", a, b);
            }
        }
    }
    return 0;
}