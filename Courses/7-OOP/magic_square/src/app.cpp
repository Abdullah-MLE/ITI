#include <unistd.h>

#include "../include/lib.h"

void magicSquare(int size, int delay) {
  int row = 0;
  int col = size / 2;
  for (int num = 1; num <= size * size; ++num) {
    moveCursor(row * 2 + 3, col * 4 + 6);
    cout << num << flush;
    usleep(delay);
    if (num % size == 0) {
      row++;
      row = row % size;
    } else {
      row--;
      col--;
      if (row < 0) row = size - 1;
      if (col < 0) col = size - 1;
    }
    moveCursor(1, 1);
  }
}