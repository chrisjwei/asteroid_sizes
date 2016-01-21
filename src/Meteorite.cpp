#include "Meteorite.h"
#include "ofMain.h"

#include <math.h>
#include <stdlib.h>

Meteorite::Meteorite(double m){
  mass = m;
  radius = pow(m,0.33333333333);
  colorRed = rand() % 255;
  colorGreen = rand() % 255;
  colorBlue = rand() % 255;
  x = 100;
  y = 100;
  s = 30;
}

void Meteorite::print(){
  cout << "x: " << x << "y: " << y << endl;
}

void Meteorite::draw(){
  //cout << "drawing x: " << x << " y: " << y << "s:  " << s << endl;
  if (!hidden){
    ofSetColor(colorRed,colorGreen,colorBlue);
    ofFill();
    ofDrawRectangle(x+2,y+2,s-4,s-4);  
  }
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