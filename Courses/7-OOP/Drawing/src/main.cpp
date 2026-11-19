#include <iostream>
#include "draw.cpp"
using namespace std;

int main() {
  clearScreen();
  hideCursor();

  Shape* gptr[5] = {new Point(0, 0),
                    new Line(3, 3, 3, 25),
                    new Rectangle(5, 35, 3, 3),
                    new Circle(20, 20, 4)};

  int i = 0;
  while (gptr[i]) {
    gptr[i]->draw();
    i++;
  }

  // p.draw();
  // l.draw();
  // r.draw();
  // c.draw();

  showCursor();
  moveCursor(35, 1);
  cout.flush();
  return 0;
}







