#include<stdio.h>

int main()
{
    int n, x, cnt = 1;
    double m, y;
    scanf("%d %lf", &n, &m);
    for ( x=(int)m/10; x>=0; x-- ) {
        y = ((m-2.5*n) - 7.5*x) / 2.5;
        if ( y==(int)y && y>=0 ) {
        	if ( x+(int)y<=n ) {
				printf("%d:%d,%d,%d\n", cnt, x, (int)y, n-x-(int)y);
	            cnt++;
			}  
        }
    }
    if ( cnt==1 ) printf("Error!\n");
    return 0;
}