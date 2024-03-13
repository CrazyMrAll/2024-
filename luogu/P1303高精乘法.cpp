#include<iostream>
#include<cstring>
using namespace std;

char a1[10000], b1[10000];
int a[10000], b[10000], c[10000];
int main ()
{
    cin >> a1 >> b1;
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
	printf("lena=%d lenb=%d len=%d\n",lena, lenb, len);
    while ( c[len]==0 && len>1 ) len--;
    for ( int i=len; i>=1; i-- ) cout << c[i];
    return 0;
}