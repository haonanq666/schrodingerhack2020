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


bool fan::isIn (v2 pos){
    v2 pleft = pos-left;
    v2 pright = pos-right;

    if(
       windVelocity.angle()>= pleft.angle()&&
       windVelocity.angle() <= pright.angle()
         ){
        //qDebug()<<"true";

        return true;
    }else{
        //qDebug()<<"false";
        // 不知道为什么球吹风时也有一半的时候显示false。。。
        return false;
    }



    //return(pos.x()>=left.x())&&(pos.x()<=(right.x()))&&(pos.y()<=left.y());

};

v2 fan :: getForce(ball* B){
    if(!isIn(B->s())){
        return v2(0,0);
    }else{
        //return (windVelocity.power(2) * (-windDensity * M_PI * pow(B->getR(),2)));
        return windVelocity*0.5;

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

/* 以下是有角度的风扇的constructor，还没写完
fan::fan(v2 left, double an, double length, double velocity)
{
    leftpoint = left;
    angle = an*M_PI/180;  //转换成弧度制
    rightpoint = v2(left.x()+cos(angle)*length, left.y()-sin(angle)*length); //利用角度和长度求出右边点的坐标
    windVelocity = v2(cos(angle + M_PI/2) * velocity, -sin(angle + M_PI/2) * velocity); //速度向量
    windDensity = 1.293;
}
更好的方法参考https://blog.csdn.net/junjunba2689/article/details/79159102?utm_medium=distribute.
pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.
channel_param&depth_1-utm_source=distribute.pc_relevant.
none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param
*/
