#ifndef FAN_H
#define FAN_H
#include "ball.h"

class fan
{
public:
    fan(v2 leftPoint, v2 rightPoint, double velocity);
    //这儿不用太复杂，有两个点就能定义一条线（风扇）。左右定义了上自然定义了。
    bool isIn(v2 pos);
    v2 getForce(ball* B);
    v2 lpoint();
    v2 rpoint();
    v2 paintlpoint();
    v2 paintrpoint();
private:
    v2 left;
    v2 right;
    v2 windVelocity;
    double windDensity;
    double getAngle(double an);
};

#endif // FAN_H
