#include<string>
#include<iostream>
using namespace std;

string add(string str1,string str2)
{
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    if ( len1 < len2 ) {
        for ( int i=1; i<=len2-len1; i++ )
           str1 = "0" + str1;
    }
    else {
        for ( int i=1; i<=len1-len2; i++ )
           str2 = "0" + str2;
    }
    len1 = str1.length();
    int next = 0;
    int temp;
    for ( int i=len1-1; i>=0; i-- ) {
        temp = str1[i] - '0' + str2[i] - '0' + next;
        next = temp / 10;
        temp %= 10;
        str = char(temp+'0') + str;
    }
    if ( next != 0 )  str = char(next+'0') + str;
    return str;
}

int main()
{
    string str1,str2;
    cin >> str1 >> str2;
    cout << add(str1,str2) << endl;
    return 0;
}