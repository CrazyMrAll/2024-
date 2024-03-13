#include <iostream>
using namespace std;

int main()
{
    int n, t;
    scanf("%d\n", &n);
    char ch;
    for (register int i = 0; i < n; i++) {
        int in, out;
        t = in = out = 0;
        while (scanf("%c", &ch)) {
            if (ch == '\n') break;
            else if (ch == '+') {
                t++;
                if (t > out) out = t;
            } else {
                t--;
                if (t < in) in = t;
            }
        }
        printf("%d\n", out - in);
    } 
    return 0;
}