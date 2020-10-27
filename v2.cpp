#include "v2.h"

v2::v2(double x, double y)
{
    xcomponent=x;
    ycomponent=y;
}

double v2::x(){
    return xcomponent;
}

double v2::y(){
    return ycomponent;
}

v2 v2::operator+(const v2& input){
    return v2(xcomponent+input.xcomponent, ycomponent+input.ycomponent);
}

double v2::magnitude(){
    return sqrt(pow(xcomponent, 2)+ pow(ycomponent, 2));
}

v2 v2::power(double power){
    return v2( pow(xcomponent, power), pow(ycomponent, power));
}

v2 v2::operator*(const double& scalar){
    return v2(scalar*xcomponent, scalar*ycomponent);
}
