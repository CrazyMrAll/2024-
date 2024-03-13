//选数
//从四位选第一位数，标记该数，并计算和。
//从四位选第二位数，并且没被标记过，并计算与第一位的和。
//从四位选第三位数，并且没被标记过，并计算与前俩位的和。
//.....直到选到第n位数，判断是否为素数，满足条件的话ans+1.
//n=4,k=3,4个整数分别为3,7,12,19
#include<iostream>
#include<cmath>
using namespace std;

int number[25];//存数字
bool mark[10000000];//标记
int n, k, ans;//输入n个数字，选k个相加,ans计算素数的情况

void Dfs_(int s, int sum,int i);//s用来记住选了几位数，sum用来计算选数的和，i用来记录选到了第几位数。
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> number[i];//存入输入的数字。
    Dfs_(1, 0,1);//从第一个数字开始选
    cout << ans;
}
void Dfs_(int s, int sum,int i)
{
    if (s == k + 1)
    {
        int j;
        for (j = 2; j <= sum; j++)//判断和是否为素数
        {
            if (sum % j == 0&& sum != 1&& sum != 2)
                break;
            if (j == sum - 1||sum==1||sum==2)
            {
                ans++;
            }
        }
        return;//回溯
    }
    for (; i <= n; i++)//选下一位合法数
        if (mark[i] == false)
        {
            mark[i] = true;
            Dfs_(s + 1, sum + number[i],i);
            mark[i] = false;
        }
}
