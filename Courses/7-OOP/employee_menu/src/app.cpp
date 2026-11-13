#include "../include/app.h"

#include "../include/lib.h"

char getch_linux() {
  char buf = 0;
  struct termios old = {0};
  tcgetattr(0, &old);
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &old);
  read(0, &buf, 1);
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  tcsetattr(0, TCSADRAIN, &old);
  return buf;
}

void drawFrame() {
  // printing up and down fram
  for (int i = 0; i < BG_WIDTH; i++) {
    printBGCell(0, i, BrightYellow);
    printBGCell(BG_HEIGHT, i, BrightYellow);
  }

  // printing left and right fram
  for (int i = 0; i < BG_HEIGHT; i++) {
    printBGCell(i, 1, BrightYellow);
    printBGCell(i, 2, BrightYellow);
    printBGCell(i, BG_WIDTH - 1, BrightYellow);
    printBGCell(i, BG_WIDTH - 2, BrightYellow);
  }
  resetStyle();
  cout.flush();
}

int getWidthCenter(const char* text) {
  int count = 0;
  while (text[count] != '\0') {
    count++;
  }

  return (BG_WIDTH - count) / 2;
}

void printOption(int row, const char* option, int color = 0, int BGColor = 0,
                 int underLine = 0) {
  int center_col = getWidthCenter(option);
  moveCursor(row, center_col);
  if (BGColor) setBGColor(BGColor);
  if (underLine) changeFormattingStyle(Underline);
  if (color) setColor(color);
  cout << option;
  resetStyle();
  cout.flush();
}

void printOptions() {
  int start_row = BG_HEIGHT / 2;
  printOption(start_row - 2, menuText1);
  printOption(start_row, menuText2);
  printOption(start_row + 2, menuText3);

  highlightHelper(start_row - 2, menuText1);
  cout.flush();
}

void highlightHelper(int row, const char* option) {
  clearArea(row, 4, row, BG_WIDTH - 4);
  printOption(row, option, BrightBlack, BrightWhite, 1);
  cout.flush();
}

void deHighlightHelper(int row, const char* option) {
  clearArea(row, 4, row, BG_WIDTH - 4);
  printOption(row, option);
  cout.flush();
}

void highlight(int cur) {
  int start_row = BG_HEIGHT / 2;
  switch (cur) {
    case 0:
      highlightHelper(start_row - 2, menuText1);
      break;
    case 1:
      highlightHelper(start_row, menuText2);
      break;
    case 2:
      highlightHelper(start_row + 2, menuText3);
      break;
  }
}

void deHighlight(int cur) {
  int start_row = BG_HEIGHT / 2;
  switch (cur) {
    case 0:
      deHighlightHelper(start_row - 2, menuText1);
      break;
    case 1:
      deHighlightHelper(start_row, menuText2);
      break;
    case 2:
      deHighlightHelper(start_row + 2, menuText3);
      break;
  }
}

void navigate(int* cur, int direction) {
  if (direction == UP && *cur > 0) {
    deHighlight(*cur);
    *cur = *cur - 1;
    highlight(*cur);
    cout.flush();

  } else if (direction == DOWN && *cur != 2) {
    deHighlight(*cur);
    *cur = *cur + 1;
    highlight(*cur);
    cout.flush();
  }
}

void mainPage(int* cur) {
  hideCursor();
  clearScreen();
  *cur = 0;
  drawFrame();
  printOptions();
  cout.flush();
}

void exitPage(int* cur) {
  clearScreen();
  drawFrame();
  moveCursor(5, 5);
  cout << "thanks for using our app.";
  moveCursor(6, 5);
  cout << "Press Enter to exit!";
  cout.flush();
}

struct employee {
  char name[20] = {'\0'};
  int age = 0;
};

void addEmployeePage(int* cur, employee* prtToEmps) {
  int i = 0;
  while(prtToEmps[i].age == 0){
    i++;
  }
  
  clearScreen();
  clearScreen();
  drawFrame();
  moveCursor(2, 3);
  cout << "you are using static DB size = " << "20";
  moveCursor(3, 3);
  cout << "Remaing size is: " << "10";

  moveCursor(5, 3);
  cout << "enter the Employee name: ";
  cin >> prtToEmps[i].name;

  moveCursor(6, 3);
  cout << "Enter the Emp age: ";
  cin >> prtToEmps[i].age;
  cout.flush();
}

void mainLoop() {
  int cur = 0;

  char byte1 = '\0';
  char byte2 = '\0';
  char byte3 = '\0';

  employee EmstaticEmpArray[20];
  mainPage(&cur);

  while (byte1 != 'q' && byte1 != 'Q') {
    byte1 = getch_linux();
    if (byte1 == 'q' || byte1 == 'Q') {
      exitPage(&cur);

    } else if (byte1 == 'E')
      addEmployeePage(&cur, &EmstaticEmpArray[0]);

    else if (byte1 == 'H')
      mainPage(&cur);

    else if (byte1 == ESC) {
      byte2 = getch_linux();
      byte3 = getch_linux();
      switch (byte3) {
        case 'A':  // UP
          navigate(&cur, UP);
          break;

        case 'B':  // DOWN
          navigate(&cur, DOWN);
          break;
      }
    }
  }
}
