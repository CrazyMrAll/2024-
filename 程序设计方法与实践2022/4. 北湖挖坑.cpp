#include <iostream>
using namespace std;
const int MAXN = 100000;
int map[MAXN+1];

int main()
{
    int n, h;
    unsigned long long cnt = 0;
    cin >> n >> h;
    for (int i = 0; i <= n; i++) {
        if (i == n) map[i] = h;
        else cin >> map[i];
        if (i) {
            int t = map[i] - map[i-1];
            if (t > 0)
                cnt += t;
        }
    }
    cout << cnt << endl;
    return 0;
}