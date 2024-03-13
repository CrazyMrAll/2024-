class Triangle {
private:
    double a, b, c;
    bool IsTrig();
    double Area();
public:
    Triangle(double x, double y, double z);
    friend double SumArea(Triangle& , Triangle&);
};