#ifndef V2_H
#define V2_H

#include <cmath>

class v2
{
public:
    v2(double x=0, double y=0);
    v2(double minx, double miny, double maxx, double maxy);
    double minx();
    double miny();
    double maxx();
    double maxy();
    double x();
    double y();
    double magnitude();
    v2 operator+(const v2&);
    v2 operator*(const double&);
    v2 operator-(const v2&);
    v2 power(double power=2);
    double angle();
private:
    double xcomponent;
    double ycomponent;
    double ix;
    double iy;
    double ax;
    double ay;

};

#endif // V2_H
