#include "CONFIG.h"
#include "Point.h"

#ifndef MATRIX
#define MATRIX
class Matrix
{
  public:
    int id;
    static int cnt;
    float data[POINT_DIM][POINT_DIM];

    Matrix() : data{{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}}
    {
        Matrix ::cnt++;
        Matrix ::id = Matrix ::cnt;
    };
    ~Matrix(){};
    void print();
    void transpose();
    void setArr(float arr[][3]);
    void setData(int x, int y, float data);
    float *getData(int index);
    float getOne(int x, int y);
    Point operator*(const Point(&P));
    Matrix &operator=(const Matrix(&M));
    Matrix operator+(const Matrix(&M));
    Matrix operator*(const Matrix(&M));
    Matrix getMatrix( Point(&A), Point(&B), Point(&C), Point(&D));
    float *operator[](const int index);
};

#endif