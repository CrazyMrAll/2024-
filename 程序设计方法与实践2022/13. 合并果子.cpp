#include <iostream>
using namespace std;
const int MAXN = 20005;
int a[MAXN];

int main()
{
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int *p = a;
    for (int i = 0; i < n-1; i++) {
        for (int j = (n-i)/2-1; j >= 0; j--) {
            if (2*j+2 <= n-1-i) {
                if (p[j] > p[2*j+2]) {
                    int t = p[j];
                    p[j] = p[2*j+2];
                    p[2*j+2] = t; 
                }  
            }
            if (p[j] > p[2*j+1]) {
                int t = p[j];
                p[j] = p[2*j+1];
                p[2*j+1] = t; 
            }
        }
        bool flag = 1;
        if (p[2]) flag = p[1]<p[2] ? 0 : 1;
        else flag = 0;
        // for (int i = 0; i < n; i++)
        //     printf("%d ", p[i]);
        // cout << endl;
        // printf("%d %d %d\n", p[0], p[1+flag], p[0]+p[1+flag]);
        p[1+flag] += p[0];
        ans += p[1+flag];
        p++;
        // printf("%lld\n", ans);  
    }
    printf("%lld\n", ans);   
    return 0;
}