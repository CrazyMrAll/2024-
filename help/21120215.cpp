#include<stdio.h>
char map[103][103]={{'\0'}};
int state[103][103]={{0}};//状态数组，没有被覆盖时为0
int s=0;
int maxv=0;
int count=0;
//cover函数：覆盖计算小岛面积
void cover(char p,int r,int l)
{
    bool goto1=(map[r-1][l]=='I'&&!state[r-1][l]);//从上方顺时针设定状态
    bool goto2=(map[r-1][l+1]=='I'&&!state[r-1][l+1]);
    bool goto3=(map[r][l+1]=='I'&&!state[r][l+1]);
    bool goto4=(map[r+1][l+1]=='I'&&!state[r+1][l+1]);
    bool goto5=(map[r+1][l]=='I'&&!state[r+1][l]);
    bool goto6=(map[r+1][l-1]=='I'&&!state[r+1][l-1]);
    bool goto7=(map[r][l-1]=='I'&&!state[r][l-1]);
    bool goto8=(map[r-1][l-1]=='I'&&!state[r-1][l-1]);

    if(state[r][l]==0&&map[r][l]=='I')
    {
    s++;
    state[r][l]=1;
    //printf("%d,%d\n",r,l);
    }
    if(s>maxv)
    {
        maxv=s;
    }
    

    if (!(goto1||goto2||goto3||goto4||goto5||goto6||goto7||goto8))
    {
        return;
    }

    if(goto1){cover(map[r-1][l],r-1,l);}
    if(goto2){cover(map[r-1][l+1],r-1,l+1);}
    if(goto3){cover(map[r][l+1],r,l+1);}
    if(goto4){cover(map[r+1][l+1],r+1,l+1);}
    if(goto5){cover(map[r+1][l],r+1,l);}
    if(goto6){cover(map[r+1][l-1],r+1,l-1);}
    if(goto7){cover(map[r][l-1],r,l-1);}
    if(goto7){cover(map[r-1][l-1],r-1,l-1);}
}

int main()
{
    
    int m,n;

    scanf("%d %d",&m,&n);
    getchar();
    //加边，防止出现指针越界
    for(int i=0;i<=m+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        {
            if(i==0||j==0||i==m+1||j==n+1)
            {
                map[i][j]='.';
            }
        }  
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            scanf("%c",&map[i][j]);
        }
        if(i==m){continue;}
        getchar();
    }
    for (int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if (state[i][j]!=0||map[i][j]!='I')
            {
                continue;
            }
            count++;
            s=0;
            cover(map[i][j],i,j);
        }
    }
    printf("%d %d",count,maxv);
    return 0;
}