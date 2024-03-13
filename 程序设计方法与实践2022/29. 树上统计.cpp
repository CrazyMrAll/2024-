#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
const int MAXN = 200005;
vector<list<int>> v(MAXN);
queue<int> q;
int a[MAXN], b[MAXN];
long long ans, t, o;
bool d;

int main()
{
    int n;
    scanf("%d", &n);
    for (register int i = 0; i < n-1; i++) {
        scanf("%d %d", &a[i], &b[i]);
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    for (register int j = 0; j < n-1; j++) {
        t = o = 0, d = 0;
        q.push(a[j]);
        t++;
        int f, ba;
        while (!q.empty()) {
            ba = q.back();
            while (1) {
                f = q.front();
                printf("Pop %d\n", f);
                q.pop();
                if (d) o++;
                for (auto i = v[f].begin(); i != v[f].end(); i++) 
                    if (*i != f && *i != b[j]) {
                        printf("Push %d\n", *i);
                        q.push(*i);
                        t++;
                    }
                if (f == ba) {
                    d ^= 1;
                    break;
                }
            }
        }

        d = 0;
        q.push(b[j]);
        while (!q.empty()) {
            ba = q.back();
            while (1) {
                f = q.front();
                printf("Pop %d\n", f);
                q.pop();
                if (d) o++;
                for (auto i = v[f].begin(); i != v[f].end(); i++) 
                    if (*i != f) {
                        printf("Push %d\n", *i);
                        q.push(*i);
                    }
                if (f == ba) {
                    d ^= 1;
                    break;
                }
            }
        }
        ans += (t * (n-t) + o) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}