#include "../include/app.h"

#include "../include/lib.h"

// ============ employee ============
class employee {
 public:
  char firstName[20];
  char lastName[20];
  int age;
  int salary;
  employee() {
    age = 0;
    lastName[0] = '\0';
    age = 0;
    salary = 0;
  }
};

// ============ healpers ============
void copyString(char dest[], const char src[]) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

int getWidthCenter(const char* text) {
  int count = 0;
  while (text[count] != '\0') {
    count++;
  }

  return (BG_WIDTH - count) / 2;
}

int findEmptyEmployeeIndex(employee* employees, int capacity) {
  int i = 0;

  while (i < capacity && employees[i].age != 0) {
    i++;
  }

  return i;
}

// ============ terminal input -AI- ============
char getch_linux() {
  char key;

  struct termios old_settings{};
  struct termios new_settings{};

  // Save original settings
  tcgetattr(0, &old_settings);

  // Copy settings
  new_settings = old_settings;

  // Enable instant input
  new_settings.c_lflag &= ~(ICANON | ECHO);
  new_settings.c_cc[VMIN] = 1;
  new_settings.c_cc[VTIME] = 0;

  // Apply new settings
  tcsetattr(0, TCSANOW, &new_settings);

  // Read using C++, not read()
  cin.get(key);

  // Restore original settings
  tcsetattr(0, TCSANOW, &old_settings);

  return key;
}

// ============ frame ============
void drawFrame(const char* pageName) {
  // printing up and down fram
  for (int i = 0; i < BG_WIDTH; i++) {
    printBGCell(0, i, BrightBlack);
    printBGCell(BG_HEIGHT, i, BrightBlack);
  }

  // printing left and right fram
  for (int i = 0; i < BG_HEIGHT; i++) {
    printBGCell(i, 1, BrightBlack);
    printBGCell(i, 2, BrightBlack);
    printBGCell(i, BG_WIDTH - 1, BrightBlack);
    printBGCell(i, BG_WIDTH - 2, BrightBlack);
  }

  moveCursor(1, 3);
  cout << "Employee MS";

  moveCursor(1, getWidthCenter(pageName));
  cout << pageName;

  moveCursor(1, BG_WIDTH - 22);
  cout << "Navigate with arrows";

  moveCursor(BG_HEIGHT, 3);
  cout << "'H' for hmoe page, 'E' for adding employee page, 'Q' to exit";
  resetStyle();
}

// ============ menu options healpers ============
int getOptionSRtartRow(int index) {
  int startRow = BG_HEIGHT / 2;

  return startRow - 2 + (index * 2);
}

const char* getOptionText(int index) {
  switch (index) {
    case 0:
      return menuText1;

    case 1:
      return menuText2;

    case 2:
      return menuText3;
  }

  return "";
}

// ============ menu options ============
void printOption(int row, const char* option, int color = 0, int BGColor = 0,
                 int underLine = 0) {
  int center_col = getWidthCenter(option);
  moveCursor(row, center_col);
  if (BGColor) setBGColor(BGColor);
  if (underLine) changeFormattingStyle(Underline);
  if (color) setColor(color);
  cout << option;
  resetStyle();
}

void printOptions() {
  for (int i = 0; i < MENU_OPTION_COUNT; i++)
    printOption(getOptionSRtartRow(i), getOptionText(i));

  highlight(0);
}

// ============ highlighting ============
void highlightHelper(int row, const char* option) {
  clearArea(row, 4, row, BG_WIDTH - 4);
  printOption(row, option, BrightBlack, BrightWhite, 1);
}

void deHighlightHelper(int row, const char* option) {
  clearArea(row, 4, row, BG_WIDTH - 4);
  printOption(row, option);
}

void highlight(int cur) {
  highlightHelper(getOptionSRtartRow(cur), getOptionText(cur));
}

void deHighlight(int cur) {
  int start_row = BG_HEIGHT / 2;
  deHighlightHelper(getOptionSRtartRow(cur), getOptionText(cur));
}

// ============ navigate ============
void navigate(int* cur, int direction) {
  if (direction == UP && *cur > 0) {
    deHighlight(*cur);
    *cur = *cur - 1;
    highlight(*cur);

  } else if (direction == DOWN && *cur != MENU_OPTION_COUNT - 1) {
    deHighlight(*cur);
    *cur = *cur + 1;
    highlight(*cur);
  }
}

// ============ pages ============
void mainPage(int* cur) {
  hideCursor();
  clearScreen();
  *cur = 0;
  drawFrame(HomePage);
  printOptions();
}

void exitPage(int* cur) {
  clearScreen();
  drawFrame(ExitPage);
  moveCursor(5, 5);
  cout << "thanks for using our app.";
  moveCursor(6, 5);
  cout << "Press Enter to exit!";
}

void fullMemoryPage() {
  clearScreen();
  drawFrame(FullMemoryPage);
  moveCursor(2, 3);
  cout << "Employee database is full!";
}

// ============ employee pages ============
void employeeAddedPage(int* cur, employee* employees, int capacity) {
  int index = findEmptyEmployeeIndex(employees, capacity);

  clearScreen();
  drawFrame(EmployeeAddedPage);

  int start_col = getWidthCenter("you are using static DB size =   ");
  int line = 3;

  moveCursor(line++, start_col);
  cout << "you are using static DB size = " << capacity;

  moveCursor(line++, start_col);
  cout << "Remaing size is: " << capacity - index;
  line++;

  moveCursor(line++, start_col);
  cout << "Employee added successfully!";

  moveCursor(line++, start_col);
  if (index == capacity) cout << "DB is Full!";
}

void addEmployeePage(int* cur, employee* employees, int capacity) {
  int index = findEmptyEmployeeIndex(employees, capacity);
  if (index == capacity) fullMemoryPage();

  clearScreen();
  drawFrame(NewEmpPage);
  showCursor();

  int start_col = getWidthCenter("you are using static DB size =   ");
  int line = 3;

  moveCursor(line++, start_col);
  cout << "you are using static DB size = " << capacity;

  moveCursor(line++, getWidthCenter("you are using static DB size =   "));
  cout << "Remaing size is: " << capacity - index;
  line++;

  moveCursor(line++, start_col);
  cout << "enter the Employee firstName: ";
  cin >> employees[index].firstName;

  moveCursor(line++, start_col);
  cout << "Enter the Emp lastName: ";
  cin >> employees[index].lastName;

  moveCursor(line++, start_col);
  cout << "Enter the Emp age: ";
  cin >> employees[index].age;

  moveCursor(line++, start_col);
  cout << "Enter the Emp salary: ";
  cin >> employees[index].salary;

  hideCursor();
  cin.ignore();
}

void dispalyEmployeesPage(int* cur, employee* employees, int capacity) {
  clearScreen();
  drawFrame(EmployeeTablePage);
  int line = 3;

  int center_col = getWidthCenter(
      "+----------------------+----------------------+-----+--------+");

  // DB info
  moveCursor(line++, getWidthCenter("you are using static DB size =   "));
  cout << "you are using static DB size = " << capacity;

  // Table header
  moveCursor(line++, center_col);
  cout << "+----------------------+----------------------+-----+--------+";
  moveCursor(line++, center_col);
  cout << "| First Name           | Last Name            | Age | Salary |";
  moveCursor(line++, center_col);
  cout << "+----------------------+----------------------+-----+--------+";

  // Employees rows
  int i = 0;
  while (i < capacity && employees[i].age != 0) {
    moveCursor(line, center_col);
    cout << "| " << employees[i].firstName;

    moveCursor(line, center_col + 22);
    cout << " | " << employees[i].lastName;

    moveCursor(line, center_col + 45);
    cout << " | " << employees[i].age;

    moveCursor(line, center_col + 51);
    cout << " | " << employees[i].salary;

    moveCursor(line++, center_col + 60);
    cout << " |";

    moveCursor(line++, center_col);
    cout << "+----------------------+----------------------+-----+--------+";

    i++;
  }
}

// == test data ==
void testData(employee* employees) {
  // Employee 0
  copyString(employees[0].firstName, "Abdullah");
  copyString(employees[0].lastName, "Saeed");
  employees[0].age = 23;
  employees[0].salary = 5000;

  // Employee 1
  copyString(employees[1].firstName, "Mohamed");
  copyString(employees[1].lastName, "Kamal");
  employees[1].age = 22;
  employees[1].salary = 4000;

  // Employee 2
  copyString(employees[2].firstName, "Ali");
  copyString(employees[2].lastName, "Toson");
  employees[2].age = 56;
  employees[2].salary = 95000;
}

// ============ main loop ============
void mainLoop() {
  employee* EstaticEmpArray = new employee[EMPLOYEE_CAPACITY];
  testData(EstaticEmpArray);
  
  int cur = 0;
  bool running = true;
  
  mainPage(&cur);

  while (running) {
    char byte1 = getch_linux();
    
    if (byte1 == 'q' || byte1 == 'Q' || (cur == 2 && byte1 == '\n'))
      exitPage(&cur);

    else if (byte1 == 'E' || (cur == 0 && byte1 == '\n')) {
      addEmployeePage(&cur, EstaticEmpArray, EMPLOYEE_CAPACITY);
      employeeAddedPage(&cur, EstaticEmpArray, EMPLOYEE_CAPACITY);
    }

    else if (cur == 1 && byte1 == '\n')
      dispalyEmployeesPage(&cur, EstaticEmpArray, EMPLOYEE_CAPACITY);

    else if (byte1 == 'H')
      mainPage(&cur);

    else if (byte1 == ESC) {
      char byte2 = getch_linux();
      char byte3 = getch_linux();
      switch (byte3) {
        case 'A':
          navigate(&cur, UP);
          break;

        case 'B':
          navigate(&cur, DOWN);
          break;
      }
    }
  }
}
