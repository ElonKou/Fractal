// Define the whole program config.
#ifndef CONFIG
#define CONFIG
#define VEC_SIZE 3
#define POINT_DIM 3
#define PI 3.14159265358979
#define MIN 1e-10
#define VEC_BUILD_START_X (WIDTH / 10)
#define VEC_BUILD_START_X_STEP (WIDTH / 12)
#define VEC_BUILD_START_Y (HEIGHT / 2)
#define VEC_BUILD_START_Y_STEP (HEIGHT / 4)
#endif

// Define the window config.
#ifndef WINDOW_CONFIG
#define WINDOW_CONFIG
#define WIN_TITLE Fractal - lab.
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
#define WIDTH 960
#define HEIGHT 540

#define WIN_NAME "Elon kou's fratral lab."
#define WIN_CLEAR_COLOR 0.1,0.1,0.1,1.0
#endif

// Define the fratral config.
#ifndef FRACTAL_CONFIG
#define FRACTAL_CONFIG
#define POINT_CNT 5
#define PATTERN_CNT 4
#define F_TIME 5
#endif

