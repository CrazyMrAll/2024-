/*2151285 王宇莹 信03*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void area(int n, double l[], double x[], double y[])
{
	double cosa[6], sina[6], s=0;
	int i;
	for (i = 0; i < n - 2; i++) {
		cosa[i] = pow(l[i], 2) + pow(l[i + 1], 2) - pow(x[i + 1] - x[i], 2) - pow(y[i + 1] - y[i], 2);
		sina[i] = sqrt(1 - cosa[i]);
		s += 0.5 * sina[i] * l[i] * l[i + 1];
	}
	cout << "凸" << n << "边形的面积=" << s << endl;
}

void polygon(int n, double x[], double y[])
{
	int m, t,q;
	double k, p;
	for (m = 0; m < n - 1; m++) {
		q = m;
		for (t = m + 1; t < n; t++) {
			if (x[t] < x[q])
				q = t;
			k = x[q];
			p = y[q];
			x[q] = x[m];
			y[q] = y[m];
			x[m] = k;
			y[m] = p;
		}
	}

	double y0,x0,r;
	for (m = 0; m < n; m++) {
		y0 = y[0];
		x0 = x[0];
		if (y[m] < y[0]) {
			y0 = y[m];
			y[m] = y[n - 1];
			y[n - 1] = y0;
			x0 = x[m];
			x[m] = x[n - 1];
			x[n - 1] = x0;
		}
	}


	double l[6];
	for (m = 0; m < n - 1; m++) {
		l[m] =sqrt( pow(x[m] - x0, 2)+pow((y[m]-y0),2));
	}

	bool ret = 1;
	for (m = 1; m < n - 1; m++) {
		if (l[m] > l[m - 1]) {
			if(m==1)
				continue;
			else {
				if (l[m - 1] < l[m - 2]) {
					ret = 0;;
					break;
				}
			}
		}
	}

	if (ret)
		area(n,l,x,y);
	else
		cout << "不是凸" << n << "边形" << endl;
}


int main()
{
	int n,n1;
	double x[7], y[7],a[7];
	int i,j;
	cout << "请输入多边形的顶点数量(4-7)" << endl;
	cin >> n;
	n1 = n;
	while (cin.fail() || n < 4 || n>7) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> n;
	}
	for (i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个顶点的坐标：" << endl;
		cin >> x[i] >> y[i];
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "请输入第" << i + 1 << "个顶点的坐标：" << endl;
			cin >> x[i] >> y[i];
		}
	}
	for (i = 0; i < n; i++) {
		if (i < n - 1) {
			a[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
		}
		else
			a[i] = (y[i] - y[0]) / (x[i] - x[0]);
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (a[i] == a[j])
				n1--;
		}
	}
	polygon(n1, x, y);
}