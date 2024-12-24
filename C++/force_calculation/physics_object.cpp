#include "physics_object.h"

PhysicsObject::PhysicsObject(double speed, int timeMinutes)
    : speed(speed), timeMinutes(timeMinutes) {}

double PhysicsObject::calculateDistance()
{
    return speed * (timeMinutes * 60); 
}

WorkObject::WorkObject(double speed, int timeMinutes, double force)
    : PhysicsObject(speed, timeMinutes), force(force) {}

double WorkObject::calculateWork()
{
    double distance = calculateDistance();
    return force * distance; 
}
