/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

struct data
{  int no;   
   int num;   
};

typedef struct data DATA;

int number( char * , DATA []);

int main( )
{   
   	DATA b[100];  
   	char sa[500];  
   	int i, n;  
   	cin.getline( sa, sizeof(sa)/sizeof(int) ); 	//输入一行字符 
   	n = number( sa, b ); 						//将sa中的整拆分到结构数组 b 中 
   	for ( i=0; i<n; i++ ) 
       	cout << b[i].num << " " << b[i].no << endl; 
   	return 0;
}


int number( char * str, DATA b[] )
{
    int cnt = 0;
    for ( int i=0; str[i]!='\0'; i++ ) {
        b[cnt].no = b[cnt].num = 0;
        while ( str[i]>='0' && str[i]<='9' ) {
            b[cnt].num = b[cnt].num*10 + str[i++] - '0';
        }
        cnt++; 
    } 
    cnt--;
    for ( int i=1; i<=cnt; i++ ) {
        int mini = 0;
        while ( b[mini].no ) mini++;
        for ( int j=0; j<cnt-1; j++ ) {
            if ( b[mini].num>b[j+1].num  && b[j+1].no==0 ) mini = j+1;
        }
        b[mini].no = i;
    } 
    return cnt; 
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */