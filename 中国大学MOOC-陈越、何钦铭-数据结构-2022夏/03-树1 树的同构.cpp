#include <iostream>
#include <cstring>
using namespace std;
typedef struct node {
    char name;
    char left[5], right[5]; 
    int child;  
} Node;
Node item[10];
Node another[10];

int count (char *a, char *b) {
    int cnt = 0;
    cnt += !strcmp(a, "-") + !strcmp(b, "-");
    return cnt;
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> item[i].name >> item[i].left >> item[i].right;
        item[i].child = count(item[i].left, item[i].right);
    }    
    cin >> m;
    bool flag = 0;
    if (n == m) {
        flag = 1;
        for (int i = 0; i < n; i++) {
            flag = 0;
            cin >> another[i].name >> another[i].left >> another[i].right;
            another[i].child = count(another[i].left, another[i].right);
            for (int j = 0; j < n; j++) {
                if (item[j].name == another[i].name)
                    if (item[j].child == another[i].child) {
                        flag = 1;
                        break;
                    }   
            }
            if (!flag) break;
        }
    }
    if (flag) cout << "Yes";
    else cout << "No";
    return 0;
}