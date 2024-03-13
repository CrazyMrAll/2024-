#include<iostream>
using namespace std;
int subcount(const string &str, const string &sub);

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << subcount(s1, s2) << endl;
    return 0;
}

int subcount(const string &str, const string &sub) {
    int max = 0, cnt = 0, lenstr = str.length(), lensub = sub.length();
    for ( int i=0; i<=lenstr-lensub; i++ ) {
        if ( str.substr(i,lensub)==sub ) {
            i += lensub - 1;
            cnt++;
        } else {
            if ( cnt>max ) max=cnt;
            cnt = 0;
        }
    }
    if ( cnt>max ) max=cnt;
    return max;
}