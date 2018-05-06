//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  window.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 22 Apr 2018 12:44:47 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstdio>
#include <GL/glut.h>
#include "window.h"
#include "Fractal.h"
#include "lib.h"
#include "main.h"

void Window::windowInit(int &argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition((WIN_WIDTH - WIDTH) / 2, (WIN_HEIGHT - HEIGHT) / 2);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow(WIN_NAME);
    glClearColor(WIN_CLEAR_COLOR);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
    printSucceed("Window initialization completed.\n");
}

void Window::drawLines()
{
    glBegin(GL_LINES);
    glColor3f(1.4, 0.4, 0.4);
    glVertex2i(100, 200);
    glVertex2i(200, 300);
    glEnd();
}

void Window::drawPattern()
{
    glBegin(GL_LINES);
    glColor3f(0.4, 1.4, 0.4);
    for (int i = 0; i < F.patternCnt - 1; i++)
    {
        glVertex2f(F.Pattern[i][0], F.Pattern[i][1]);
        glVertex2f(F.Pattern[i + 1][0], F.Pattern[i + 1][1]);
    }
    glEnd();
}

void Window::drawPoints()
{
    glBegin(GL_LINES);
    glColor3f(1.4, 0.2, 1.4);
    for (int i = 0; i < F.pointsCnt - 1; i++)
    {
        glVertex2f(F.Points[i][0], F.Points[i][1]);
        glVertex2f(F.Points[i + 1][0], F.Points[i + 1][1]);
    }
    glEnd();
}

void Window::windowLoop()
{
    glutDisplayFunc(Window::draw);
    glutMainLoop();
}

void Window::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    printSucceed("Loop is running...\n");
    Window::drawPattern();
    Window::drawPoints();
    glFlush();
}
