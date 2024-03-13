//全排列问题：
//思想：一次选一个数，并标记该数，再选第二个数，再标记，直到选到n+1个数停止，然后回溯。
#include<iostream>
using namespace std;
int number[100];//存答案
bool mark[100];//标记
int n;
void Dfs_(int ans);

int main()
{
    cin >> n;
    Dfs_(1);//从第一个数开始选
}
void Dfs_(int ans)
{
    if (ans == n + 1)//递归基线条件，选到第n+1个数停止
    {
        for (int j = 1; j <= n; j++)
            cout << number[j];//输出答案
        cout << endl;
        return;//回溯
    }
    for (int i = 1; i <= n; i++)
        if (mark[i] == false)//如果没被标记过
        {
            number[ans] = i;
            mark[i] = true;//对该数字标记
            Dfs_(ans + 1);//找下一个数
            mark[i] = false;//取消这一步的标记
        }
}