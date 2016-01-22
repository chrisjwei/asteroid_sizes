#include "Meteorite.h"
#include "ofMain.h"
#include "constants.h"

#include <math.h>
#include <stdlib.h>

Meteorite::Meteorite(double m, const char *name_in, const char *color){
  mass = m;
  name = name_in;

  radius = pow(m,0.33333333333);

  int rgb = stoi(color+1, 0, 16);


  colorRed = (rgb >> 16) & 0xFF;
  colorGreen = (rgb >> 8) & 0xFF;
  colorBlue = (rgb) % 0xFF;
  x = -1;
  y = -1;
  s = 30;
}

void Meteorite::print(){
  cout << "x: " << x << "y: " << y << endl;
}

void Meteorite::draw(){
  if (!hidden){
    ofSetColor(colorRed,colorGreen,colorBlue);
    ofFill();
    ofDrawRectangle(x+2,y+2,s-4,s-4);  
  }
}

void Meteorite::drawText(){
  char s[128];
  ofSetColor(0);
  ofFill();
  sprintf(s, "\"%s\", %.2f grams", name, mass);
  ofDrawBitmapString(s, CANVAS_BORDER, CANVAS_BORDER-20);
}

double Meteorite::getRadius(){
  return radius;
}

void Meteorite::setX(int xin){
  x = xin;
}

void Meteorite::setY(int yin){
  y = yin;
}

void Meteorite::setSize(int size){
  s = size;
}

void Meteorite::hide(){
  hidden = true;
}

void Meteorite::show(){
  hidden = false;
}