#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
using namespace std;
priority_queue<int>q;
int main()
{
	int n, i, x, sum = 0, t;
	cin >> n;
	for (i = 0; i<n; i++)
	{
		cin >> x;
		q.push(-x);//存入负值
	}
    //一共选n-1次
	for (i = 1; i<n; i++)
	{
		t = q.top();
		sum -= q.top();
		q.pop();
		t += q.top();
		sum -= q.top();
		q.pop();
		q.push(t);
	}
	cout <<"WPL="<< sum << endl;
	//system("pause");
	return 0;
}
