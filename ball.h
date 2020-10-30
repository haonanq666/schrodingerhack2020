#ifndef BALL_H
#define BALL_H
#include "v2.h"

class ball
{
public:
    ball(v2 pos, double mass, v2 velocity=v2(0,0), v2 acc=v2(0,0) );
    v2 s();
    v2 v();
    v2 a();
    v2 minloc();
    v2 maxloc();
    ball updateV(v2 velocity);
    double getR();
    double getM();
    void updatepos(v2 force, double time);

private:
    v2 position;
    v2 ballvelocity;
    v2 ballacceleration;
    double ballmass;
    v2 gravity;
    double radius;
};

#endif // BALL_H
