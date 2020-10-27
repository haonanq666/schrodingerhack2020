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
    void updatepos(v2 force, double time);
private:
    v2 position;
    v2 ballvelocity;
    v2 ballacceleration;
    double ballmass;

};

#endif // BALL_H
