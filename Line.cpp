#include "Line.h"

Line::Line(Point p1, Point p2)
{
    if (p1.x == p2.x)
    {
        k = 0;
        b = -p1.x;
        return;
    }
    if (p1.y == p2.y)
    {
        k = 0;
        b = p1.y;
        return;
    }
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

bool operator==(const Line line1, const Line line2)
{
    return (line1.b == line2.b) && (line1.k == line2.k);
}

bool operator!=(const Line line1, const Line line2)
{
    return !(line1 == line2);
}



