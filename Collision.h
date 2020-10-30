#ifndef COLLISION_H
#define COLLISION_H
#include <iostream>
#include <string>
#include "ball.h"
#include <vector>
using namespace std;
class Collision {
public:
    Collision();

    void updateCollisionStatus(ball* ball, vector<v2> obsticleMaxMin);

    bool ifExit(ball ball, v2 exitMin, v2 exitMax);



private:
    int iscollide(v2 b_min, v2 b_max, v2 obj_min, v2 obj_max);

    void update(ball* ball, int status);

};

#endif // COLLISION_H
