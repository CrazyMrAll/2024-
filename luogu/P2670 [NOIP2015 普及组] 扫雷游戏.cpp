#include <iostream>
using namespace std;

int main()
{
   int m, n, cnt = 1;
   while ( cin >> m >> n && m!=0 && n!=0) {
      if ( cnt!=1 ) cout << endl;
      char s[m][n];
      int map[m][n];
      for ( int i=0; i<m; i++ ) {
         for ( int j=0; j<n; j++ ) {
            map[i][j] = 0;
         }
      }
      for ( int i=0; i<m; i++ ) {
         for ( int j=0; j<n; j++ ) {
            cin >> s[i][j];
         }
      }
      for ( int i=0; i<m; i++ ) {
         for ( int j=0; j<n; j++ ) {
            if ( s[i][j]=='*' ) {
                  if ( i!=0 ) {
                     if ( j!=0 ) map[i-1][j-1]++;
                     map[i-1][j]++;
                     if ( j!=n-1 ) map[i-1][j+1]++;
                  }
                  if ( j!=0 ) map[i][j-1]++;
                  if ( j!=n-1 ) map[i][j+1]++;
                  if ( i!=m-1 ) {
                     if ( j!=0 ) map[i+1][j-1]++;
                     map[i+1][j]++;
                     if ( j!=n-1 ) map[i+1][j+1]++;
                  }
            }
         }
      }
      printf("Field #%d:\n", cnt);
      for ( int i=0; i<m; i++ ) {
         for ( int j=0; j<n; j++ ) {
            if ( s[i][j]=='*' ) {
               map[i][j] = '*';
               cout << s[i][j];
            } else cout << map[i][j];
         }
         cout << endl;
      }
      cnt++;
   }
   
   return 0;
}