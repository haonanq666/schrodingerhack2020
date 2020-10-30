#include "v2.h"

v2::v2(double x, double y)
{
    xcomponent=x;
    ycomponent=y;
}
v2::v2(double minx, double miny, double maxx, double maxy){
    ix=minx;
    iy=miny;
    ax=maxx;
    ay=maxy;
}

double v2::x(){
    return xcomponent;
}

double v2::y(){
    return ycomponent;
}
double v2::minx(){
    return ix;
}
double v2::miny(){
    return iy;
}
double v2::maxx(){
    return ax;
}
double v2::maxy(){
    return ay;
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

v2 v2::operator-(const v2 & input){
    return v2(xcomponent-input.xcomponent, ycomponent-input.ycomponent);
}

double v2::angle(){
    return atan2(ycomponent, xcomponent);
}
