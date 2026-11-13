#include "../include/lib.h"
// Cursor position
void moveCursor(int x, int y) { cout << ESC << "[" << x << ";" << y << "H"; };

// Styles and Colors
void setColor(int color) { cout << ESC << "[" << color << "m"; };
void setBGColor(int color) { cout << ESC << "[" << color + 10 << "m"; }
void resetStyle() { cout << ESC << "[0m"; };

// Screen control
void clearScreen() { cout << ESC << "[2J"; };
void clearLine() { cout << ESC << "[2K"; };
void clearToEndOfLine() { cout << ESC << "[0K"; };
void clearArea(int row1, int col1, int row2, int col2) {
  for (int row = row1; row <= row2; row++) {
    moveCursor(row, col1);
    for (int col = col1; col <= col2; col++) {
      cout << ' ';
    };
  }
}

// Cursor visibility
void hideCursor() { cout << ESC << "[?25l"; };
void showCursor() { cout << ESC << "[?25h"; };

// Text formatting
void changeFormattingStyle(const char* style) { cout << ESC << style; };

// short cuts
void printBGCell(int x, int y, int color) {
  moveCursor(x, y);
  setBGColor(color);
  cout << " ";
};