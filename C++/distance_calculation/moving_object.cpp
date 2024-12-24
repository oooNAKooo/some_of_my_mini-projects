#include "moving_object.h"

MovingObject::MovingObject(int minutes, int seconds, double speed)
    : minutes(minutes), seconds(seconds), speed(speed) {}

double MovingObject::calculateDistance()
{
    return totalSeconds() * speed;
}

int MovingObject::totalSeconds()
{
    return (minutes * 60) + seconds;
}
