// #include <sys/ioctl.h>
// sys/ioctl.h is a C header file
// in POSIX-compliant OSs
// -- POSIX: Portable Operating System Interface

// ioctl, TIOCGWINSZ, winsize
// #include <unistd.h>
// the unistd or Unix Standard is
// provides wrapper functions for
// core system calls
// ------------------------------
// we importing it to use: STDOUT_FILENO

#include "../include/app.h"

#include <iostream>
using namespace std;

void chage_text_color(char* text, int color) {
  cout << "\x1b";
  cout << "[1;" << color << "m";
  cout << text;
  cout << "\x1b";
  cout << "[0m";
  cout << "\n";
}

void move_cursor(int x, int y) {
  // ESC[{line};{column}H
  // ESC[{line};{column}f
  cout << "\x1b";
  cout << "[50;50H";
//   cout << "\x1b";
//   cout << "[5;5f";
//   cout << "\x1b";

}

void show_tui_menu(char* text1, int color1, char* text2, int color2,
                   char* text3, int color3) {
  cout << "text1: " << text1 << " color: " << color1 << endl;
  cout << "text2: " << text2 << " color: " << color2 << endl;
  cout << "text3: " << text3 << " color: " << color3 << endl;
  cout << "========================================" << endl;
  move_cursor(5, 5);
  chage_text_color(text1, color1);
  chage_text_color(text2, color2);
  chage_text_color(text3, color3);
  // print_centered(text1);
}