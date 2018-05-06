#include "CONFIG.h"

// void windowInit(int &argc, char *argv[]);
// void windowLoop();
// void draw(void);

#ifndef WINDOW
#define WINDOW
class Window
{
  public:
    int width;
    int height;
    char window_name[255];
    Window() : width(WIN_WIDTH), height(WIN_HEIGHT), window_name(WIN_NAME){};

    void windowInit(int &argc, char *argv[]);
    void windowLoop();
    static void draw();
    static void drawLines();
    static void drawPoints();
    static void drawPattern();
};

#endif