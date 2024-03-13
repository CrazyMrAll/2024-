#include <iostream>
using namespace std;

class Point2D
{
private:
    double x, y;
public:
    void GetX() {
        cout << "x = " << x << endl;
    }
    void GetY() {
        cout << "y = " << y << endl;
    }
    void SetX(double x) {
        this->x = x;
        // cout << "set x = " << x << endl;
    }
    void SetY(double y) {
        this->y = y;
        // cout << "set y = " << y << endl;
    }
    Point2D();
    ~Point2D();
};

Point2D::Point2D()
{
    x = y = 0;
    cout << "Create Point" << endl;
}

Point2D::~Point2D()
{
    cout << "Delete Point" << endl;
}
