#include <iostream>
using namespace std;
#define Red 31
#define Green 33
#define Blue 32
#define ESC "\x1b"
#define BG_WIDTH 70
#define BG_HEIGHT 15
#define FRAM_COLOR 9

void show_tui_menu(char* text1, int color1, char* text2, int color2,
                   char* text3, int color3);