#include "../include/app.h"
int main() {
  drawFrame();
  printOptions();
  cout.flush();
  mainLoop();
  return 0;
}