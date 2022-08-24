#ifndef MFTI_TASK4_GEOMETRY_SHAPE_H
#define MFTI_TASK4_GEOMETRY_SHAPE_H

#include "Point.h"
#include "Line.h"

class Shape
{
public:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;

    virtual bool operator==(const Shape& another) = 0;
    virtual bool isCongruentTo(const Shape& another) = 0;
    virtual bool isSimilarTo(const Shape& another) = 0;
    virtual bool containsPoint(Point point) = 0; // why Point is not a reference pass?

    virtual void rotate(Point center, double angle) = 0;
    virtual void reflex(Point center) = 0;
    virtual void reflex(Line axis) = 0;
    virtual void scale (Point center, double coeffcient) = 0;
    // why Point, Line are not a reference pass?
};



#endif //MFTI_TASK4_GEOMETRY_SHAPE_H
