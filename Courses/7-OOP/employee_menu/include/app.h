#include <iostream>
using namespace std;

#include <termios.h>
#include <unistd.h>

#include "../include/lib.h"

#define BG_WIDTH 81
#define BG_HEIGHT 24
#define EMPLOYEE_CAPACITY 2

#define MENU_OPTION_COUNT 3
#define menuText1 "New Employee"
#define menuText2 "Display"
#define menuText3 "Exit"

#define DB_OPTION_COUNT 3
#define DBMenu1 "Static  DB"
#define DBMenu2 "Dynamic DB"

#define HomePage "HOME"
#define NewEmpPage "NEW EMPLOYEE"
#define EmployeeAddedPage "NEW EMPLOYEE ADDED"
#define EmployeeTablePage "EMPLOYEE TABLE"
#define ExitPage "SEE YOU AGIN :)"
#define FullMemoryPage "!!!"
#define DBSizePage "SELECT THE SIZE OF STATIC DB"

#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3

#define CurAt

void mainLoop();
void highlight(int cur);