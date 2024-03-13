#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1001;
const int l = 10;
char Origin[11] = "fattyhappy";
char table[100][11];
char str[MAXN];

int main()
{
    for (int i = 1; i < l; i++) {
        for (int j = i+1; j <= l; j++) {
            if (Origin[i-1] != Origin[j-1]) {
                strcpy(table[i*10+j], Origin);
                char tmp = Origin[i-1];
                table[i*10+j][i-1] = table[i*10+j][j-1];
                table[i*10+j][j-1] = tmp;
            }    
        }
    }
    // for (int i = 1; i < l; i++) {
    //     for (int j = i+1; j <= l; j++) {
    //         printf("%d %d: %s\n", i, j, table[i*10+j]);
    //     }
    // }
    int T;
    scanf("%d", &T);
    for (int m = 0; m < T; m++) {
        scanf("%s", str);
        bool Flag = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            char tmp = str[i+l];
            str[i+l] = '\0';
            bool flag = 1;
            int a, b;
            for (int k = 1; k < l && flag; k++) 
                for (int j = 2; j <= l; j++) 
                    if (!strcmp(&str[i], table[k*10+j])) {
                        flag = 0;
                        a = k;
                        b = j;
                    }              
            if (flag) 
                str[i+l] = tmp;
            else {
                printf("%d %d\n", a+i, b+i);
                Flag = 0;
                break;
            }
            if (str[i+l] == '\0')
                break;
        }
        if (Flag) printf("-1\n");
    }
    return 0;
}