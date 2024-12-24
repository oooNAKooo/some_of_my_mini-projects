#ifndef FOOD_DATA_H
#define FOOD_DATA_H

#include <QString>

class FoodData {
protected:
    double caloriesPer100g;
    double fatPer100g;

public:
    FoodData(double cal = 0.0, double fat = 0.0) : caloriesPer100g(cal), fatPer100g(fat) {}

    QString toString() const {
        return QString("������������ �� 100 �: %1, ���� �� 100 �: %2").arg(caloriesPer100g).arg(fatPer100g);
    }
};

#endif 
