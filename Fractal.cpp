//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  fractal.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 22 Apr 2018 12:25:24 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstdio>
#include <vector>
#include <cmath>
#include <GL/glut.h>
#include "Point.h"
#include "Matrix.h"
#include "Fractal.h"
#include "window.h"

Fractal::Fractal() : pointsCnt(POINT_CNT), patternCnt(PATTERN_CNT)
{
    Fractal::buildMatrix();
    Fractal::buildPattern();
    Fractal::buildPoints();
    printSucceed("Fractal initialization completed.\n");
}

Fractal::Fractal(int pointsCnt, int patternCnt) : pointsCnt(pointsCnt), patternCnt(patternCnt)
{
    Fractal::pointsCnt = POINT_CNT;
    Fractal::patternCnt = PATTERN_CNT;
    Fractal::buildMatrix();
    Fractal::buildPattern();
    Fractal::buildPoints();
    printSucceed("Fractal initialization completed.\n");
}

void Fractal::buildMatrix()
{
    Fractal::M = Matrix();
}

void Fractal::buildPoints()
{
    for (int i = 0; i < POINT_CNT; i++)
    {
        float x = 100 + i * 150;
        float y = 190 + x / 5 + 180 * pow(-1, i);
        Fractal::Points.push_back(Point(x, y));
    }
}

void Fractal::buildPattern()
{
    for (int i = 0; i < PATTERN_CNT; i++)
    {
        float x = 50 + i * 45;
        float y = 100 + 30 * pow(-1, i) + x / 3;
        Fractal::Pattern.push_back(Point(x, y));
    }
}

void Fractal::printMatrix()
{
    Fractal::M.print();
    printf("\n");
}

void Fractal::printPoints()
{
    for (int i = 0; i < Fractal::pointsCnt; i++)
    {
        Fractal::Points[i].print();
    }
    printf("\n");
}

void Fractal::printPattern()
{
    for (int i = 0; i < Fractal::patternCnt; i++)
    {
        Fractal::Pattern[i].print();
    }
    printf("\n");
}

void Fractal::generate()
{
    for (int i = 0; i < F_TIME; i++)
    {
        for (int j = 0; j < Fractal::pointsCnt - 1; j++)
        {
            Fractal::M = Matrix::getMatrix(Fractal::Pattern[0], Fractal::Pattern[Fractal::patternCnt - 1], Fractal::Points[j], Fractal::Points[j + 1]);
            for (int k = 0; k < Fractal::patternCnt - 1; k++)
            {
                Point T = Fractal::M * Fractal::Pattern[k];
                Fractal::Points.push_back(T);
            }
        }
        Point T = Fractal::M * Fractal::Pattern[patternCnt - 1];
        Fractal::Points.push_back(T);
        for (int j = 0; j < Fractal::pointsCnt; j++)
        {
            Fractal::Points.erase(Fractal::Points.begin(), Fractal::Points.begin() + 1);
        }
        Fractal::pointsCnt = (Fractal::pointsCnt - 1) * (Fractal::patternCnt - 1) + 1;
    }
}

// void fractalInit()
// {
// init the fractral.
// calc the multi of matrix and vec

// buildVec(Vexs, 10);
// printVec(Vexs, 10);

// printVec(Pattern, 10);

// calc the multi matrix
// Matrix A = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
// Matrix B = {{2.0, 3.0, 4.0}, {6.0, 5.0, 4.0}, {17.0, 18.0, 19.0}};
// multiMatrix(A, B, M);
// printMatrix(M);

// calc angle.
// Vec CC[2] = {{1.0, 2.0, 1.0}, {4.0, 5.0, 1.0}};
// Vec DD[2] = {{2.0, 3.0, 1.0}, {6.0, 5.0, 1.0}};
// float ang = angle(CC[0], CC[1], DD[0], DD[1]);

// calc middle matrix and test if it is rigt.
// calcMatrix(Pattern[0], Pattern[1], Pattern[2], Pattern[3], M);
// printVec(Pattern, 10);
// printMatrix(M);
// multiVec(M, Pattern, 2);
// printVec(Pattern, 10);
// }
