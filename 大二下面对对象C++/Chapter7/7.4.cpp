#include <iostream>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
public:
    // Date() {
    //     year = 0;
    //     month = 0;
    //     day = 0;
    // }
    // Date(int y) { 
    //     year = y; 
    //     month = 0; 
    //     day = 0; 
    // }
    // Date(int y, int m) { 
    //     year = y; 
    //     month = m; 
    //     day = 0; 
    // }
    // Date(int y, int m, int d) { 
    //     year = y; 
    //     month = m; 
    //     day = d;
    // }
    Date(int y = 0, int m = 0, int d = 0) { 
        year = y; 
        month = m; 
        day = d;
    }
    void print() {
        cout << "year: " << year << ", month: " << month << ", day: " << day << endl;
    }
};

int main()
{
    Date a;
    a.print();
    Date b(2023);
    b.print();
    Date c(2023, 3);
    c.print();
    Date d(2023, 3, 8);
    d.print();
    return 0;
}
