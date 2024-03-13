#include <iostream>
using namespace std;

struct Point
{
    int ways = 0;
    int ans = 0;
};
Point map[100];

int choose(int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else return (a<b) ? a : b;
}

int main()
{
    int m, n, ms, ns;
    cin >> m >> n >> ms >> ns;
    map[0].ans = 0;
    map[0].ways = 1;
    for (int i = 0; i <= n; i++) {
        map[0].ans += i;
        for ( int j = 0; j <= m; j++) {
            if (j-1 >= 0) {
                map[j].ans = choose(map[j-1].ans, map[j].ans) + i;
                map[j].ways = map[j-1].ways + map[j].ways;
            }
            if (i == ns && j == ms) {
                map[j].ways = 0;
                map[j].ans = 0;
            }
        }
    }
    cout << "ways=" << map[m].ways << " ans=" << map[m].ans;
    return 0;
}