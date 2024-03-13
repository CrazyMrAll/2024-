#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 201
char s[MAXN];

bool isRight(int i, int j) {
    bool flag = 1;
    int len = j - i + 1, middle = (i+j+1) / 2;
    for ( int i=1; i<=len/2; i++ ) {
        if ( !((s[middle-i]>='a' && s[middle-i]<='z') || (s[middle-i]>='A' && s[middle-i]<='Z')) ||
            !((s[middle+i-!(len%2)]>='a' && s[middle+i-!(len%2)]<='z') || (s[middle+i-!(len%2)]>='A' && s[middle+i-!(len%2)]<='Z')) ||
            s[middle-i]!=s[middle+i-!(len%2)] ) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    cin >> s;
    int len = strlen(s);
    int begin = 0, end = len - 1, last = 0;
    for ( ; begin<end; begin++ ) {
        if ( begin>last ) last = begin;
        for ( ; end>last && end<len; end-- ) {
            if ( isRight(begin,end) ) {
                for ( int i=begin; i<=end; i++ )
                    cout << s[i];
                cout << endl;
                last = end;
                break;
            }
        }
        end = len - 1;
    }
    return 0;
}