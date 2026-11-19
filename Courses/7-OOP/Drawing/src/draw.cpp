#include <cmath>
#include <iostream>

#include "../include/lib.h"

using namespace std;

class Shape {
 private:
 protected:
  int row;
  int col;

 public:
  Shape(int row, int col) : row(row), col(col) {
    // cout << "Constracort Shap" << endl;
  }

  ~Shape() {
    //  cout << "Destracor: Shape" << endl;
  }

  virtual void draw() {
    moveCursor(row, col);
    // cout << "Drawing Shape" << endl;
  }
};

class Point : public Shape {
 private:
 protected:
 public:
  Point(int row, int col) : Shape(row, col) {
    // cout << "Constracort Point " << endl;
  }

  ~Point() {
    // cout << "Destracor: Point" << endl;
  }

  void draw() override { cout << "*" << endl; }
};

class Line : public Shape {
 private:
  int endrow;
  int endcol;

 protected:
 public:
  Line(int row, int col, int endrow, int endcol)
      : Shape(row, col), endrow(endrow), endcol(endcol) {
    // cout << "Constracort Line " << endl;
  }

  ~Line() {
    // cout << "Destracor Line" << endl;
  }

  void draw() override {
    int x1 = col;
    int y1 = row;
    int x2 = endcol;
    int y2 = endrow;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int error = dx - dy;
    moveCursor(0,0);

    while (true) {
      moveCursor(y1, x1);
      cout << "*";

      if (x1 == x2 && y1 == y2) break;

      int e2 = 2 * error;

      if (e2 > -dy) {
        error -= dy;
        x1 += sx;
      }

      if (e2 < dx) {
        error += dx;
        y1 += sy;
      }
    }
  }
};

class Rectangle : public Shape {
 private:
  int width;
  int height;

 protected:
 public:
  Rectangle(int row, int col, int width, int height)
      : Shape(row, col), width(width), height(height) {
    // cout << "Constracort Rectangle" << endl;
  }

  ~Rectangle() {
    // cout << "Destracor Rectangle" << endl;
  }

  void draw() override {
    char symbol = '*';
    moveCursor(0,0);

    for (int x = 0; x < width; x++) {
      moveCursor(row, col + x);
      cout << symbol;

      moveCursor(row + height - 1, col + x);
      cout << symbol;
    }

    for (int y = 0; y < height; y++) {
      moveCursor(row + y, col);
      cout << symbol;

      moveCursor(row + y, col + width - 1);
      cout << symbol;
    }
  }
};

class Circle : public Shape {
 private:
  int radius;

 protected:
 public:
  Circle(int row, int col, int radius) : Shape(row, col), radius(radius) {
    // cout << "Constracort Circle " << endl;
  }

  ~Circle() {
    // cout << "Destracor Circle" << endl;
  }

  void draw() override {
    const double PI = 3.141592653589793;
    moveCursor(0,0);

    for (int degree = 0; degree < 360; degree++) {
      double angle = degree * PI / 180.0;

      int x = col + lround(radius * 2 * cos(angle));
      int y = row + lround(radius * sin(angle));

      moveCursor(y, x);
      cout << "*";
    }
  }
};