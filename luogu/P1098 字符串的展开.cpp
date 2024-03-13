#include <iostream>
using namespace std;

int main()
{
    char s[110];
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3 >> s;
    for (int i = 0; s[i]!='\0'; ++i) {
        bool flag = 0;
        if (s[i]=='-') {printf("-"); continue;}
        if (s[i+1]!='-') flag = 1;
        else if (s[i+2]<=s[i]) flag = 1;
        else {
            flag = 1;
            bool flag1, flag2;
            flag1 = flag2 = 0;
            if (s[i]>='a' && s[i]<='z') flag1 = 1;
            if (s[i+2]>='a' && s[i+2]<='z') flag2 = 1;
            if (flag1==flag2) flag = 0;
        }
        cout << s[i];
        if (!flag) {
            int len = s[i+2] - s[i];
            for (int j = 1; j < len; ++j) {
                char ch;
                if (p3==2) ch = s[i+2] - j;
                else ch = s[i] + j;
                if (s[i]>='a' && s[i]<='z')
                    if (p1==2) ch += 'A' - 'a';
                if (p1==3) ch = '*';
                for (int i = 0; i < p2; ++i)
                    cout << ch;
            }
            ++i;
        }
    }
    return 0;
}