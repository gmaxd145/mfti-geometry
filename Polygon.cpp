#include "Polygon.h"
#include <utility>
#include <cmath>
#include <exception>
#include <algorithm>

 void isPolygon(int verticesCount)
 {
     if (verticesCount < 3)
     {
         throw std::length_error("Not a polygon");
     }
 }

Polygon::Polygon(std::vector<Point> vertices) : _vertices(std::move(vertices))
{
    isPolygon(_vertices.size());
}

Polygon::Polygon(std::initializer_list<Point> vertices) : _vertices(vertices)
{
    isPolygon(_vertices.size());

}

double DistBtwnPoints(Point point1, Point point2)
{
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}

double Polygon::perimeter() const
{
    double perimeter{};
    for (int i = 0; i < _vertices.size() - 1; ++i)
    {
        perimeter += DistBtwnPoints(_vertices[i + 1], _vertices[i]);
    }

    return perimeter;
}

double Polygon::area() const
{
    double area{};
    for (int i = 0;  i < _vertices.size() - 1; ++i)
    {
        area += _vertices[i].x * _vertices[i + 1].y - _vertices[i + 1].x * _vertices[i].y;
    }
    // https://ru.wikipedia.org/wiki/%D0%A4%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%BF%D0%BB%D0%BE%D1%89%D0%B0%D0%B4%D0%B8_%D0%93%D0%B0%D1%83%D1%81%D1%81%D0%B0

    return std::abs(area) * 1.5;
}

bool Polygon::operator==(const Shape &another)
{
    const auto* pAnotherPolygon = dynamic_cast<const Polygon*>(std::addressof(another));
    //Сhecking whether the Shape is really a Polygon
    if (!pAnotherPolygon)
    {
        return false;
    }
// how to make it work?
//    try
//    {
//        const auto& pAnotherPolygon = dynamic_cast<const Polygon&>(another);
//    }
//    catch (std::bad_cast& e)
//    {
//        std::cout << e.what() << std::endl;
//        return false;
//    }

    if (pAnotherPolygon->_vertices == _vertices)
    {
        return true;
    }
    if (pAnotherPolygon->_vertices.size() != _vertices.size())
    {
        return false;
    }

    /*
     * find first equal points by comparing first this point and another points
     * O(N)
     * Comparing
     * O(N)
     * Result: 2*O(N)
     */
    int indexVerticEqualToFirstAnotherVertic = 0;
    for (int i = 0; i < _vertices.size(); ++i)
    {
        if (_vertices[i] == pAnotherPolygon->_vertices[0])
        {
            indexVerticEqualToFirstAnotherVertic = i;
            break;
        }
    }
    if (indexVerticEqualToFirstAnotherVertic)
    {
        for (int i = 1; i < _vertices.size(); ++i)
        {
            if (indexVerticEqualToFirstAnotherVertic + 1 >= _vertices.size())
            {
                indexVerticEqualToFirstAnotherVertic = 1;
            }
            if (_vertices[indexVerticEqualToFirstAnotherVertic + 1] != pAnotherPolygon->_vertices[i])
            {
                return false;
            }
        }
    }
    /* find first equal points by comparing first this point and another points
     * if there is no equal points return false
     * O(N)
     * make another point which equal with this first point first by std::rotate
     * O(N)
     * compare
     * O(N)
     * Result: 3*O(N), clear code
     */

    return true;
}

bool Polygon::isCongruentTo(const Shape &another)
{
    return (*this == another);
}

double calculateAngle(const std::vector<Point>& vertices, int i)
{
    return std::acos(
                   ((vertices[i].x - vertices[(i + 1) % vertices.size()].x)
                      * (vertices[i % vertices.size()].x - vertices[(i + 2) % vertices.size()].x)
                      +
                      (vertices[i % vertices.size()].x - vertices[(i + 1) % vertices.size()].x) * (vertices[i % vertices.size()].x - vertices[(i + 2) % vertices.size()].x))
                      /
                      (DistBtwnPoints(vertices[i % vertices.size()], vertices[(i + 1) % vertices.size()])
                      *
                      DistBtwnPoints(vertices[i % vertices.size()], vertices[(i + 2) % vertices.size()])));
}

/*
 * % vertices.size()
 *
 * -1
 * -1 0 1 -> 2 0 1
 *
 * 0
 * 0 1 2
 *
 * 1
 * 1 2 3 -> 1 2 0
 *
 * 1 < 2 = vertices.size() - 1
 */
void PolygonAngles(std::vector<double>& angles, const std::vector<Point>& vertices)
{
    for (int i = -1; i < vertices.size() - 1; ++i)
    {
        angles.push_back(calculateAngle(vertices, i));
    }
}

bool Polygon::isSimilarTo(const Shape &another)
{
    const auto* pAnotherPolygon = dynamic_cast<const Polygon*>(std::addressof(another));
    // Checking whether the shape is really a polygon
    if (!pAnotherPolygon)
    {
        return false;
    }

    if (pAnotherPolygon->_vertices == _vertices)
    {
        return false;
    }
    if (pAnotherPolygon->_vertices.size() != _vertices.size())
    {
        return false;
    }

    std::vector<double> angles;
    std::vector<double> anotherAngles;
    PolygonAngles(angles, _vertices);
    PolygonAngles(anotherAngles, pAnotherPolygon->_vertices);

    for (int i = 0; i < angles.size(); ++i)
    {
        if (angles[i] == anotherAngles[0])
        {
            std::rotate(angles.begin(), angles.begin()+i, angles.end());
            std::rotate(_vertices.begin(), _vertices.begin()+i, _vertices.end());
            // https://cplusplus.com/reference/algorithm/rotate/
            break;
        }
    }
    if (angles != anotherAngles)
    {
        return false;
    }

    // calculate polygon sides
    // DistanceBetweenPoints
//    double similarityСoefficient =  sides[0] / anotherSides[0];
//    for (int i = 1;  i < _vertices.size(); ++i)
//    {
//        if (similarityСoefficient == sides[i] / anotherSides[i])
//        {
//            similarityСoefficient = sides[i] / anotherSides[i];
//        }
//        else
//        {
//            return false;
//        }
//    }
}

bool Polygon::containsPoint(Point point)
{
    // Принадлежность точки выпуклому или звёздному N-угольнику может быть определена при помощи двоичного поиска за время O(log N), при затрате O(N) памяти и O(N) времени на предварительную обработку.
}


