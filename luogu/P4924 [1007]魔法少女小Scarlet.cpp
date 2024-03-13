#include<iostream>
using namespace std;
int map[500][500];

int main ()
{
    int n, m;
    cin >> n >> m;
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            map[i][j] = ++k;
    for (int i = 0; i < m; i++) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        x--; y--;
        for (int i = 1; i <= r; i++) {
            int t = 2 * i + 1;
            int tmp[t];
            if (!z) {
                for (int j = 0; j < t - 1; j++) 
                    tmp[j] = map[x-i][y+i-j];
                for (int j = 0; j < t - 1; j++) 
                    map[x-i][y+i-j] = map[x-i+j][y-i];
                for (int j = 0; j < t - 1; j++) 
                    map[x-i+j][y-i] = map[x+i][y-i+j];
                for (int j = 0; j < t - 1; j++)
                    map[x+i][y-i+j] = map[x+i-j][y+i];
                for (int j = 0; j < t - 1; j++)
                    map[x+i-j][y+i] = tmp[j];
            } else {
                for (int j = 0; j < t - 1; j++) 
                    tmp[j] = map[x-i][y-i+j];
                for (int j = 0; j < t - 1; j++)
                    map[x-i][y-i+j] = map[x-i+j][y+i];
                for (int j = 0; j < t - 1; j++)
                    map[x-i+j][y+i] = map[x+i][y+i-j];
                for (int j = 0; j < t - 1; j++)
                    map[x+i][y+i-j] = map[x+i-j][y-i];
                for (int j = 0; j < t - 1; j++)
                    map[x+i-j][y-i] = tmp[j];    
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            cout << map[i][j];
            if ( j!=n-1 ) cout << " ";
        }
        cout << endl;    
    }  
    return 0;
}