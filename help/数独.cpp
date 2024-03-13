#include <iostream>
using namespace std;

bool isLittleRight (int map[][9], int x, int y) {
    bool allFlag = 1, numFlag[10];
    for ( int i=1; i<=9; i++ )
        numFlag[i] = 1;
    for ( int i=x; i<x+3; i++ ) 
        for ( int j=y; j<y+3; j++ ) 
            numFlag[map[i][j]] = 0;
    for ( int i=1; i<=9 && allFlag; i++ ) {
        if ( numFlag[i] ) allFlag = 0;
    }
    return allFlag;
}

bool isXRight (int map[][9], int x) {
    bool allFlag = 1, numFlag[10];
    for ( int i=1; i<=9; i++ )
        numFlag[i] = 1;
    for ( int j=0; j<9; j++ ) 
        numFlag[map[x][j]] = 0;
    for ( int i=1; i<=9 && allFlag; i++ ) {
        if ( numFlag[i] ) allFlag = 0;
    }
    return allFlag;
}

bool isYRight (int map[][9], int y) {
    bool allFlag = 1, numFlag[10];
    for ( int i=1; i<=9; i++ )
        numFlag[i] = 1;
    for ( int i=0; i<9; i++ ) 
        numFlag[map[i][y]] = 0;
    for ( int i=1; i<=9 && allFlag; i++ ) {
        if ( numFlag[i] ) allFlag = 0;
    }
    return allFlag;
}

int main()
{
    int map[9][9];
    bool mapFlag = 1;
    for ( int i=0; i<9; i++ ) {
        for ( int j=0; j<9; j++ ) {
            cin >> map[i][j];
        }
    }
    for ( int i=0; i<9 && mapFlag; i++ ) {
        if ( isXRight(map,i) ) continue;
        else mapFlag = 0;
    }
    if ( mapFlag )
        for ( int j=0; j<9 && mapFlag; j++ ) {
            if ( isYRight(map,j) ) continue;
            else mapFlag = 0;
        }
    if ( mapFlag )
        for ( int i=0; i<=6 && mapFlag; i+=3 ) {
            for ( int j=0; j<=6 && mapFlag; j+=3 ) {
                if ( isLittleRight(map,i,j) ) continue;
                else mapFlag = 0;
            }
        }
    if ( mapFlag ) cout << "正确" << endl;
    else cout << "不正确" << endl;
    return 0;
}