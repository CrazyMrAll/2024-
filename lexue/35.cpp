/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

void sort(int *, int, int);
void input(int *, int );
void output(int *, int );

int main()  //输入n（n<100)个整数，按照指定的方式（升序或降序）进行排序
{
	int n, flag, a[100];
	cin >> n >> flag;
	input(a, n);
	sort(a, n, flag); // flag=0：升序，flag=1：降序
	output(a, n);
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void input(int *a, int n){
    for ( int i=0; i<n; i++ )
        cin >> a[i];
}

void output(int *a, int n){
    for ( int i=0; i<n; i++ )
        cout << a[i] << ",";
    cout << endl;
}

void sort(int *a, int n, int flag){
    for ( int i=n-1; i>0; i-- ) {
        for ( int j=0; j<i; j++ ) {
            if ( ((flag) ? a[j]<a[j+1] : a[j]>a[j+1]) ) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}