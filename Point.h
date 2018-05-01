#include "CONFIG.h"

#ifndef POINT
#define POINT
class Point
{
  public:
    int id;
    static int cnt;
    int color[POINT_DIM];
    float data[POINT_DIM];

    Point(float z = 1.0) : data{0.0, 0.0, z}, color{0, 0, 0}
    {
        Point::cnt++;
        Point::id = Point::cnt;
    }
    Point(float x, float y) : data{x, y, 1.0}, color{0, 0, 0}
    {
        Point::cnt++;
        Point::id = Point::cnt;
    }
    ~Point(){};
    Point &operator=(const Point(&P));
    Point operator+(const Point(&P)) const;
    Point operator-(const Point(&P)) const;
    float operator*(const Point(&P));
    float operator%(const Point(&P));
    float operator[](const int index);
    float getDistance(Point(&P));
    float getAngle(Point(&A), Point(&B), Point(&C), Point(&D));
    void setData(float x, float y, float z = 1.0);
    void setColor(int r, int g, int b);
    void print();
};

#endif