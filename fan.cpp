#include "fan.h"
#include<cmath>
#include <QDebug>
fan::fan(v2 leftPoint, v2 rightPoint, double velocity)
{
    left = leftPoint;
    right = rightPoint;
    windVelocity = v2(
                (-(right+left*(-1)).y())/(right+left*(-1)).magnitude(),
                ((right+left*(-1)).x())/(right+left*(-1)).magnitude()
                )*velocity;
    windDensity = 1.293;
}

double fan::getAngle(double an){
    double angle = an-(right+left*(-1)).angle(); //计算夹角
    if(angle > M_PI){
        return angle - 2*M_PI;
    }else if(angle < -M_PI){
        return angle + 2*M_PI;
    }else{
        return angle;
    }
    //调整范围
}


bool fan::isIn (v2 pos){
    v2 pleft = pos-left;
    v2 pright = pos-right;
    double ran = getAngle(pright.angle());      //计算pright与风扇向量(right-left)的夹角，并另其取值范围为(-Pi,Pi)
    double lan = getAngle(pleft.angle());       //计算pleft与风扇向量的夹角，并另其取值范围为(-Pi,Pi)

    //qDebug()<<"r"<<ran;
    //qDebug()<<"l"<<lan;

    if(
       M_PI/2 >= lan && lan >= 0 &&        //左角度应大于0，小于90.
       M_PI >= ran && ran >= M_PI/2          //右角度应大于90，小于180.
         ){
        //qDebug()<<true;
        return true;
    }else{
        //qDebug()<<false;
        return false;
    }

    /*
    if(
       windVelocity.angle() >= pleft.angle()&&
       windVelocity.angle() <= pright.angle()
         ){
        //qDebug()<<"true";

        return true;
    }else{
        //qDebug()<<"false";
        // 不知道为什么球吹风时也有一半的时候显示false。。。
        // 可能是因为一个风扇是false 另一个是true
        return false;
    }
    */

};

v2 fan :: getForce(ball* B){
    if(!isIn(B->s())){
        return v2(0,0);
    }else{
        return windVelocity * (windVelocity.magnitude() * 0.3 * 0.5 * windDensity * M_PI * pow(B->getR(),2));
        //return windVelocity*0.5;

        //formula: Drag = Velocity^2 * drag coeffient * 0.5 * windDensity * Area
        //有时间的话可以优化Area的算法(比如只有部分小球刚进入风扇范围内时)，这里只用了Pi*r^2
        //这个运算仔细研究一下。
    }
}

v2 fan::lpoint(){
    return left;
}

v2 fan::rpoint(){
    return right;
}

v2 fan::paintlpoint(){
    if((right-left).angle() < M_PI ){
         return left;
    }else{
        return right;
    }

}
v2 fan::paintrpoint(){
    if((right-left).angle() < M_PI ){
    return right;
    }else{
        return left;
    }
}
