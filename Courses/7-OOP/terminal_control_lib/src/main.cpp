#include <iostream>

#include "../include/lib.h"
int main() {
  int startRow = 5;

  // ----------------------

  moveCursor(startRow, 20);
  setBGColor(BrightRed);
  cout<<"      ";
  resetStyle();
  setColor(BrightRed);
  changeFormattingStyle(Bold);
  cout << "   this is line one.";
  moveCursor(1, 1);
  resetStyle();

  // -------------------------------
  
  moveCursor(startRow + 1, 20);
  setBGColor(BrightGreen);
  cout<<"      ";
  resetStyle();
  changeFormattingStyle(Regular);
  setColor(BrightGreen);
  cout << "   this is line two.";
  moveCursor(1, 1);
  resetStyle();

  // -------------------------------
  
  moveCursor(startRow + 2, 20);
  setBGColor(BrightYellow);
  cout<<"      ";
  resetStyle();
  changeFormattingStyle(Italic);
  setColor(BrightYellow);
  cout << "   this is line three.";
  moveCursor(1, 1);
  resetStyle();

  // -------------------------------
  
  moveCursor(startRow + 3, 20);
  setBGColor(BrightBlue);
  cout<<"      ";
  resetStyle();
  cout<<"   ";
  changeFormattingStyle(Underline);
  setColor(BrightBlue);
  cout << "this is line four.";
  moveCursor(1, 1);
  resetStyle();

  // -------------------------------
  
  moveCursor(startRow + 4, 20);
  setBGColor(BrightMagenta);
  cout<<"      ";
  resetStyle();
  changeFormattingStyle(Blinking);
  setColor(BrightMagenta);
  cout << "   this is line five.";
  moveCursor(1, 1);
  resetStyle();

  hideCursor();
  return 0;
}