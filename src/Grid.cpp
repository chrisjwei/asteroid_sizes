#include "Grid.h"

void foo(Meteorite m){
}

Grid::Grid(){
}

void Grid::clear(){
  memset(gridArray, 0, sizeof(gridArray[0][0]) * ROWS * COLS);
  low = HUGE_VAL;
  high = -1;
}

bool Grid::spaceAvaliable(int row, int col, int size){
  int row_i, col_i;
  for (row_i = 0; row_i < size; row_i++){
    for (col_i = 0; col_i < size; col_i++){
      if (row+row_i >= ROWS || col+col_i >= COLS){
        return false;
      }
      if (gridArray[row+row_i][col+col_i] == 1){
        return false;
      }
    }  
  }
  return true;
}

void Grid::allocateSpace(int row, int col, int size){
  int row_i, col_i;
  for (row_i = 0; row_i < size; row_i++){
    for (col_i = 0; col_i < size; col_i++){
      gridArray[row+row_i][col+col_i] = 1;
    }  
  }
}

int Grid::apply(Meteorite *m, double scale){
  int size = max(int(m->getRadius() / scale),1);
  int drawSize = GRID_SIZE * size;
  int row, col;
  for (row=0; row < ROWS; row++){
    for (col=0; col < COLS; col++){
      if (spaceAvaliable(row, col, size)){
        allocateSpace(row,col,size);
        m->setX(int(CANVAS_BORDER+(col*GRID_SIZE)));
        m->setY(int(CANVAS_BORDER+(row*GRID_SIZE)));
        m->setSize(drawSize);
        return RESULT_SUCCESS;
      }
    }
  }
  if (size == 1){
    return RESULT_TERMINATE; // time to stop
  }
  return RESULT_FAILURE;
}

void Grid::setLow(double x){
  low = x;
}

void Grid::setHigh(double x){
  high = x;
}

void Grid::draw(){
  int row, col, x, y;
  ofSetColor(0,0,0);
  ofSetLineWidth(1);
  ofNoFill();
  for (row=0; row < ROWS; row++){
    for (col=0; col < COLS; col++){
      x = CANVAS_BORDER+col*GRID_SIZE;
      y = CANVAS_BORDER+row*GRID_SIZE;
      ofDrawRectangle(x,y,GRID_SIZE,GRID_SIZE);
    }
  }
}