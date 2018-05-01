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

void windowInit(int &argc, char *argv[])
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

void drawLines(){

}

void drawPoints(){
    
}

void windowLoop()
{
    glutDisplayFunc(draw);
    glutMainLoop();
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
