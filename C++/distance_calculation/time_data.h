#ifndef TIME_DATA_H
#define TIME_DATA_H

#include <QString>

class TimeData {
protected:
    int minutes;
    int seconds;

public:
    TimeData(int min = 0, int sec = 0) : minutes(min), seconds(sec) {}

    QString toString() const {
        return QString("Minutes: %1, Seconds: %2").arg(minutes).arg(seconds);
    }

    int totalSeconds() const {
        return (minutes * 60) + seconds;
    }
};

#endif 
