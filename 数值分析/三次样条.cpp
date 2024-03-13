#include <iostream>
using namespace std;
#define N 100

int n = 0;
typedef struct Point {
	double x;
	double y;
} point;
void init();//初始化 
void chase();//追赶法
void printresult();
int cmp(const void* point1, const void* point2) {
	return (((point*)point1)->x - ((point*)point2)->x) > 0 ? 1 : 0;
}
point p[N];
double a[N] = {0}, b[N] = {0}, d[N] = {0}, k[N] = {0}, f1[N] = {0}, f2[N] = {0};
//a数组为方程中的λ，b数组为方程中的μ,f1数组为三次样条插值函数各点处的一阶导数 
int main()
{
	init();
	chase();
	printresult();
	return 0;
}
void printresult() {
	printf("结果为\n");
	for(int i = 0; i < n; i++) {
		printf("在区间[%lf,%lf]上，S(x)=%lf+(x-%lf)*%lf+1/6*(x-%lf)(x-%lf)*[S’’(x)+%lf]\n"
		,p[i].x, p[i+1].x, p[i].y, p[i].x, (p[i+1].y-p[i].y)/(p[i+1].x-p[i].x), p[i].x, p[i+1].x,k[i]+k[i+1]);
		printf("其中S''(x)=%lf + %lf*(x-%lf)\n", k[i], (k[i+1]-k[i])/(p[i+1].x-p[i].x),p[i].x);
	}
	return;
}
void chase() {
	double l1[N] = {0}, l2[N] = {0};//l1为对角线的l，l2为左下角的l 
	double u[N] = {0};
	l1[0] = 2;
	u[0] = a[0] / l1[0];
	for(int i = 1; i <= n-1; i++) {
		l2[i] = b[i];
		l1[i] = 2 - l2[i]*u[i-1];
		u[i] = a[i]/l1[i];
	}
	l2[n] = b[n];
	l1[n] = 2-l2[n] * u[n-1];
	
	double z[N] = {0};
	z[0] = d[0]/l1[0];
	for(int i = 1; i <= n; i++)
		z[i] = (d[i]-b[i]*z[i-1])/l1[i];
	k[n] = z[n];
	for(int i = n-1; i >= 0; i--)
		k[i] = z[i]-u[i]*k[i+1];
	return;
}
void init() {
	printf("输入n:\n");
	scanf("%d", &n);
	printf("输入n+1个点的xi和yi,用空格隔开:\n");
	for(int i = 0; i <= n; i++)
		scanf("%lf %lf",&p[i].x,&p[i].y);
	printf("输入端点条件,即两端的一阶导数值:\n");
	scanf("%lf %lf", &f1[0], &f1[n]); 
	qsort(p, n+1, sizeof(p[0]), cmp);//将x从小到大排序 
	for(int i = 1; i <= n-1; i++) {
		a[i] = (p[i+1].x-p[i].x)/(p[i+1].x-p[i-1].x);
		b[i] = (p[i].x-p[i-1].x)/(p[i+1].x-p[i-1].x);
		d[i] = 6 * ( (p[i+1].y - p[i].y)/(p[i+1].x - p[i].x) - (p[i].y - p[i-1].y)/(p[i].x - p[i-1].x) ) /( p[i+1].x - p[i-1].x);
	}
	a[0] = 1;
	b[n] = 1;
	d[0] = 6.0/(p[1].x-p[0].x)*((p[1].y-p[0].y)/(p[1].x-p[0].x) - f1[0]);
	d[n] = 6.0/(p[n].x-p[n-1].x)*(f1[n] - (p[n].y-p[n-1].y)/(p[n].x-p[n-1].x));
	return;
}