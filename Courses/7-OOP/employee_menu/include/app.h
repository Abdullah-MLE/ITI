#include <iostream>

#include "../include/lib.h"
using namespace std;

#include <termios.h>
#include <unistd.h>

#include <cstdio>

#define BG_WIDTH 70
#define BG_HEIGHT 15

#define menuText1 "New Employee"
#define menuText2 "Display"
#define menuText3 "Exit"

#define DOWN 0
#define UP 1

void drawFrame();
void printOptions();
void printOptionn(int row, const char* option, int color = BrightWhite,
                  int BGColor = BrightBlack, int underLine = 0);

void highlightHelper(int row, const char* option);
void highlight(int cur);

char getch_linux();
void mainLoop();