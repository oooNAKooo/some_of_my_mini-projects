#include "portion_info.h"

FoodItem::FoodItem(double caloriesPer100g, double weight, double fatPer100g)
    : caloriesPer100g(caloriesPer100g), weight(weight), fatPer100g(fatPer100g) {}

double FoodItem::calculateCalories()
{
    return (caloriesPer100g * weight) / 100.0;
}

double FoodItem::calculateFat()
{
    return (fatPer100g * weight) / 100.0;
}
