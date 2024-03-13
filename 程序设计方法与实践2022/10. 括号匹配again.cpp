#include <iostream>
using namespace std;
const int MAXN = 100001;
typedef struct table
{
    int r = 0, l = 0;
    bool flag = 1;
}Table;

Table table[MAXN];

int main()
{
    int n, cnt = 0;
    scanf("%d\n", &n);
    for (int m = 0; m < n; m++) {
        char tmp;
        while (scanf("%c", &tmp) && tmp != '\n') {
            if (tmp == '(') table[m].l++;
            else if (table[m].l) table[m].l--;
            else table[m].r++;
        }
        if (table[m].l && table[m].r) table[m].flag = 0;
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (table[i].flag && table[j].flag) {
                bool flag = 0;
                if (table[i].l == table[j].r ) {
                    if (!table[i].l) {
                        if (table[i].r == table[j].l) 
                            flag = 1;
                    } else {
                        if (table[i].r == table[i].l && !table[i].r)
                            flag = 1;
                    }
                } else if (table[i].r == table[j].l) {
                    if (!table[i].r) {
                        if (table[i].l == table[j].r) 
                            flag = 1;
                    } else {
                        if (table[i].l == table[i].r && !table[i].l)
                            flag = 1;
                    }
                }
                if (flag) {
                        // cout << i+1 << " " << j+1 << endl;
                        cnt++;
                        table[i].flag = table[j].flag = 0;
                    }
            }
        }
    }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    //     cout << table[i].l << " " << table[i].r << endl;
    printf("%d\n", cnt);
    return 0;
}