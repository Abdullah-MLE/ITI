#include <iostream>
using namespace std;
#define ESC '\x1b'

#define BrightBlack 90
#define BrightRed 91
#define BrightGreen 92
#define BrightYellow 93
#define BrightBlue 94
#define BrightMagenta 95
#define BrightCyan 96
#define BrightWhite 97


#define Bold "[1m"
#define Regular "[2m"
#define Italic "[3m"
#define Underline "[4m"
#define Blinking "[5m"


// Cursor position
void moveCursor(int x, int y);

// Styles and Colors
void setColor(int color);
void setBGColor(int color);
void resetStyle();

// Screen control
void clearScreen();
void clearLine();
void clearToEndOfLine();
void clearArea(int x1, int y1, int x2, int y2);

// Cursor visibility
void hideCursor();
void showCursor();

// Text formatting
void changeFormattingStyle(const char* style);
