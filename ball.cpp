#include "ball.h"

ball::ball(v2 pos, double mass, v2 velocity, v2 acc)
{
    position = pos;
    ballmass = mass;
    ballvelocity = velocity;
    ballacceleration = acc;
    radius = 3;
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

double ball::getM(){
    return ballmass;
}

double ball::getR(){
    return radius;
}

void ball::updatepos(v2 force, double time){
    ballacceleration = (force)*(1/ballmass);
    position = (ballacceleration*pow(time, 2))*0.5+ ballvelocity*time+position;
    ballvelocity = ballvelocity + ballacceleration*time;
}

// for collision class
v2 ball::minloc() {
    return v2(position.x(), position.y());
}
v2 ball::maxloc() {
    return v2(position.x()+radius*2, position.y()+radius*2);
}
ball ball::updateV(v2 velocity) {
    return ball(position, ballmass, velocity, ballacceleration);
}
