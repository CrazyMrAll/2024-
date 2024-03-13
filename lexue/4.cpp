#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "徒手方队中第 " << n << " 个出场的是：";
    switch (n)
    {
    case 1:cout<<"仪仗"; break;
    case 2:cout<<"领导指挥"; break;
    case 3:cout<<"陆军"; break;
    case 4:cout<<"海军"; break;
    case 5:cout<<"空军"; break;
    case 6:cout<<"火箭军"; break;
    case 7:cout<<"战略支援部队"; break;
    case 8:cout<<"联勤保障部队"; break;
    case 9:cout<<"武警部队"; break;
    case 10:cout<<"女兵"; break;
    case 11:cout<<"院校科研"; break;
    case 12:cout<<"文职人员"; break;
    case 13:cout<<"预备役部队"; break;
    case 14:cout<<"民兵"; break;
    case 15:cout<<"维和部队"; break;
    }
    cout << "方队" << endl;
    return 0;
}