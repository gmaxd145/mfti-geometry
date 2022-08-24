#ifndef MFTI_TASK4_GEOMETRY_POLYGON_H
#define MFTI_TASK4_GEOMETRY_POLYGON_H

#include "Shape.h"
#include <vector>

class Polygon : public Shape
{
public:
    Polygon(std::vector<Point> vertices);
    Polygon(std::initializer_list<Point> vertices);

    double perimeter() const override;
    double area() const  override;

    bool operator==(const Shape& another) override;
    bool isCongruentTo(const Shape& another) override;
    bool isSimilarTo(const Shape& another) override;

    bool containsPoint(Point point) override;
    void rotate(Point center, double angle) override;
    void reflex(Point center) override;
    void reflex(Line axis) override;
    void scale (Point center, double coeffcient) override;

    void isConvex() const;
    std::vector<Point> getVerticles() const;

private:
    std::vector<Point> vertices;
};


#endif //MFTI_TASK4_GEOMETRY_POLYGON_H
