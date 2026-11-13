#include "../include/app.h"

#include <cstddef>

#include "../include/lib.h"

char getch_linux() {
  char buf = 0;
  struct termios old = {0};
  tcgetattr(0, &old);
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &old);
  read(0, &buf, 1);
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  tcsetattr(0, TCSADRAIN, &old);
  return buf;
}

int getWidthCenter(const char* text) {
  int count = 0;
  while (text[count] != '\0') {
    count++;
  }

  return (BG_WIDTH - count) / 2;
}

void drawFrame() {
  // printing up and down fram
  for (int i = 0; i < BG_WIDTH; i++) {
    printBGCell(0, i, BrightYellow);
    printBGCell(BG_HEIGHT, i, BrightYellow);
  }

  // printing left and right fram
  for (int i = 0; i < BG_HEIGHT; i++) {
    printBGCell(i, 1, BrightYellow);
    printBGCell(i, 2, BrightYellow);
    printBGCell(i, BG_WIDTH - 1, BrightYellow);
    printBGCell(i, BG_WIDTH - 2, BrightYellow);
  }
  resetStyle();
}

void printOption(int row, const char* option) {
  int center_col = getWidthCenter(option);
  moveCursor(row, center_col);
  cout << option;
  resetStyle();
}

void printOptions() {
  int start_row = BG_HEIGHT / 2;
  printOption(start_row - 2, menuText1);
  printOption(start_row, menuText2);
  printOption(start_row + 2, menuText3);
}

void mainLoop() {
  char byte1 = '\0';
  char byte2 = '\0';
  char byte3 = '\0';

  // Infinite loop that runs until the user chooses to quit
  while (byte1 != 'q' && byte1 != 'Q') {
    byte1 = getch_linux();
    if (byte1 == ESC) {
      byte2 = getch_linux();
      byte3 = getch_linux();
      switch (byte3) {
        case 'A':
          cout << "↑ Up Arrow\n";
          break;

        case 'B':
          cout << "↓ Down Arrow\n";
          break;

        case 'C':
          cout << "→ Right Arrow\n";
          break;

        case 'D':
          cout << "← Left Arrow\n";
          break;
        case 'H':
          cout << "← Home Button \n";
          break;
        case 'F':
          cout << "End Button\n";
          break;
      }
    }
  }
}