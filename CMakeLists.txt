cmake_minimum_required(VERSION 3.23)
project(mfti_task4_geometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(mfti_task4_geometry Point.cpp Point.h Line.cpp Line.h main.cpp Shape.h Polygon.h Polygon.cpp)
