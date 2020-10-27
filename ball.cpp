#include "ball.h"

ball::ball(v2 pos, double mass, v2 velocity, v2 acc)
{
    position = pos;
    ballmass = mass;
    ballvelocity = velocity;
    ballacceleration = acc;
}

v2 ball::a(){
    return ballacceleration;
}

v2 ball::v(){
    return ballvelocity;
}

v2 ball::s(){
    return position;
}

void ball::updatepos(v2 force, double time){
    ballacceleration = force*(1/ballmass);
    ballvelocity = ballvelocity + ballacceleration*time;
    position = (ballacceleration*pow(time, 2))*0.5+ ballvelocity*time+position;
}
