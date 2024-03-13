#include <iostream>
using namespace std;

int maxv, now, m, n;
char map[100][100];

void search(int x, int y);
void clear(int x, int y);

int main()
{
    int h;
    cin >> m >> n >> h;
    for (int i=0; i<m; ++i) 
        for ( int j=0; j<n; ++j)
            map[i][j] = '_';
    for (int i=0; i<h; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        if (t==0) {
            if (map[x][y]=='x') clear(x, y);
            now++;
            map[x][y] = '@';
            search(x, y);
        } else {
            map[x][y] = '_';
            now--;
            clear(x, y);
        }
        if (now>maxv) maxv=now;
        // for (int i=0; i<m; ++i) {
        //     for (int j=0; j<n; ++j)
        //         cout << map[i][j];
        //     cout << endl;
        // }
    }
    cout << maxv << endl << now << endl;
    return 0;
}

void search(int x, int y) {
    int t = 0, flag[4] = {0}, bigflag = 0, FLAG = 0;
    while (!bigflag) {
        t++;
        if (y-t>=0 && map[x][y-t]=='@') {bigflag=FLAG=flag[0]=1;}
        if (y+t<n && map[x][y+t]=='@') {bigflag=FLAG=flag[1]=1;}
        if (x-t>=0 && map[x-t][y]=='@') {bigflag=FLAG=flag[2]=1;}
        if (x+t<m && map[x+t][y]=='@') {bigflag=FLAG=flag[3]=1;}
        if (y-t<0 && y+t>=n && x-t<0 && x+t>=m) bigflag=1;
    }
    if (FLAG) {
        for (int i=1; i<t; ++i) {
            if (flag[0]) {map[x][y-i]='x';now++;}
            if (flag[1]) {map[x][y+i]='x';now++;}
            if (flag[2]) {map[x-i][y]='x';now++;}
            if (flag[3]) {map[x+i][y]='x';now++;}
        }
    }
    
}

void clear(int x, int y) {
    int bigflag = 4, flag[4] = {1, 1, 1, 1};
    if ((y-1>=0 && map[x][y-1]=='_') || y-1<0) {flag[0]=0;bigflag--;}
    if ((y+1<n && map[x][y+1]=='_') || y+1>=n) {flag[1]=0;bigflag--;}
    if ((x-1>=0 && map[x-1][y]=='_') || x-1<0) {flag[2]=0;bigflag--;}
    if ((x+1<m && map[x+1][y]=='_') || x+1>=m) {flag[3]=0;bigflag--;}
    for (int t=1; bigflag; ++t) {
        if (flag[0]) {
            if (y-t>=0 && map[x][y-t]=='x') {map[x][y-t]='_';now--;}
            else if (y-t<0 || map[x][y-t]=='@') {bigflag--;flag[0]=0;}
        }
        if (flag[1]) {
            if (y+t<n && map[x][y+t]=='x') {map[x][y+t]='_';now--;}
            else if (y+t>=n || map[x][y+t]=='@') {bigflag--;flag[1]=0;}
        }
        if (flag[2]) {
            if (flag[2] && x-t>=0 && map[x-t][y]=='x') {map[x-t][y]='_';now--;}
            else if (x-t<0 || map[x-t][y]=='@') {bigflag--;flag[2]=0;}
        }
        if (flag[3]) {
            if (x+t<m && map[x+t][y]=='x') {map[x+t][y]='_';now--;}
            else if (x+t>=m || map[x+t][y]=='@') {bigflag--;flag[3]=0;}
        }    
    }
}