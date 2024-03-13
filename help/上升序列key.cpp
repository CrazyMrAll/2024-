#include<stdio.h>
int a[1000]={0};
int cnt[1000]={0};
int maxv=1;
int n;
int max(int x,int y)
{
    return (x>y?x:y);
}
void maxcnt(int r)
{   for(int i=r-1;i>0;i--)
    {
        if(a[i]<a[r])
        {
        cnt[i]=max(cnt[i],cnt[r]+1);
        //break;
        }
    }
    return;
}
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[i]=1;
    }
    for(int i=n;i>0;i--)
    {
        maxcnt(i);
        for(int i=1;i<=n;i++)
            printf("%d ", cnt[i]);
        printf("\n");
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>maxv)
        {maxv=cnt[i];}
    }
    printf("%d",maxv);
    return 0;
}