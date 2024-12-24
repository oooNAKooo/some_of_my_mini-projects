#ifndef PRISM_H
#define PRISM_H

class Prism
{
public:
    Prism(double side1, double side2, double height);

    double calculateArea();    
    double calculateVolume();  

private:
    double side1;
    double side2;
    double height;
};

#endif 
