//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  hello.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 22 Apr 2018 06:22:01 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstdio>
#include <GL/glut.h>
#include "Point.h"
#include "Matrix.h"

int Point::cnt = 0;

int main()
{
    Point P1 = Point();
    Point P2 = Point();
    Point P3 = Point();

    P1.print();
    P2.print();
    P3.print();
    printf("\n");

    P1.setData(2.0, 3.2);
    P2.setData(5.0, 2.3);
    P3 = P2 + P1;
    Point P4;
    P4 = P3;
    Point P5 = P4 - P1;

    P1.print();
    P2.print();
    P3.print();
    P4.print();
    P5.print();

    printf("\n");

    Matrix A, B, C;
    A.print();
    B.print();
    C.print();

    float arr[][3] = {{1.0, 2.0, 3.0},
                      {2.0, 3.0, 12.0},
                      {0.0, 0.0, 1.0}};

    A.setArr(arr);
    A.print();
    B = A;
    B.print();
    B.transpose();
    B.print();
    C = B + B;
    C.print();
    printf("++++++++++++++++++++++++++++++++++++++++++++\n");
    B.print();
    A.print();
    A = B * A;
    A.print();
    printf("++++++++++++++++++++++++++++++++++++++++++++\n");
    B.print();
    P1.print();
    Point D = B * P1;
    D.print();
    printf("++++++++++++++++++++++++++++++++++++++++++++\n");

    P1.print();
    P2.print();
    float a = P1 * P2;
    float b = P1 % P2;
    printf("a = %f\n", a);
    printf("b = %f\n", b);

    printf("b = %f\n", P1[0]);
    printf("b = %f\n", P1[1]);
    printf("b = %f\n", P1[2]);
    printf("++++++++++++++++++++++++++++++++++++++++++++\n");

    float *list = B[1];
    B.print();
    printf("list[0] = %f\n", list[0]);
    printf("list[1] = %f\n", list[1]);
    printf("list[2] = %f\n", list[2]);
    printf("++++++++++++++++++++++++++++++++++++++++++++\n");
    P1.print();
    P2.print();
    P3.print();
    P4 = P4 + P4;
    P4.print();
    Matrix M;
    M = M.getMatrix(P1, P2, P3, P4);
    M.print();
    P1.print();
    P2.print();
    Point T = M * P1;
    T.print();
    T = M * P2;
    T.print();
    return 0;
}
