#include "../include/app.h"
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
void clearArea(int x1, int y1, int x2, int y2) {
  for (int row = x1; row <= x2; row++) {
    moveCursor(row, y1);
    for (int col = y1; col <= y2; col++) {
      cout << ' ';
    };
  }
}

// Cursor visibility
void hideCursor() { cout << ESC << "[?25l"; };
void showCursor() { cout << ESC << "[?25h"; };

// Text formatting
void changeFormattingStyle(const char* style) { cout << ESC << style; };
