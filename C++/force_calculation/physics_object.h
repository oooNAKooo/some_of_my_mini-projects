#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

class PhysicsObject
{
public:
    PhysicsObject(double speed, int timeMinutes);
    double calculateDistance(); 

protected:
    double speed;      
    int timeMinutes;   
};

class WorkObject : public PhysicsObject
{
public:
    WorkObject(double speed, int timeMinutes, double force);
    double calculateWork();  

private:
    double force; 
};

#endif
