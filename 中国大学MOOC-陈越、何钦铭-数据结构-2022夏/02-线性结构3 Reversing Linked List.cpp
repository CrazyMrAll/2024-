#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 10000
typedef struct info *List; 
typedef struct info {
    int num, no;
    char front[6], rear[6];
} Info;
Info item[MAXN];

int main()
{
    int n, k;
    char entry[6];
    cin >> entry >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> item[i].front >> item[i].num >> item[i].rear;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if(!strcmp(entry, item[j].front)) {
                item[j].no = i;
                strcpy(entry, item[j].rear);
                break;
            }
        }   
    }
    for (int j = k; j > 0; j--) {
        for (int i = 0; i < n; i++) 
            if (item[i].no == j) {
                if (j != k) cout << " " << item[i].front << endl;
                cout << item[i].front << " " << item[i].num;
            }
                
    }  
    for (int j = k + 1; j <= n; j++) {
        for (int i = 0; i < n; i++) 
            if (item[i].no == j) {
                cout << " " << item[i].front << endl;
                cout << item[i].front << " " << item[i].num;
                if (j == n) cout << " " << -1;
            }
                
    }   
    return 0;
}