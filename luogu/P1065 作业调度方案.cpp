#include <iostream>
using namespace std;

int m, n;
struct PART
{
    int machine[20], time[20];
};
PART part[20];
int solution[20][20], timemax[20], time[20];

int main()
{
    cin >> m >> n;
    int order[400], t = m * n, total = 0;
    for (int i = 0; i < t; ++i)
        cin >> order[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> part[i].machine[j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> part[i].time[j];
    for (int i = 0; i < t; ++i) {
        bool flag = 1;
        int item = order[i];
        int j = 1, tmptime = 0;
        for ( ; j <= m; ++j)
            if (part[item].machine[j]) break;
        for (int k = 1; flag; ++k) {
            if (timemax[k] < solution[part[item].machine[j]][k]) timemax[k] = solution[part[item].machine[j]][k];
            if (!solution[part[item].machine[j]][k]) {
                if (time[item]<=total) {
                    solution[part[item].machine[j]][k] = part[item].time[j];
                    time[item] += part[item].time[j];
                    flag = 0;
                }
            }
            tmptime += solution[part[item].machine[j]][k];
        }
        if (total <= tmptime) total = tmptime;
        part[item].machine[j] = 0;
    }
    cout << total;
    return 0;
}