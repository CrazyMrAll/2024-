#include <iostream>
using namespace std;

int main()
{
   int n;
   scanf("%d", &n);
   int list[n];
   for ( int i=0; i<n; i++ ) 
      scanf("%d", &list[i]);
   int begin, end, decrease_number, t_begin, t_end, t;
   begin = end = t_begin = t_end = decrease_number = 1;
   t = 0;
   for ( int i=1; i<n; i++ ) {
      int tmp = list[i-1];
      if ( tmp >= list[i] ) {
         if ( decrease_number==1 ) begin=i;
         decrease_number++;
         end = i+1;
      } else {
         if ( t < decrease_number ) {
            t = decrease_number;
            t_begin = begin;
            t_end = end;
         } 
         begin = end = decrease_number = 1;
      }
   }
   if ( t==0 ) printf("%d %d\n", begin, end);
   else printf("%d %d\n", t_begin, t_end);
   return 0;
}