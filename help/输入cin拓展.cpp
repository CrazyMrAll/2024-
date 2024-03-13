#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a>b) ? a : b;
}

int max(int a, int b, int c) {
    int t = max(a,b);
    return (t>c) ? t : c;
}

int max(int a, int b, int c, int d) {
    int t = max(a,b,c);
    return (t>d) ? t : d;
}

int main()
{
    int n, a, b, c, d, Max;
    bool flag = 1;
    while ( flag ) {
        cout << "请输入num个数以及num:" << endl;
        cin >> n;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(81,'\n');
            continue;
        }
        switch (n)
        {
            case 2: cin >> a >> b;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(81,'\n');
                        continue;
                    }
                    Max = max(a,b);
                    flag=0;
                    break;
            case 3: cin >> a >> b >> c;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(81,'\n');
                        continue;
                    }
                    Max = max(a,b,c);
                    flag=0;
                    break;
            case 4: cin >> a >> b >> c >> d;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(81,'\n');
                        continue;
                    }
                    Max = max(a,b,c,d);
                    flag=0;
                    break;
            default: return 0;
        }
    }
    cout << "max=" << Max << endl;
    return 0;
}