#include <stdio.h>

int main()
{
    int a, b, c;
    int flag = 1;
    scanf("%d %d %d", &a, &b, &c);
    for ( int x=-100; x<=100; x++ ) {
        for ( int y=-100; y<=100; y++ ) {
            int z = -(a*x + b*y) / c;
            if ( z>=-100 && z<=100 )
                if ( (a*x + b*y + c*z == 0) )
                    if ( !(x==0 && y==0 && z==0)) {
                        printf("%d %d %d\n", x, y, z);
                        flag = 0;
                    }
                        
        }
    }
    if ( flag ) printf("No solution\n");
    return 0;
}