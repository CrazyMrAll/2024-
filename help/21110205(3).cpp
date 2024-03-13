#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char str1[5];
    char str[101][21]={0};
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
        
        for(int j=0;j<n-2-i;j++)//在这里尝试进行了修改 还是出错
        {
            if(strcmp(str[j],str[j+1])>0)
            {
                strcpy(p,str[j]);strcpy(str[j],str[j+1]);strcpy(str[j+1],p);
            } 
            memset(p,0,21);
        } 
    } 
    for(int i=0;i<n;i++)
    {
        
        
        for(int j=0;str[i][j]!='\0';j++)
        {
            
            if(str[i][j]==1)
            {
                str[i][j]=str1[0];
            }
             else if(str[i][j]==2)
            {
                str[i][j]=str1[1];
            }
            else if(str[i][j]==3)
            {
                str[i][j]=str1[2];
            }
            else if(str[i][j]==4)
            {
                str[i][j]=str1[3];
            }
        }
    }
    for(int i=0;i<n;i++)
    {printf("%s\n",str[i]);}
    return 0;
}
//评测只有两个点通过 其余显示“无效指针”？老师：检查数组大小