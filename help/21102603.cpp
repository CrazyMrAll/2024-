#include <stdio.h>
#include <ctype.h>
int main()
{
    int a,b,c,x,y,z;
    scanf("%d %d %d",&a,&b,&c);
    
    bool s=false;
    for(x=-100;x<=100;x++)
    {
        for(y=-100;y<=100;y++)
        {
            for(z=-100;z<=100;z++)
            if(a*x+b*y+c*z==0&&x!=0&&y!=0&&z!=0)
            {
                printf("%d %d %d\n",x,y,z);
                s=true;
            }
        }
            
    }
    if(s==false)
    {
        printf("%s","no solution");
    }
    return 0;

}