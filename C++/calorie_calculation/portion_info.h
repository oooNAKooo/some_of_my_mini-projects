#ifndef PORTION_INFO_H
#define PORTION_INFO_H

class FoodItem
{
public:
    FoodItem(double caloriesPer100g, double weight, double fatPer100g);

    double calculateCalories(); 
    double calculateFat();       

private:
    double caloriesPer100g;
    double weight;
    double fatPer100g;
};

#endif 
