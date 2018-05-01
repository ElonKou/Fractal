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

int main(int argc, char *argv[])
{
    windowInit(argc, argv);
    Fractal F;
    F.printMatrix();
    F.printPattern();
    F.printPoints();
    windowLoop();

    return 0;
}
