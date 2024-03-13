/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

typedef struct buy
{  char  gname;
   int   sname;
   int   gprice;
} BUY;

int findm( int, int [ ][3], BUY [ ] );

int main( )
{  	int i, j, n, min, price[10][3];
   	BUY scheme[3]={ {'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0} };

   	cin >> n;
   	for( i = 0; i < n; i++ )
		for( j = 0; j < 3; j++ )
	   		cin >> price[i][j];

   	min = findm( n, price, scheme );

   	cout << "Total Money are : " << min <<"\nGoods-Name  Shop-Name  Goods-Price\n";
   	for ( i=0; i<3; i++ )
    	printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice ); //这个应该用C++的语句，不改了 
   	return 0;
}

/* int findm( int n, int gp[ ][3], BUY schm[ ] ) */
int findm( int n, int price[ ][3], BUY scheme[ ] ) {
    int sum, min = INT32_MAX;
    for ( int i=0; i<n; i++ ) {
        int minBNum = 1;
        for ( int j=0; j<n; j++ ) 
            if ( j!=i && price[j][1]<price[minBNum][1] ) minBNum = j;
        int minCNum = 2;
        for ( int k=0; k<n; k++ )
            if ( k!=i && k!=minBNum && price[k][2]<price[minCNum][2] ) minCNum = k;
        sum = price[i][0] + price[minBNum][1] + price[minCNum][2];
        if ( sum<min ) {
            scheme[0].sname = i + 1;
            scheme[1].sname = minBNum + 1;
            scheme[2].sname = minCNum + 1;
            scheme[0].gprice = price[i][0];
            scheme[1].gprice = price[minBNum][1];
            scheme[2].gprice = price[minCNum][2];
            min = sum;
        }
    }
    return min;
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */