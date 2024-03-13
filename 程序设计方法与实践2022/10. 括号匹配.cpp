#include <iostream>
using namespace std;
const int MAXN = 100001;
bool map[5*MAXN];
int p[MAXN+1];
int top = -1;
int n;

bool Push(int i) {
    bool IsFind = 1;
    for (int k = 0; p[i]+k < p[i+1]; k++) {
        if (top == -1) {
            if (map[p[i]+k]) top++;
            else {
                IsFind = 0;
                break;
            }
        } else if (map[p[i]+k]) {
            top++;
        } else {
            if (top == -1) {
                IsFind = 0;
                break;
            }
            else top--;
        }
    }
    return IsFind;
}

int main()
{
    int cnt = 0, num = 0;
    scanf("%d", &n);
    char tmp[MAXN+1];
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        int j = 0, tmpcnt = 0;
        for (; tmp[j] != '\0'; j++) {
            if (tmp[j] == '(') map[p[num]+j-tmpcnt] = 1;
            else {
                if (j) tmpcnt += 2;
            }
        }
        p[num+1] = p[num] + j - tmpcnt;
        num++;
    }
        
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            top = -1;
            bool Islegal = Push(i);
            if (Islegal)
                Islegal = Push(j);
            if (Islegal && top == -1) {
                cnt++;
                // for (int k = p[i]; k < p[i+1]; k++) 
                //     cout << map[k];
                // cout << endl;
            }     
        }
    }
    // for (int i = 0; i < n; i++)
    //     cout << i << ": "<< p[i] << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = p[i]; j < p[i+1]; j++)
    //         cout << map[j];
    //     cout << endl;
    // }
    printf("%d\n", cnt);
    return 0;
}