#ifndef MFTI_TASK4_GEOMETRY_POINT_H
#define MFTI_TASK4_GEOMETRY_POINT_H


struct Point
{
    friend bool operator==(const Point point1, const Point point2);
    friend bool operator!=(const Point point1, const Point point2);

    double x;
    double y;

};


#endif //MFTI_TASK4_GEOMETRY_POINT_H
