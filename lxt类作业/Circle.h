#include "Point2D.h"

class Circle
{
private:
    Point2D origin;
    double radius;
public:
    void SetRadius(double X) {
        radius = X;
        // cout << "set Radius = " << X << endl;
    }
    void GetRadius() {
        cout << "Radius = " << radius << endl;
    }
    void SetOrigin(Point2D P) {
        origin = P;
        // cout << "set Origin: " << endl;
        // P.GetX();
        // P.GetY();
    }
    void GetOrigin() {
        origin.GetX();
        origin.GetY();
    }
    Circle();
    ~Circle();
};

Circle::Circle()
{
    radius = 0;
    cout << "Create Circle" << endl;
}

Circle::~Circle()
{
    cout << "Delete Circle" << endl;
}
