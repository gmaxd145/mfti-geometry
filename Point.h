#ifndef MFTI_TASK4_GEOMETRY_POINT_H
#define MFTI_TASK4_GEOMETRY_POINT_H


struct Point {
    double x;
    double y;

    friend bool operator==(const Point p1, const Point p2);
    friend bool operator!=(const Point p1, const Point p2);
};


#endif //MFTI_TASK4_GEOMETRY_POINT_H
