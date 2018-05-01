//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  Matrix.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 29 Apr 2018 10:39:56 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstdio>
#include <cmath>
#include "Matrix.h"

int Matrix::cnt;

Matrix Matrix::operator*(const Matrix(&M))
// Matrix Matrix::multiMatrix(const Matrix(&M))
{
    Matrix T;
    for (int i = 0; i < VEC_SIZE; ++i)
    {
        for (int j = 0; j < VEC_SIZE; ++j)
        {
            for (int k = 0; k < VEC_SIZE; ++k)
            {
                T.data[i][j] += Matrix::data[i][k] * M.data[k][j];
            }
        }
    }
    return T;
}

void Matrix::print()
{
    printf("Matrix_%05d\t", Matrix::id);
    for (int i = 0; i < VEC_SIZE; ++i)
    {
        if (i != 0)
        {
            printf("\t\t");
        }
        for (int j = 0; j < VEC_SIZE; ++j)
        {
            printf("%f  ", Matrix::data[i][j]);
        }
        if (i != VEC_SIZE)
        {
            printf("\n");
        }
    }
}

void Matrix::setData(int x, int y, float data)
{
    Matrix::data[x][y] = data;
}

void Matrix::setArr(float arr[][3])
{
    for (int i = 0; i < POINT_DIM; i++)
    {
        for (int j = 0; j < POINT_DIM; j++)
        {
            Matrix::data[i][j] = arr[i][j];
        }
    }
}

void Matrix::transpose()
{
    for (int i = 0; i < POINT_DIM - 1; i++)
    {
        for (int j = i + 1; j < POINT_DIM; j++)
        {
            Matrix::data[i][j] = Matrix::data[i][j] + Matrix::data[j][i];
            Matrix::data[j][i] = Matrix::data[i][j] - Matrix::data[j][i];
            Matrix::data[i][j] = Matrix::data[i][j] - Matrix::data[j][i];
        }
    }
}

float *Matrix::getData(int index)
{
    return Matrix::data[index];
}

float Matrix::getOne(int x, int y)
{
    return Matrix::data[x][y];
}

float *Matrix::operator[](const int index)
{
    return Matrix::data[index];
}

Matrix &Matrix::operator=(const Matrix(&M))
{
    for (int i = 0; i < POINT_DIM; i++)
    {
        for (int j = 0; j < POINT_DIM; j++)
        {
            Matrix::data[i][j] = M.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix(&M))
{
    Matrix T;
    for (int i = 0; i < POINT_DIM; i++)
    {
        for (int j = 0; j < POINT_DIM; j++)
        {
            T.data[i][j] = Matrix::data[i][j] + M.data[i][j];
        }
    }
    return T;
}

Point Matrix::operator*(const Point(&P))
{
    Point T = Point(0.0);
    for (int i = 0; i < POINT_DIM; ++i)
    {
        for (int j = 0; j < POINT_DIM; ++j)
        {
            T.data[i] += Matrix::data[i][j] * P.data[j];
        }
    }
    return T;
}

Matrix Matrix::getMatrix(Point(&A), Point(&B), Point(&C), Point(&D))
{
    Matrix M;
    float tx = C[0] - A[0];
    float ty = C[1] - A[1];
    float disA = A.getDistance(B);
    float disC = C.getDistance(D);
    float scale = disC / disA;
    float ang = A.getAngle(A, B, C, D);
    // printf("\n%f %f %f %f %f %f\n", tx, ty, disA, disC, scale, ang);
    // build Multi-Matrix from 7.43
    M.data[0][0] = scale * cos(ang);
    M.data[1][0] = scale * sin(ang);
    M.data[2][0] = 0.0;
    M.data[0][1] = -1 * scale * sin(ang);
    M.data[1][1] = scale * cos(ang);
    M.data[2][1] = 0.0;
    M.data[0][2] = A[0] * (1 - scale * cos(ang)) + A[1] * scale * sin(ang) + tx;
    M.data[1][2] = A[1] * (1 - scale * cos(ang)) - A[0] * scale * sin(ang) + ty;
    M.data[2][2] = 1.0;
    return M;
}