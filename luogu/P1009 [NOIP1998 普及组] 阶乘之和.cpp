#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 2

char a1[10000], b1[10000];
int a[10000], b[10000], c[10000];
void AmulB ( char a1[], char b1[] ) {
    int lena = strlen(a1);
	int lenb = strlen(b1);
    for ( int i=1; i<=lena; i++ ) a[i] = a1[lena-i] - '0';
    for ( int i=1; i<=lenb; i++ ) b[i] = b1[lenb-i] - '0';
	for ( int i=1; i<=lenb; i++ )
	    for( int j=1; j<=lena; j++ )
	        c[i+j-1] += a[j] * b[i];
    for ( int i=1; i<lena+lenb; i++ ) 
	    if(c[i]>9) {
		c[i+1] += c[i] / 10;
		c[i] %= 10;
	}
	int len = lena + lenb;
    while ( c[len]==0 && len>1 ) len--;
    for ( int i=len; i>=1; i-- ) cout << c[i];
}

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

int main ()
{
    char n[MAXN];
    cin >> n;
    int len_n =  strlen(n);
    for ( int i=0; i<len_n; i++ ) {
        a1[i] = n[i] - '0';
    }
    int lena = strlen(a1);
    
    return 0;
}