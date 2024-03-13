#include <iostream>
using namespace std;
const int size = 10;

int cnt;
bool state[160005];
char map[size][size];
struct COW
{
    int x, y, direction = 0; 
};

void Move(COW *a) {
    switch (a->direction) {
        case 0:
            if (a->x-1>=0 && map[a->x-1][a->y]!='*') a->x--;
            else a->direction = 1;
            break;
        case 1:
            if (a->y+1<size && map[a->x][a->y+1]!='*') a->y++;
            else a->direction = 2;
            break;
        case 2:
            if (a->x+1<size && map[a->x+1][a->y]!='*') a->x++;
            else a->direction = 3;
            break;
        case 3:
            if (a->y-1>=0 && map[a->x][a->y-1]!='*') a->y--;
            else a->direction = 0;
            break;
    }
}

int main()
{
    COW c, f;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> map[i][j];
            if (map[i][j]=='C') {
                c.x = i;
                c.y = j;
            } else if (map[i][j]=='F') {
                f.x = i;
                f.y = j;
            }
        }
    }
    int flag = 0;
    while (!flag) {
        Move(&c);
        Move(&f);
        int t = c.x + c.y*10 + f.x*100 + f.y*1000 + c.direction*10000 + f.direction*40000;
        if (state[t]) flag = 2;
        state[t] = 1;
        cnt++;
        if (c.x==f.x && c.y==f.y) flag = 1;
    } 
    if (flag==1) cout << cnt << endl;
    else cout << 0 << endl;
    return 0;
}