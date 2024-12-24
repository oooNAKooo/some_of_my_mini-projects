#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

class MovingObject
{
public:
    MovingObject(int minutes, int seconds, double speed);

    double calculateDistance();

private:
    int totalSeconds();

    int minutes;
    int seconds;
    double speed;
};

#endif
