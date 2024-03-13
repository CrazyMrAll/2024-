#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    string name;
    double salary;
public:
    virtual void pay()=0;
    Employee(string n, double m): name(n), salary(m) {}
    string Getname() {return name;}
    double Getsalary() {return salary;}
};

class Technician: public Employee
{
public:
    void pay() {cout << "Technician: " << Getname() << ", salary: " << Getsalary() << endl;}
    Technician(string n, double hour): Employee(n, 100*hour) {}
};

class Manager: virtual public Employee
{
public:
    void pay() {cout << "Manager: " << Getname() << ", salary: " << Getsalary() << endl;}
    Manager(string n = "", double money = 7000): Employee(n, money) {}
};

class Salesman: virtual public Employee
{
private:
    double sale;
public:
    void pay() {cout << "Salesman: " << Getname() << ", salary: " << Getsalary() << endl;}
    Salesman(string n = "", double s = 0): Employee(n, s*0.05), sale(s) {}
    double Getsale() {return sale;}
};

class SalesManager: public Manager, public Salesman
{
public:
    void pay() {cout << "SalesManager: " << Getname() << ", salary: " << Getsalary() << endl;}
    SalesManager(string n = "", double s = 0): Employee(n, 4000+s*0.005) {}
};

int main()
{
    Technician t("Tony", 7*8);
    Manager m("Magie");
    Salesman s1("Sunny", 100000), s2("Sunday", 200000);
    SalesManager S("Super", 1000000+2000000);
    Employee *p;
    p = &t;
    p->pay();
    p = &m;
    p->pay();
    p = &s1;
    p->pay();
    p = &s2;
    p->pay();
    p = &S;
    p->pay();
    return 0;
}

// pay函数输出为 类别名：名字，薪水：数额
// 名字和薪水在初始化时确定，传入的第二个参数：Technician为工作市场，Manager默认为7000，Salesman和SalesManager为销售额
// output:
// Technician: Tony, salary: 5600    
// Manager: Magie, salary: 7000      
// Salesman: Sunny, salary: 5000     
// Salesman: Sunday, salary: 10000   
// SalesManager: Super, salary: 19000