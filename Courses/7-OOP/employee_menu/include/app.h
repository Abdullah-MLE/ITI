#include <iostream>
using namespace std;

#include <termios.h>
#include <unistd.h>

#include "../include/lib.h"

#define BG_WIDTH 81
#define BG_HEIGHT 24
#define EMPLOYEE_CAPACITY 20

#define MENU_OPTION_COUNT 3
#define menuText1 "New Employee"
#define menuText2 "Display"
#define menuText3 "Exit"

#define HomePage "HOME"
#define NewEmpPage "NEW EMPLOYEE"
#define EmployeeAddedPage "NEW EMPLOYEE ADDED"
#define EmployeeTablePage "EMPLOYEE TABLE"
#define ExitPage "SEE YOU AGIN :)"
#define FullMemoryPage "!!!"

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