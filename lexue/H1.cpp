#include <iostream>
using namespace std;

void jiong(int);
int blank = 0;

int main()
{
   int n;
   cin >> n;
   jiong(n);
   return 0;
}

void jiong(int n)
{
   int i, j, wide, t, p, q;
   i = 1;
   for ( wide=8; i<n; i++) {
      wide *= 2;
   }
   char a[wide][wide];
   for ( t=wide; wide>=8; wide/=2 ) {
      for ( i=0; i<wide; i++ ) {
         for ( j=0; j<wide; j++ ) {
            p = i+blank*2*(wide!=t);
            q = j+blank*(wide!=t);
            if ( (i==0 && (j==0 || j==wide-1)) || (i==wide-1 && (j==0 || j==wide-1)) || (i==wide/2 && (j==wide*3/4-1 || j==wide/4)) || (i==wide-1 && (j==wide*3/4-1 || j==wide/4)) )
               a[p][q] = '+' ;
            else if ( i+j==wide/2 && i>1 && j>1 )
               a[p][q] = '/' ;
            else if ( j-i==wide/2-1 && j>wide/2 && j<wide-2)
               a[p][q] = '\\';
            else if ( ((j==0 || j==wide-1) && (i!=0 || i!=wide-1)) || ((j==wide*3/4-1 || j==wide/4 ) && (i>wide/2 && i<wide-1)) )
               a[p][q] = '|' ;
            else if ( (i==0 && j!=0 && j!=wide-1) || (i==wide-1 && j!=wide*3/4-1 && j!=wide/4) || (i==wide/2 && j<wide*3/4-1 && j>wide/4)) 
               a[p][q] = '-' ;
            else
               a[p][q] = ' ' ;
         }
      }
      blank += wide/4;
   }
   for ( i=0; i<t; i++ ) {
      for ( j=0; j<t; j++ ) {
         cout << a[i][j];
      }
      cout << endl;
   }
}