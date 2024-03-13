#include <iostream>
using namespace std;
#define digit 12

int main()
{
    printf("请输入[0~10亿)之间的数字：\n");
    int num[digit];
    double money;
    cin >> money;
    long long a = (long long)money;
    long long b = money*100 - a*100;
    int rate = 1000000000;
    for ( int i=0; i<digit-2; i++ ) {
        num[i] = a / rate;
        a %= rate;
        rate /= 10;
    }
    rate = 10;
    for ( int i=10; i<digit; i++ ) {
        num[i] = b / rate;
        b %= rate;
        rate /= 10;
    }
    cout << "十亿位 ：" << num[0] << endl;
    cout << "亿位   ：" << num[1] << endl;
    cout << "千万位 ：" << num[2] << endl;
    cout << "百万位 ：" << num[3] << endl;
    cout << "十万位 ：" << num[4] << endl;
    cout << "万位   ：" << num[5] << endl;
    cout << "千位   ：" << num[6] << endl;
    cout << "百位   ：" << num[7] << endl;
    cout << "十位   ：" << num[8] << endl;
    cout << "圆     ：" << num[9] << endl;
    cout << "角     ：" << num[10] << endl;
    cout << "分     ：" << num[11] << endl;
    return 0;
}