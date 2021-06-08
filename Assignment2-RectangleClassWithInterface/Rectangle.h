/** @file Rectangle.h */
#ifndef _RECTANGLE
#define _RECTANGLE

#include "RectangleInterface.h"

class Rectangle : public RectangleInterface {

  private:
    double length;
    double width;

  public:
    Rectangle();
    bool set(double length, double width);
    double getLength() const;
    double getWidth() const;
    double getArea() const;

}; 

#endif