#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1000001;

int main()
{
    char str[MAXN];
    while (gets(str)) {
        bool flag = 1;
        for (int i = 0; ; i++) {
            if (str[i] == '\0') break;
            if (str[i] == '.' || str[i] == '?' || str[i] == '!') {
                flag = 1;
                continue;
            } else if (str[i] != ' ') {
                if (flag) {
                    if (str[i] >= 'a' && str[i] <= 'z') str[i] += 'A' - 'a';
                    flag = 0;
                } else {
                    if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 'a' - 'A';
                }
            }
        }
        printf("%s\n", str);
    }
    return 0;
}