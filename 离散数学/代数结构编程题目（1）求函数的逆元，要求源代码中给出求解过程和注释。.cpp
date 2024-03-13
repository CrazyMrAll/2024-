#include <iostream>
using namespace std;

// 根据逆元定义，易知f1,f2,f3的逆元即为自身
// f5化简得1 - x^-1, 故f4*f5 = 1, f4, f5互为逆元
// f6化简为1 + (x-1)^-1, 验证得f6*f6 = 1, f6逆元为自身
int ans[6] = {1, 2, 3, 5, 4, 6}, n;

int main()
{
    scanf("f%d", &n);
    printf("f%d\n", ans[n-1]);
}