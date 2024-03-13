#include <iostream>
#include <string>
using namespace std;

int main()
{
   int m, n;
   scanf("%d %d", &m, &n);
   int direction1 [m], direction2 [n];
   string member[m];
   int task[n];
   for ( int i=0; i<m; i++ ) {
      scanf("%d",&direction1[i]);
      cin >> member[i];
   }
   for ( int i=0; i<n; i++ ) {
      scanf("%d %d",&direction2[i], &task[i]);
   }
   int move = 0;
   for ( int i=0; i<n; i++ ) {
      if ( direction1[move]^direction2[i] == 0 ) move-=task[i];
      else move+=task[i]; 
      while ( move>m-1 ) {move-=m;}
      while ( move<0 ) {move+=m;}
   }
   cout << member[move] << endl;
   return 0;
}