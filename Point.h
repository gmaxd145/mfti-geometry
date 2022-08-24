#ifndef MFTI_TASK4_GEOMETRY_POINT_H
#define MFTI_TASK4_GEOMETRY_POINT_H


struct Point {
    double x;
    double y;

    friend bool operator==(const Point point1, const Point point2);
    friend bool operator!=(const Point point1, const Point point2);
};


#endif //MFTI_TASK4_GEOMETRY_POINT_H
