#include "fan.h"
#include<cmath>

fan::fan(v2 leftPoint, double length, double velocity)
{
    left = leftPoint;
    right = v2((left.x()+length),left.y());
    windVelocity = v2(0,velocity);
    windDensity = 1.293;
}


bool fan::isIn (v2 pos){
    return(pos.x()>=left.x())&&(pos.x()<=(right.x()))&&(pos.y()<=left.y());

};

v2 fan :: getForce(ball* B){
    return windVelocity.power(2) * (-windDensity * M_PI * pow(B->getR(),2));
    //有时间的话可以优化Area的算法(比如只有部分小球刚进入风扇范围内时)，这里只用了Pi*r^2
};


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
