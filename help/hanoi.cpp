//----------------------------------
#include <iostream>
using namespace std;
  
//定义结构体，用作存放圆盘信息的“容器”(立柱)。在立柱上放入或取走圆盘，
//总是发生在顶部，有“先放后取，后放先取”的特征。这是典型的栈操作。
typedef struct{
    char disc[27];
    int top;      //-1表示没有瓷盘，空的
}POLE;
 
//下面三个函数是实现在立柱(容器)上获取顶部瓷盘，拿走和放入瓷盘的操作
 
//获取顶部圆盘的代码。
//这里形参变量p前的 & 不是取地址操作，而表示函数调用时，此类形参是实参
//的【引用】，不会发生一般情况下的实参向形参变量的赋值过程，而是通过 p
//这个“别名”，直接使用实参。因此，函数对它的更新，等同于发生在实参本身。
char top(POLE &p)
{
    if(p.top < 0) return '\0';
 
    return p.disc[p.top];
}
 
//拿走（删除）顶部圆盘
void pop(POLE &p)
{
    if(p.top < 0) return; //已空
 
    p.disc[p.top] = '\0';
    p.top--;
}
 
//在顶部新放入一个圆盘
void push(POLE &p, char d)
{
    if(p.top > 25) return; //已满
 
    p.top++;
    p.disc[p.top] = d;
}
///////////////////////////////
  
int step = 0;
//代表堆放碟子的三个立柱（容器）
POLE P[3] = {{"\0", -1},{"\0", -1},{"\0", -1}}; 
//移动汉诺塔
//功能: 把第1根柱子p1上的n个瓷盘，借助第2根柱子p2, 
//      搬到第3根柱子上。
//TODO: 补全move递归函数后，与所有代码一起提交。
void move(int n, int p1, int p2, int p3)
{
    if(n == 1)
    {//成功搬移一个瓷盘
        step++;
        //这是一个典型的出栈进栈操作
        char movedDisk = top(P[p1-1]);
        pop(P[p1-1]);
        push(P[p3-1], movedDisk);
  
        cout<<"Step."<<step<<": disk "<<movedDisk;
        cout<<" moved from P"<<p1<<" to P"<<p3<<endl;
  
        return; //重要
    }
    move(n-1,p1,p3,p2);
    move(1,p1,p2,p3);
    move(n-1,p2,p1,p3);
  
    //要解决原问题，需要：
    //1. 把P1顶部n-1个瓷盘借助P3，先搬到P2上;    
    /* _@{TODO 递归调用}_ */
     
    //2. 把P1上剩下的底部那1个借助P2,搬到P3上；
    /* _@{TODO 递归调用}_ */
     
    //3. 把已搬到P2上的n-1个瓷盘，搬到P3上。
    /* _@{TODO 递归调用}_ */
     
}
  
int main()
{
    int n;
    cin >> n;
    for(int j = 0; j < n; j++)
    {
        push(P[0], 'A'+j); //在第1根柱子上放入所需的瓷盘
    }
  
    move(n, 1, 2, 3);
  
    return 0;
}