#include<iostream>
using namespace std;

//练习案例2：点和圆的关系
//设计一个圆形类和一个点类，计算点和圆的关系

//创建点类 
class point
{
public:
	//设置XY 
	void setXY(int &X, int &Y)
	{
		m_X = X;
		m_Y = Y;
	}
	//获取X
	int getX()
	{
		return m_X;
	} 
	//获取Y
	int getY()
	{
		return m_Y;
	} 
	
private:
	int m_X;
	int m_Y;
}; 

//创建圆类 
class circle
{
public:
	//设置半径
	void setR(int &r)
	{
		m_R = r;
	}
	//获取半径
	int getR()
	{
		return m_R;
	}
	//设置圆心
	void setcenter(point center)
	{
		m_center = center;
	}
	//获取圆心
	point getcenter()
	{
		return m_center;
	}
	
private:
	int m_R;
	point m_center;

//判断点和圆关系
public:
    void ifincircle(circle &c,point &p)
    {
	    //两点之间距离的平方
	    int distance=
	        (c.getcenter().getX()-p.getX())*(c.getcenter().getX()-p.getX())+
	        (c.getcenter().getY()-p.getY())*(c.getcenter().getY()-p.getY());
	    //计算半径的平方
	    int Rdistance = c.getR() * c.getR() ;
	
    	//判断关系
    	if(distance==Rdistance)
    	{
   		cout<< "点在圆上" << endl;
    	} 
    	else if(distance > Rdistance)
    	{
    		cout<< "点在圆外" << endl;
    	}
    	else
    	{
    		cout<< "点在圆内" << endl;
    	}
    }  
};
int main()
{ 
    //创建点类
    point p1;           
	//点的X和Y坐标 
	int P1_X=10;     
	int P1_Y=10;
    p1.setXY(P1_X,P1_Y) ;
	
	//创建圆类 
	circle c1;
	//圆的半径和圆心坐标 
	int R=10;
	c1.setR(R);
	int c1_X = 10;     
	int c1_Y = 0;
	c1.getcenter().setXY(c1_X,c1_Y);    
	
	cout<< "c1的X坐标为： " << c1.getcenter().getX() << "     " << "c1的Y坐标为： " << c1.getcenter().getY() << endl;
	cout<< "p1的X坐标为： " << p1.getY()  << "     " << "p1的Y坐标为： " << p1.getY() << endl;
	
	cout<< "圆的半径为： " << c1.getR() << endl ; 
	
	c1.ifincircle(c1,p1);  	
	
	system("pause");
	return 0;
}
