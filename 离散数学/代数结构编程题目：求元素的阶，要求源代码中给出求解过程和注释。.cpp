#include <iostream>
using namespace std;

int main()
{
    // 由定义易得当k*a = e时，k为阶数
    int n, cnt = 1, num;
    scanf("%d", &n);
    num = n;
    while (num % 18) {
        num += n;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}