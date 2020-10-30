#include "Collision.h"
#include <vector>

Collision::Collision()
{

}
// The main method for collision handling
// listof obsticleMaxMin(including [v2 obj1Max, v2 obj1Min] of every rectangle obsticles on screen)
void Collision::updateCollisionStatus(ball* ball, vector<v2> obsticleMaxMin) {
    int sizeOfArray = obsticleMaxMin.size();


    for (int i = 0; i < sizeOfArray; i++) {
        v2 objMin(obsticleMaxMin.at(i).minx(), obsticleMaxMin.at(i).miny());
        v2 objMax(obsticleMaxMin.at(i).maxx(), obsticleMaxMin.at(i).maxy());
        int collisionStatus = this->iscollide(ball->minloc(), ball->maxloc(), objMin, objMax);
        cout << "CollisionStatus: " << collisionStatus <<endl;
        if (collisionStatus != 0) {
            cout << "detectedball-pos: " << ball->s().x() << " x and " << ball->s().y() << endl;
           update(ball, collisionStatus);
        }
    }

}

// check to see if the ball hit exit door(side of collision doesn't matter)
bool Collision::ifExit(ball ball, v2 exitMin, v2 exitMax) {
    int withExit = (this->iscollide(ball.minloc(), ball.maxloc(), exitMin, exitMax));
    if (withExit != 0) {
        return true;
    }
    return false;
}

// return if collide, and which sides of object does the ball collide on
int Collision::iscollide(v2 b_min, v2 b_max, v2 obj_min, v2 obj_max) {
    if (b_max.x() < obj_min.x() or b_min.x() > obj_max.x()) {
        return 0;
    }
    if (b_max.y() < obj_min.y() or b_min.y() > obj_max.y()) {
        return 0;
    }

    int minx = obj_min.x();
    int miny = obj_min.y();
    int maxx = obj_max.x();
    int maxy = obj_max.y();
    int minx2 = b_min.x();
    int miny2 = b_min.y();
    int maxx2 = b_max.x();
    int maxy2 = b_max.y();

    if(maxx2<=minx ||minx2>=maxx) return 1;
    if(maxy2<=miny || miny2>=maxy) return 3;
    //if ((maxx2>=minx && minx2<=maxx && maxy2>=miny))  return 1;    // ball hitting left side of object 2
    //if ((maxy2>=miny && minx2<=maxx && minx2<=maxx)) return 2;    // ball hitting right side of object 2
    //if (miny2<=minx && (maxy2>=miny && minx2<=maxy)) return 3;    // ball hitting bottom of object 2
    //if (minx2<maxx && maxy2>=miny && maxx2>=minx)  return 4;    // ball hitting top of object 2
    return 0;
}




void Collision::update(ball* ball, int status)
{

    switch (status) {
    case 1:
            ball->updateV(v2(-1 * ball->v().x(), ball->v().y()));
            break;
    case 2:
            ball->updateV(v2(-1 * ball->v().x(), ball->v().y()));
            break;
    case 3:
            ball->updateV(v2(ball->v().x(), -1 * ball->v().y()));
            break;
    case 4:
            ball->updateV(v2(-1 * ball->v().x(), ball->v().y()));
            break;
    }
}
