#include "Circle.h"

int main()
{ 
    Point2D P1;
    P1.SetX(1.0);
    P1.SetY(2.0);
    P1.GetX();
    P1.GetY();
    Circle C1;
    C1.SetOrigin(P1);
    C1.GetOrigin();
    C1.SetRadius(5.0);
    C1.GetRadius();
    return 0;
}