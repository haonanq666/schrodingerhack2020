#ifndef FAN_H
#define FAN_H
#include "ball.h"

class fan
{
public:
    fan(v2 leftPoint, double length, double velocity);
    bool isIn(v2 pos);
    v2 getForce(ball* B);
private:
    v2 left;
    v2 right;
    v2 windVelocity;
    double windDensity;
};

#endif // FAN_H

/* 以下是有角度的风扇，还没写完
class fan
{
public:
    fan(v2 leftPoint, double angle, double length, double velocity);  //角度angle以正x轴方向为0°，范围为-180°-180°
    bool isIN(v2 pos);
    v2 getForce(ball B);
private:
    v2 leftpoint;  //左点的坐标
    v2 rightpoint; //右点的坐标
    v2 windVelocity;
    double angle;
    double windDensity;
};
*/
