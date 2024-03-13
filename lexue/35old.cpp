/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

void swap(int &, int &);
void input(int *, int );
void output(int *, int );
int main()
{
// 分别将输入2*n（n<100)个整数保存在两个数组中，比较对应
// 数组元素，将较小值保存在a数组中，较大值存入数组b中 
	int n, k, a[100], b[100];
	cin >> n;
	input(a, n);
	input(b, n);
	for ( k=0; k<n; k++ )
	{	if( a[k] > b[k] ) 
			swap(a[k], b[k]);
	}
	output(a, n);
	output(b, n); 
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void swap(int &m, int &n){
    int t = m;
    m = n;
    n = t;
}

void input(int *a, int n){
    for ( int i=0; i<n; i++ )
        cin >> a[i];
}

void output(int *a, int n){
    for ( int i=0; i<n; i++ )
        cout << a[i] << ",";
    cout << endl;
}