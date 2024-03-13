#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <windows.h> //取系统时间
using namespace std;

int N[100001] = {0, 1};

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* program begin */
    int xmax, ymax, zmax, xmin, ymin, zmin, x[4], y[4], z[4], xresult[500], yresult[500], zresult[500], min, cnt = 0;
    xmax = ymax = zmax = INT_MIN;
    min = xmin = ymin = zmin = INT_MAX;
    for ( int i=0; i<4; i++ ) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
        if ( xmax<x[i] ) xmax=x[i];
        if ( ymax<y[i] ) ymax=y[i];
        if ( zmax<z[i] ) zmax=z[i];
        if ( xmin>x[i] ) xmin=x[i];
        if ( ymin>y[i] ) ymin=y[i];
        if ( zmin>z[i] ) zmin=z[i];
    }
    for ( int i=xmin; i<=xmax; i++ ) {
        for ( int j=ymin; j<=ymax; j++) {
            for ( int k=zmin; k<=zmax; k++ ) {
                int tmp = 0;
                for ( int q=0; q<4; q++ ) {
                    tmp += (int)sqrt( pow(i-x[q], 2) + pow(j-y[q], 2) + pow(k-z[q], 2) );
                }
                if ( tmp<min ) {
                    min = tmp;
                    cnt = 0; 
                } else if ( tmp==min )cnt++;
                else continue;
                xresult[cnt] = i;
                yresult[cnt] = j;
                zresult[cnt] = k; 
            }
        }
    }
    printf("%d %d\n", min, cnt+1);
    for ( int i=0; i<=cnt; i++ ) {
        printf("%d %d %d\n", xresult[i], yresult[i], zresult[i]);
    }
	/* program end */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
