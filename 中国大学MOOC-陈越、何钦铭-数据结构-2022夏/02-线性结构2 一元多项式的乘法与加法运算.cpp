#include <iostream>
using namespace std;
#define MAXN 10
typedef struct item {
    int n;
    int e;
} Item;
Item I1[MAXN], I2[MAXN], ans1[MAXN*MAXN], ans2[MAXN];

int main()
{
    int n1, n2, m1, m2;
    cin >> n1;
    for (int i = 0; i < n1; i++) 
        cin >> I1[i].n >> I1[i].e;
    cin >> n2;
    for (int i = 0; i < n2; i++) 
        cin >> I2[i].n >> I2[i].e;
    int emap[MAXN][MAXN];
    for (int i = 0; i < n1; i++) 
        for (int j = 0; j < n2; j++)
            emap[i][j] = I1[i].e + I2[j].e;
    int max = 0;
    for (m1 = 0; ; m1++) {
        max = 0;
        bool flag = 1;
        for (int i = 0; i < n1; i++) 
            for (int j = 0; j < n2; j++)
                if (emap[i][j] >= max) {max = emap[i][j]; flag = 0;}
        for (int i = 0; i < n1; i++) 
            for (int j = 0; j < n2; j++)
                if (emap[i][j] == max) {
                    ans1[m1].e = emap[i][j];
                    ans1[m1].n += I1[i].n * I2[j].n;
                    emap[i][j] = -1;
                }
        if (!ans1[m1].n && ans1[m1].e) m1--;//第一次提交没有想到这句话
        if (flag) break;
    }
    int i1, i2;
    i1 = i2 = 0;
    for (m2 = 0; i1 < n1 || i2 < n2; m2++) {
        if (I1[i1].e > I2[i2].e) {
            ans2[m2].e = I1[i1].e;
            ans2[m2].n = I1[i1++].n;
        } else if ((I1[i1].e < I2[i2].e)) {
            ans2[m2].e = I2[i2].e;
            ans2[m2].n = I2[i2++].n;
        } else {
            int num = I1[i1].n + I2[i2].n;
            if (num == 0) m2--;
            else {
                ans2[m2].e = I1[i1].e;
                ans2[m2].n = num;
            } i1++; i2++;
        }
    }
    cout << ans1[0].n << " " << ans1[0].e;
    for (int i = 1; i < m1; i++) 
        cout << " " << ans1[i].n << " " << ans1[i].e;
    cout << endl;
    cout << ans2[0].n << " " << ans2[0].e;
    for (int i = 1; i < m2; i++) 
        cout << " " << ans2[i].n << " " << ans2[i].e;    
    return 0;
}