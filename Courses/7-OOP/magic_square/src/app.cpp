#include <unistd.h>

#include "../include/lib.h"
void magicSquare(int size, int delay) {
  int row = 5;
  int col = size / 2;
  for (int num = 1; num <= size * size; ++num) {
    moveCursor(row + 1, col * 4 + 1);
    cout << num << flush;
    usleep(delay);
    if (num % size == 0) {
      row++;
      row = row % size;
    } else {
      row = (row - 1 + size);
      row = row % size;
      col++;
      col = col % size;
    }
  }
  moveCursor(size + 2, 1);
}