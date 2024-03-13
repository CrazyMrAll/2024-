#include <iostream>
using namespace std;
const int MAXN = 100000;
int map[MAXN];

int main()
{
    int T;
    cin >> T;
    for (int m = 0; m < T; m++) {
        int n;
        long long int cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++) 
            scanf("%d", &map[i]);
        for (int i = 0; i < n-1; i++) {
            if (map[i] > map[i+1]) {
                int wall = map[i], deep = map[i+1], right = -1, tmp = 0;
                for (int j = i+2; j < n; j++)
                    if (map[j] > deep) {
                        tmp = right;
                        // cout << j;
                        right = j;
                        if (map[j] >= wall) 
                            break;
                        else 
                            if (map[j] < map[right]) {
                                right = tmp; 
                                break;
                            }              
                    }
                wall = wall<map[right] ? wall : map[right];
                for (int j = i+1; j < right; j++)
                    cnt += wall - map[j];
                if (right != -1)
                    i = right - 1;
                // cout << i << " ";
            }
        }
        printf("%lld\n", cnt);
    }
    return 0;
}