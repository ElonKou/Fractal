//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  main.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Mon 30 Apr 2018 10:57:50 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstdio>
#include <unistd.h>
#include "CONFIG.h"
#include "window.h"
#include "Fractal.h"
#include "lib.h"
#include "main.h"

Fractal F;

int main(int argc, char *argv[])
{
    Window W;
    W.windowInit(argc, argv);
    F.printMatrix();
    F.printPattern();
    F.printPoints();
    F.generate();
    W.windowLoop();

    return 0;
}
