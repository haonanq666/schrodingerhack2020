# Document

## The Problem
Our project not necessarily solves a problem, but rather strives to optimize the physics learning experience of both students and prospective students. We believe that the best way to learn is to have fun doing it; for example, the game *Minecraft* likely has inspired more architects than any textbook ever will. Although our project is incomparable to that scale, we aim for the same goal: to provide a fun game where the player can apply physics knowledge, or obtain physics knowledge through tinkering with gameplay. Through playing our game, we hope more people will be intrigued and inspired by Newtonian dynamics, one of the core parts of physics that is usually taught first. 

## The Project
As alluded above, the project built by our team is heavily based on Newtonian dynamics and aims to disseminate knowledge in that facet of physics. This is achieved by building a game where the player can tweak the initial launch conditions of a ball, allowing the ball to be launched forward. This ball then is effected upon by numerous effectors, such as fans blowing air, magnets, springs, etc. These effectors all provide a force upon the ball, changing its trajectory; thus, the player must cleverly tweak the available settings to ensure the ball stays on a desired trajectory, which would be to reach an exit point. 

Each level of the game would have a different configuration of effectors, challenging the player to think like a physicist when solving the level. Of course, the other option of playing with the settings is also encouraged, as then the effects of various parameters can be learnt through hands on investigation. 

## Building the Project
### Design Choices

A number of factors was taken into consideration when designing the project. Firstly, we decided that we would want to customize all portions of the game. Thus, we opted to choose to write a program from scratch as opposed to using a game engine; we believed that only basic physics functions were needed, which would be more easily implemented ourselves (with the added benefit of learning more from doing more). Most game engines would have been simply overkill and unnecessary. 

Then came the choice of what language and what tools to use. We eventually chose C++ with the Qt toolkit for graphics, as C++ is known for efficient execution, and it has the ability to do advanced operations, such as working directly with memory. One such example is the "v2" class we created:
```c++
class  v2{
public:
  v2(double  x=0,  double  y=0);
  double  x();
  double  y();
  double  magnitude();
  v2  operator+(const  v2&);
  v2  operator*(const  double&);
  v2  operator-(const  v2&);
  v2  power(double  power=2);
  double  angle();
private:
  double  xcomponent;
  double  ycomponent;
};
```
Although implementations of vectors probably existed, we wanted one that was lightweight and just enough for our needs; thus easily creating our own was the best option. Although in other object-oriented languages normal member functions could be easily created too, we also overloaded operators to make doing calculations with these vectors simpler. 

### The Physics Behind It All

The central idea of our implementation is akin to an "inertial navigation system". At each point in time, an object would be subject to some force, which could be used to find acceleration. Therefore, a relation between the acceleration and time since some epoch can be determined; integrating this twice and replacing the integration constants with the objects initial velocity and position, the current position of the object can be determined. 
$$\int\int \vec{a}(t)\ dt^2=\vec s(t)$$
However, the function of acceleration to time may not be a function that is easy to work with; integrating would pose serious challenges. Therefore, we have introduced the notion of update cycles. During every cycle, the force acting on the object is considered to be constantly equal to the force determined at the beginning of the cycle; using this data, the velocity, speed, and position is updated accordingly. This allows for simplification of the calculation process. This calculation can be seen in the following member function of class ball:
```c++
void  ball::updatepos(v2  force,  double  time){
  ballacceleration  =  (force)*(1/ballmass);
  position  =  (ballacceleration*pow(time,  2))*0.5+  ballvelocity*time+position;
  ballvelocity  =  ballvelocity  +  ballacceleration*time;
}
```
Note that velocity is updated *after* the position; this is intentional. Here, ```ballvelocity``` is the initial velocity; the velocity after updating would be the final velocity, which is not what is called for in the formula. 

As long as ```time``` is kept to a very small value, this approximation would still remain accurate enough for our purposes. 

The net force on the ball at any given moment is determined by the balls position. This position is used by all effectors to return the force which it does upon the ball; this is summed and passed into the function to update the ball's position. An example would be the fans:
```c++
v2  fan  ::  getForce(ball*  B){
  if(!isIn(B->s())){
  return  v2(0,0);
  }else{
  return  windVelocity  *  (windVelocity.magnitude()  *  0.3  *  0.5  *  windDensity  *  M_PI  *  pow(B->getR(),2));
  }
}
``` 
It checks whether the ball is in range of the fan, and if so, how much force it should be getting. However, the formula here is for fans only and other effectors will have different ways to calculate the force given to ball. 

## External Links
Source code can be found here: https://github.com/haonanq666/schrodingerhack2020

