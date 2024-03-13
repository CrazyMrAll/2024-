#include<iostream>
using namespace std;
int main()
{
	int c=0,t=1,i,j;
	long long m,n,r;
	long long x,y;
	long long a[21]={0};
	long long b[21]={0};
	cin>>c;
	while(t<=c)
	{
	cin>>a[t]>>b[t];
	t=t+1;
	}
	for(i=1;i<=c;i++)
	{
	for(j=1;j<=c;j++)
	{
		m=a[i];
		n=b[j];
		while(m%n!=0)
		{
			r = m%n;
			m = n;
			n = r;
		}
		a[i]=a[i]/n;
		b[j]=b[j]/n;
	}
	}
	x=1;
	y=1; 
	for(i=1;i<=c;i++)
	{
		x=x*a[i];
	}
	for(j=1;j<=c;j++)
	y=y*b[j];
	if(y==1)
	cout<<x<<endl;
	else
	cout<<x<<"/"<<y<<endl;
	return 0;
 }