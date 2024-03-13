#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        unsigned long long int x;
        cin >> x;
        cnt = 0;
        if (x)
            x--;
        while (x) {
            x /= 2;
            cnt++;
        }  
        cout << cnt << endl;   
    }
    return 0;
}