#include "Polygon.h"
#include <utility>
#include <cmath>
#include <exception>
#include <iostream>

Polygon::Polygon(std::vector<Point> vertices) : vertices(std::move(vertices))
{
}

Polygon::Polygon(std::initializer_list<Point> vertices) : vertices(vertices)
{
}

double Polygon::perimeter() const
{
    double perimeter{};
    for (int i = 0; i < vertices.size() - 1; ++i)
    {
        perimeter += sqrt(pow(vertices[i + 1].x - vertices[i].x, 2) + pow(vertices[i + 1].y - vertices[i].y, 2));
    }
    //img.png

    return perimeter;
}

double Polygon::area() const
{
    double area{};
    for (int i = 0;  i < vertices.size() - 1; ++i)
    {
        area += vertices[i].x * vertices[i + 1].y - vertices[i + 1].x * vertices[i].y;
    }
    // https://ru.wikipedia.org/wiki/%D0%A4%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%BF%D0%BB%D0%BE%D1%89%D0%B0%D0%B4%D0%B8_%D0%93%D0%B0%D1%83%D1%81%D1%81%D0%B0

    return fabs(area) * 1.5;
}

bool Polygon::operator==(const Shape &another)
{

    const auto* rAnotherPolygon = dynamic_cast<const Polygon*>(std::addressof(another));
//    try
//    {
//        const auto& rAnotherPolygon = dynamic_cast<const Polygon&>(another);
//    }
//    catch (std::bad_cast& e)
//    {
//        std::cout << e.what() << std::endl;
//        return false;
//    }
// how to make it work?
//    if (!rAnotherPolygon)
//    {
//        return false;
//    }
// no cases for bad cast?
// I know ony one - img_1
    if (rAnotherPolygon->vertices == vertices)
    {
        return true;
    }
    if (rAnotherPolygon->vertices.size() != vertices.size())
    {
        return false;
    }

    int thisIndex = 0;
    for (int i = 0; i < vertices.size(); ++i)
    {
        if (vertices[i] == rAnotherPolygon->vertices[0])
        {
            thisIndex = i;
            break;
        }
    }
    if (thisIndex)
    {
        for (int i = 1; i < vertices.size(); ++i)
        {
            if (thisIndex + 1 >= vertices.size())
            {
                thisIndex = 1;
            }
            if (vertices[thisIndex + 1] != rAnotherPolygon->vertices[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool Polygon::isCongruentTo(const Shape &another)
{
    return (*this == another);
}

bool Polygon::isSimilarTo(const Shape &another)
{
}

bool Polygon::containsPoint(Point point)
{
    // Принадлежность точки выпуклому или звёздному N-угольнику может быть определена при помощи двоичного поиска за время O(log N), при затрате O(N) памяти и O(N) времени на предварительную обработку.
}


