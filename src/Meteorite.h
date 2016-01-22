#pragma once


class Meteorite{
  double mass;
  double radius;
  int x;
  int y;
  int s;
  int colorRed, colorGreen, colorBlue;
  bool hidden, selected;
  const char *name;
  public:
    Meteorite(double, const char *, const char *);
    double getRadius();
    void print();
    void setX(int);
    void setY(int);
    void setSize(int);
    void draw();
    void hide();
    void show();
    void drawText();
};


