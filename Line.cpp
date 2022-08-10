#include "Line.h"

Line::Line(Point p1, Point p2)
{
    k = (p2.y - p1.y) / (p2.x - p1.x);
    b = (p2.x * p1.y - p2.y * p1.x) / (p2.x - p1.x);
}

Line::Line(double k, double b) : k(k), b(b)
{
}

Line::Line(Point p, double k) : k(k)
{
    b = -k*p.x + p.y;
}

bool operator==(const Line l1, const Line l2)
{
    return (l1.b == l2.b) && (l1.k == l2.k);
}

bool operator!=(const Line l1, const Line l2)
{
    return !(l1 == l2);
}



