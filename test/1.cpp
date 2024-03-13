#include <iostream>
using namespace std;

int q[101];
int min(int a, int b) {
    return (a<b) ? a : b;
}

int main() 
{
    int n, ans = 0;
    cin >> n;
    for (int i=0; i<n; ++i) 
        cin >> q[i];
    for (int i=0; i<n; ++i) {
        if (!q[i]) {
            if (i==0) ans+=q[1];
            else if (i==n-1) ans+=q[n-2];
            else ans+=min(q[i-1], q[i+1]);
        }
    }
    cout << ans << endl;
    return 0;
}