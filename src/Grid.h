#pragma once

#include "ofMain.h"
#include "constants.h"
#include "Meteorite.h"

#define GRID_SIZE 10
#define ROWS (CANVAS_HEIGHT-(2*CANVAS_BORDER)) / GRID_SIZE
#define COLS (CANVAS_WIDTH-(2*CANVAS_BORDER)) / GRID_SIZE

class Grid{
  int gridArray[ROWS][COLS];
  double high;
  double low;
  double scale;
  public:
    Grid();
    void draw();
    void clear();
    int apply(Meteorite *, double, int);
    void setLow(double);
    void setHigh(double);
    void foo(Meteorite);
    void allocateSpace(int,int,int,int);
    bool spaceAvaliable(int,int,int);
    int getRowCol(int,int);
};