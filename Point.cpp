//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  MMM.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 22 Apr 2018 06:21:04 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>
#include <cstdio>
#include "Point.h"
#include "Matrix.h"

int Point::cnt;

Point &Point::operator=(const Point(&P))
{
    for (int i = 0; i < POINT_DIM; i++)
    {
        Point::data[i] = P.data[i];
        Point::color[i] = P.color[i];
    }
    return *this;
}

Point Point::operator+(const Point(&P)) const
{
    Point T;
    for (int i = 0; i < POINT_DIM - 1; i++)
    {
        T.data[i] = Point::data[i] + P.data[i];
        T.color[i] = Point::color[i];
    }
    return T;
}

Point Point::operator-(const Point(&P)) const
{
    Point T;
    for (int i = 0; i < POINT_DIM - 1; i++)
    {
        T.data[i] = Point::data[i] - P.data[i];
        T.color[i] = Point::color[i];
    }
    return T;
}

float Point::getDistance(Point(&P))
{
    float T = 0;
    for (int i = 0; i < POINT_DIM - 1; i++)
    {
        T += pow((P.data[i] - Point::data[i]), 2.0);
    }
    return sqrt(T);
}

float Point::operator*(const Point(&P))
{
    return P.data[0] * Point::data[0] + P.data[1] * Point::data[1];
}

float Point::operator%(const Point(&P))
{
    return Point::data[0] * P.data[1] - Point::data[1] * P.data[0];
}

float Point::operator[](int index)
{
    return Point::data[index];
}

void Point::setData(float x, float y, float z)
{
    Point::data[0] = x;
    Point::data[1] = y;
    Point::data[2] = z;
}

void Point::setColor(int r, int g, int b)
{
    Point::data[0] = r;
    Point::data[1] = g;
    Point::data[2] = b;
}

float Point::getAngle(Point(&A), Point(&B), Point(&C), Point(&D))
{
    float ang = 0.0;
    Point P1 = B - A;
    Point P2 = D - C;
    float mul = P1 % P2;
    float dot = P1 * P2;
    // printf("+++++++::\n");
    float degree = dot / (A.getDistance(B) * C.getDistance(D));
    // printf("degree:%f\n", degree);
    // printf("arg:%f\n", ang);
    // printf("dot:%f\n", dot);
    // printf("mul:%f\n", mul);
    if (fabs(dot - 1.0) <= MIN)
    {
        ang = 0.0;
    }
    else if (fabs(dot + 1.0) <= MIN)
    {
        ang = PI;
    }
    else
    {
        ang = acos(degree);
        if (mul < 0)
        {
            ang = 2 * PI - ang;
        }
    }
    return ang;
}

void Point::print()
{
    printf("Point_%05d\tdata : (", Point::id);
    for (int i = 0; i < POINT_DIM; i++)
    {
        printf("%f", Point::data[i]);
        if (i != POINT_DIM - 1)
        {
            printf("  ");
        }
    }
    printf(")  color : (");
    for (int i = 0; i < POINT_DIM; i++)
    {
        printf("%d", Point::color[i]);
        if (i != POINT_DIM - 1)
        {
            printf("  ");
        }
    }
    printf(")\n");
}
