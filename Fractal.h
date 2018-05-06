#include "CONFIG.h"
#include "Matrix.h"
#include "Point.h"
#include <vector>
#include <string>
#include "lib.h"

// extern Matrix M;
// extern Vec Pattern[4];
// extern Vec Vexs[10];
// extern vector<Vec> VEXS;

// extern std::vector<Point> Points;
// extern std::vector<Point> Pattern;

#ifndef FRACTAL
#define FRACTAL
class Fractal
{
public:
  Matrix M;
  int pointsCnt;
  int patternCnt;
  std::vector<Point> Points;
  std::vector<Point> Pattern;
  Fractal();
  Fractal(int pointsCnt, int patternCnt);
  ~Fractal(){};
  void buildMatrix();
  void buildPoints();
  void buildPattern();
  void printMatrix();
  void printPoints();
  void printPattern();
  void generate();
};
#endif