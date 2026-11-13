#include <iostream>
using namespace std;

#include <termios.h>
#include <unistd.h>
#include <cstdio>

#define BG_WIDTH 70
#define BG_HEIGHT 15

#define menuText1 "New Employee"
#define menuText2 "Display"
#define menuText3 "Exit"

void drawFrame();
void printOptions();
void printOption(int row, const char* option);
char getch_linux();
void mainLoop();