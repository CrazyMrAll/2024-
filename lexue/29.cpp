/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

int main()
{  	int n, s, findf( int );
   	cin >> n;
   	s = findf(n);
   	cout << s << endl;
   	return 0;
}

int findf( int n) { 
    if ( n>=0 && n<=4 ) return 1;
    else if ( n>4 && !(n%2) ) return findf(n-1) + findf(n-3);
    else if ( n>4 && n%2 ) return findf(n-2) + findf(n-4);
    else return -1;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */