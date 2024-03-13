/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

void sort(int *, int, int (*)(int, int));
void input(int *, int );
void output(int *, int );
int up(int, int);    	// a<b:1； a=b:0；a>b:-1反序 
int down(int, int);		// a<b:-1；a=b:0；a>b:1 正序 

int main()
{
	int n, flag, a[100];
	cin >> n >> flag;	// n：数组元素数量； flag=0：升序，flag=1：降序 
	input(a, n);
	if ( flag==0 )
		sort(a, n, up); 	// 0：升序，1：降序
	else 
		sort(a, n, down);
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

void sort(int *a, int n, int (*pf)(int, int)){
    for ( int i=n-1; i>0; i-- ) {
        bool flag = 1;
        for ( int j=0; j<i; j++ ) {
            if ( pf(a[j],a[j+1]) ) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                flag = 0;
            }
        }
        if ( flag ) break;
    }
}

int up(int a, int b){
    if ( a>b ) return 1;
    else return 0;
}

int down(int a, int b){
    if ( a<b ) return 1;
    else return 0;
}