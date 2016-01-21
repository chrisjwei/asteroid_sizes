#pragma once


class Meteorite{
  double mass;
  double radius;
  int x;
  int y;
  int s;
  int colorRed, colorGreen, colorBlue;
  bool hidden;
  public:
    Meteorite(double);
    double getRadius();
    void print();
    void setX(int);
    void setY(int);
    void setSize(int);
    void draw();
    void hide();
    void show();
};


