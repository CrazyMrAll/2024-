#include <iostream>
using namespace std;

int main()
{
    bool flag = 0;
    int n;
    cin >> n;
    for (int i = n; i >= 0; --i) {
        int num;
        cin >> num;
        if (flag && num>0) printf("+"); 
        if (num==-1 && i) printf("-");
        if ((num && num!=1 && num!=-1) || (!i && num)) printf("%d", num);
        if (num && i) printf("x");
        if (num && i>1) printf("^%d", i);
        if (!flag && num) flag = 1;
    }
    cout << endl;
    return 0;
}