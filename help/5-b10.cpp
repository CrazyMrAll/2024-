/*2151285 王宇莹 信03*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int zeller(int y, int m)
{
    int d = 1,w;
    if (m <= 2)
    {
        m += 12;
        y -= 1;
    }
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return w + 1;
}

void print(int year)
{
    int i,i1, j, k, t, n;
    int table[24][21] = { 0 };
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; 
    if (year%4==0&&year%100||year%400==0)
    {
       days[2] = 29;
    }
   
    for (i = 0; i < 12; i++)
    {
        n = zeller(year,i + 1);
        for (j = (i / 3) * 6; j < (i / 3) * 6 + 6; j++)
        {
            for (k = (i % 3) * 7; k < (i % 3) * 7 + 7; k++)
            {
                t = (j % 6) * 7 + k % 7 - n + 2;
                if (0 >= t)
                {
                    continue;
                }
                if (t <= days[i])
                {
                    table[j][k] = t;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    for (i = 0; i < 24; i++)
    {
        if (i==0)
        {
            cout << setw(15) << "1月" << setw(32) <<"2月" << setw(32) << "3月" << endl;
            for (i1 = 0; i1 < 3; i1++)
                cout << "Sun Mon Tue Wed Thu Fri Sat     ";
            cout << endl;
        }
        if (i==6)
        {
            cout << setw(15) << "4月" << setw(32) << "5月" << setw(32) << "6月" << endl;
            for (i1 = 0; i1 < 3; i1++)
                cout << "Sun Mon Tue Wed Thu Fri Sat     ";
            cout << endl;
        }
        if (i==12)
        {
            cout << setw(15) << "7月" << setw(32) << "8月" << setw(32) << "9月" << endl;
            for (i1 = 0; i1 < 3; i1++)
                cout << "Sun Mon Tue Wed Thu Fri Sat     ";
            cout << endl;
        }
        if (i==18)
        {
            cout << setw(15) << "10月" << setw(32) << "11月" << setw(32) << "12月" << endl;
            for (i1 = 0; i1 < 3; i1++)
                cout << "Sun Mon Tue Wed Thu Fri Sat     ";
            cout << endl;
        }
        for (j = 0; j < 21; j++)
        {
            if (j==7 || j==14)
            {
                cout << "     ";
            }
            if (table[i][j]==0)
            {
                cout << "    ";
                continue;
            }
            if ( j%7==0 || table[i][j-1]==0 )
            {
                cout<<setw(5)<<table[i][j];
            }
            else
            {
                cout<<setw(4)<<table[i][j];
            }
        }
        cout << endl;
    }
}

int main()
{
    int y;
    cout << "请输入年份[1900-2100]" << endl;
    cin >> y;
    while (cin.fail() || y < 1900 || y>2100) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "请输入年份[1900-2100]" << endl;
        cin >> y;
    }

    cout << y << "年的日历为:" << endl;
    print(y);

}