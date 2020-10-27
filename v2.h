#ifndef V2_H
#define V2_H

#include <cmath>

class v2
{
public:
    v2(double x=0, double y=0);
    double x();
    double y();
    double magnitude();
    v2 operator+(const v2&);
    v2 operator*(const double&);
    v2 power(double power=2);
private:
    double xcomponent;
    double ycomponent;

};

#endif // V2_H
