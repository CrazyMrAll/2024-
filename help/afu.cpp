#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
 int n;
 scanf("%d",&n);
 int a[n][n];
 int k=1;
 for(int i=0;i<n*n;i++)
 {
  {
   for(int j=0;j<n*n;j++)
   {
    a[i][j]=k;
    k++; 
   }
  }
 }
 
 for(int i=0;i<n*n;i++)
 {
  {
   for(int j=0;j<n*n;j++)
   {
    printf(" %d",a[i][j]);
   }
  }
 }
 return 0;
}