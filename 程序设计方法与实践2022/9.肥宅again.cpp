#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1001;
const int l = 10;
char Origin[11] = "fattyhappy";
char str[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    for (int m = 0; m < T; m++) {
        scanf("%s", str);
        // cout << m << endl;
        bool Flag = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            int cnt = 0, a[2] = {0, 0}, tmpp = 0;
            for (int j = 0; j < l && tmpp <= 2; j++) {
                if (str[i+j] != '\0')
                    if (str[i+j] == Origin[j])
                        cnt++;
                    else 
                        a[tmpp++] = i + j;
                else break;
            }
            if (cnt == 8) {
                // cout << 1 << endl;
                // printf("%d %d\n", a[0], a[1]);
                if (str[i+l-2] == '\0') break;
                char tmp = str[a[0]];
                str[a[0]] = str[a[1]];
                str[a[1]] = tmp;
                bool tmpflag = 1;
                // printf("%s\n", str);
                for (int k = 0; k < l; k++) 
                    if (str[i+k] != Origin[k]) {
                        // cout << 1 << endl;
                        tmpflag = 0;
                    } 
                tmp = str[a[0]];
                str[a[0]] = str[a[1]];
                str[a[1]] = tmp;
                // printf("%s\n", str);
                if (tmpflag) {
                    // cout << 2 << endl;
                    printf("%d %d\n", a[0]+1, a[1]+1);
                    Flag = 0;
                    break;
                }
            } else if (cnt == 9) {
                // cout << 2 << endl;
                // scanf("%s\n", &str[i]);
                if (str[i+l-1] == '\0') break;
                else {
                    char lack = Origin[a[0]-i];
                    // cout << lack << endl;
                    // cout << str << endl;
                    bool tmpflag = 1;
                    for (int k = 0; k < i; k++)
                        if (str[k] == lack) {
                            // cout << 1 << endl;
                            a[tmpp++] = k;
                            tmpflag = 0;
                            break;
                        }
                    if (!tmpflag) {
                        printf("%d %d\n", a[1]+1, a[0]+1);
                        Flag = 0;
                        break;
                    } else {
                        for (int k = i + l; str[k] != '\0'; k++)
                            if (str[k] == lack) {
                            a[tmpp++] = k;
                            tmpflag = 0;
                            break;
                        }
                        if (!tmpflag) {
                            printf("%d %d\n", a[0]+1, a[1]+1);
                            Flag = 0;
                            break;
                        }
                    }
                }
            } else if (cnt == 10) {
                printf("%d %d\n", i+2, i+7);
                Flag = 0;
                break;
            }
            // cout << 3 << endl;
        }
        if (Flag) printf("-1\n");
    }
    return 0;
}