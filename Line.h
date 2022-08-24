#ifndef MFTI_TASK4_GEOMETRY_LINE_H
#define MFTI_TASK4_GEOMETRY_LINE_H

#include "Point.h"

class Line
{
public:
    Line(Point point1, Point point2);
    Line(double k, double b);
    Line(Point point, double k);

    friend bool operator==(const Line line1, const Line line2);
    friend bool operator!=(const Line line1, const Line line2);

private:
    double k;
    double b;
};


#endif //MFTI_TASK4_GEOMETRY_LINE_H
