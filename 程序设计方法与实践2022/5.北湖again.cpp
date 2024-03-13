#include <iostream>
using namespace std;
const int MAXN = 100000;

int min(int a, int b) {
    return a > b ? b : a;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        long long ans = 0;
        scanf("%d", &n);
        int map[MAXN];
        for (int i = 0; i < n; i++) 
            scanf("%d", &map[i]);
        int j = 0, stack[MAXN], top = -1;
        while (j < n) {
            // if (top >= 0)
            //     cout << "topnow = " << map[stack[top]] << endl;
            int tmp = map[j], deept;
            if (top == -1 || tmp < map[stack[top]]) {
                // printf("Push %d\n", j);
                stack[++top] = j++;
            } else {
                deept = stack[top];
                stack[top] = 0;
                top--;
                // printf("Pop %d\n", deept);
                if (top != -1) {
                    long long wide = j - stack[top] - 1;
                    long long h = min(tmp, map[stack[top]]) - map[deept];
                    ans += wide * h;
                    // printf("ans = %d\n", ans);
                } 
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}