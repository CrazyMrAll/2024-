
#include <stdio.h>
 
int main() {
    int n;
    double s = 0;
    int cnt1 = 0, cnt2 = 0;
    int arr[201][4]={0};
    scanf("%d\n", &n);
 
    for (int i = 0; i < n; i++) {
        s = 0.0;
        for (int j = 0; j < 4; j++) {
            scanf("%d", &arr[i][j]);
            switch (j) {
                case 1:
                    s += 0.2 * arr[i][j];
                    break;
                case 2:
                    s += 0.1 * arr[i][j];
                    break;
                case 3:
                    s += 0.7 * arr[i][j];
                    break;
            }
        }
        printf("%d %.0lf\n", arr[i][0], s);
        if (s < 60) cnt2++;
        else if (s >= 90) cnt1++;
    }
    printf("%d\n%d", cnt1, cnt2);
 
    return 0;
}