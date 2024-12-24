#include "prism.h"

Prism::Prism(double side1, double side2, double height)
    : side1(side1), side2(side2), height(height) {}

double Prism::calculateArea()
{
    return 0.5 * side1 * side2;
}

double Prism::calculateVolume()
{
    return calculateArea() * height;
}
