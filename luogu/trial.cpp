#include <iostream>
using namespace std;
class DIO {
    int x, y;
public:
    DIO(){
        x = 0;
        y = 0;
    }
};
int DIO_count(DIO ds[]) {
    int N = (sizeof(ds)) / (sizeof(ds[0]));
    return N;
}
int main()
{
    DIO d1, d2, d3;
    DIO ds[3] = { d1, d2, d3 };
    cout << (sizeof(ds)) / (sizeof(ds[0])) << endl;
    cout << sizeof(ds) << endl;
    cout << sizeof(ds[0]) << endl;
    cout << DIO_count(ds) << endl;
    cout << 24 / 8 << endl;
    system("pause");
    return 0;
}