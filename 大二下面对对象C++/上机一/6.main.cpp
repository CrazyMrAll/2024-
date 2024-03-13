#include "6.h"
#include <iostream>
using namespace std;

int main()
{
    Circle c1(2);
    // 非const类对象可以调用const函数和非const函数
    c1.getArea();
    c1.printArea();
    const Circle c2(2);
    // const类对象只能调用const函数
    // c2.getArea(); //如果加上这一行，编译将会报错，因为const类对象只能调用public的const函数
    c2.printArea();
    return 0;
}