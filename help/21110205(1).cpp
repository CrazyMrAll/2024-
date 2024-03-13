#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char str1[5];
    char str[101][21];
    char p[21];

    scanf("%d",&n); 
    scanf("%s",str1);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str[i]);
        
        for(int j=0;str[i][j]!='\0';j++)
        {
            
            if(str[i][j]==str1[0])
            {
                str[i][j]=1;
            }
             else if(str[i][j]==str1[1])
            {
                str[i][j]=2;
            }
            else if(str[i][j]==str1[2])
            {
                str[i][j]=3;
            }
            else if(str[i][j]==str1[3])
            {
                str[i][j]=4;
            }
        }
    }
    for (int i=0;i<n-1;i++)
    {
        
        for(int j=0;j<n-1-i;j++)
        {
            if(strcmp(str[i],str[i+1])>0)
            {
                strcpy(p,str[i]);strcpy(str[i],str[i+1]);strcpy(str[i+1],p);
            } 
            //p={'\0'};
        } 
    } 
    printf("%s",str);
    return 0;
}
