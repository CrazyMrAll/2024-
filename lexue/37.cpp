/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
#include <cmath>
using namespace std;

int * input( int );    		
int  PrimCount( int *, int );	
bool isPrim( int ); 

/*
int * input(int n) // 输入n个整数保存在动态申请的空间中 
{
// n：需要处理的整数数量 
// 函数功能：申请存储n个整数的空间，读入n个整数保存在该空间中 
// 函数返回值：指向该内存空间的指针 

}

int PrimCount( int *p, int n)  // 统计n个整数中的素数数量 
{
// p：指向待统计的数组首地址 
// n：数组中保存的数据数量 
// 函数功能：统计指针p所指空间中素数的数量 
// 函数返回值：统计结果

}
*/

bool isPrim(int x)
{	int i;
	if ( x==2 ) return true;		// 是素数，返回1
	if ( x<=1 || x%2==0 )	return false;	// 不是素数，返回0 
	for ( i=3; i<=sqrt(x); i+=2 )
		if ( x%i==0 )	return false;   // 不是素数，返回0 
	return true;			// 是素数，返回1 
}

int main()
{	int n, count, *p;

	cin >> n; 			// 接受整数数量n
	p = input( n );  	// 调用函数输入n个整数 
	count = PrimCount( p, n );	// 对素数进行计数 
	cout << "PrimCount=" << count << endl;
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int * input( int n ) {
    int *p = new int(n);
    for ( int i=0; i<n; i++ )
        cin >> p[i];
    return p;
}

int  PrimCount( int *p, int n) {
    int cnt = 0;
    for ( int i=0; i<n; i++ )
        if ( isPrim(p[i]) ) cnt++;
    return cnt;
}