#ifndef MFTI_TASK4_GEOMETRY_LINE_H
#define MFTI_TASK4_GEOMETRY_LINE_H

#include "Point.h"

class Line
{
public:
    Line(Point p1, Point p2);
    Line(double k, double b);
    Line(Point p, double k);

    friend bool operator==(const Line l1, const Line l2);
    friend bool operator!=(const Line l1, const Line l2);

private:
    double k;
    double b;
};


#endif //MFTI_TASK4_GEOMETRY_LINE_H
