#include<stdio.h>

int main()
{
    int n;
    char str1[5];
    int str[101][21];

    scanf("%d",&n);
    scanf("%s",str1);

    for(int i=0,j=0;i<n;i++)
    {
        while( scanf("%c",&str[i][j]) && str[i][j]!='\n' )
        {
                
            if(str[i][j]==str1[0]) {str[i][j]=1;}
            else if(str[i][j]==str1[1]) {str[i][j]=2;}
            else if(str[i][j]==str1[2]){str[i][j]=3;}
            else if(str[i][j]==str1[3]){str[i][j]=4;}
            j++;
        }
    }

    printf("%s",str);
    return 0;
}