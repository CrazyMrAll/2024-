/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
#include <math.h>
using namespace std; 

int main()
{
	int n, m;
	int isPrime( int );  // 若是素数函数isPrim返回1，否则返回0 
	
	cin >> n >> m;
	while ( n < m-1 )
	{
		if ( isPrime(n) && isPrime(n+2) )
		{
			cout << n << "," << n+2 << endl;
		}
		n++;
	}
	return 0;
}

int isPrime(int x)
{
	if ( !(x%2) ) return 0;
    else {
        bool flag = 1;
        for ( int i=3; i<=(int)sqrt(x); i+=2 ) {
            if ( !(x%i) ) {flag=0;break;}
        }
        if ( flag ) return 1;
        else return 0;
    }
} 


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */