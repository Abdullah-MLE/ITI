#include "../include/app.h"

#include "../include/lib.h"

// ============ employee class ============
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

int findEmptyEmployeeIndex(employee* employees, int capacity) {
  int i = 0;

  while (i < capacity && employees[i].age != 0) {
    i++;
  }

  return i;
}

employee* initializeEmployeesArray(int capacity) {
  employee* employess = new employee[capacity];
  return employess;
}

employee* extendDB(employee* employees, int* capacity) {
  employee* employees2 = initializeEmployeesArray(*capacity * 2);

  int i = 0;
  while (i < *capacity && employees[i].age != 0) {
    employees2[i] = employees[i];
    i++;
  }
  *capacity *= 2;

  return employees2;
}

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
void drawFrame(const char* pageName, int DBType) {
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
  cout << "Employee MS-";
  if (DBType == -1)
    cout << DBMenu2 << " ✓";
  else
    cout << DBMenu1 << " " << DBType;

  moveCursor(1, getWidthCenter(pageName));
  cout << pageName;

  moveCursor(1, BG_WIDTH - 22);
  cout << "Navigate with arrows";

  moveCursor(BG_HEIGHT, 3);
  cout << "'H' for hmoe page, 'E' for adding employee page, 'Q' to exit";
  resetStyle();
}

// ============ menu options healpers ============
int OptionRow(int cur) {
  int centerROW = BG_HEIGHT / 2;
  switch (cur) {
    case 0:
      return centerROW - 2;
    case 1:
      return centerROW;
    case 2:
      return centerROW + 2;
    case 3:
      return centerROW - 1;
    case 4:
      return centerROW + 1;
    default:
      return -1;
  }
}

const char* getOptionText(int cur) {
  switch (cur) {
    case 0:
      return menuText1;
    case 1:
      return menuText2;
    case 2:
      return menuText3;
    case 3:
      return DBMenu1;
    case 4:
      return DBMenu2;
    default:
      return "";
  }
}

// ============ menu options ============
void printOption(int row, const char* option, int color = 0, int BGColor = 0,
                 int underLine = 0) {
  int centerCol = getWidthCenter(option);

  moveCursor(row, centerCol);
  if (BGColor) setBGColor(BGColor);
  if (underLine) changeFormattingStyle(Underline);
  if (color) setColor(color);
  cout << option;
  resetStyle();
}

void printOptions() {
  for (int i = 0; i < MENU_OPTION_COUNT; i++)
    printOption(OptionRow(i), getOptionText(i));

  highlight(0);
}

void printDBOption(int row, const char* option, int color = 0, int BGColor = 0,
                   int underLine = 0, int checkd = 0) {
  int centerCol = BG_WIDTH / 3 * 2;

  moveCursor(row, centerCol);
  if (BGColor) setBGColor(BGColor);
  if (underLine) changeFormattingStyle(Underline);
  if (color) setColor(color);
  if (checkd)
    cout << option << " ✓ ";
  else
    cout << option << " _ ";
  resetStyle();
}

void printDBOptions() {
  for (int i = 3; i < 5; i++) printDBOption(OptionRow(i), getOptionText(i));
}

// ============ highlighting ============
void highlight(int cur) {
  clearArea(OptionRow(cur), 4, OptionRow(cur), BG_WIDTH - 4);

  if (cur < 3)
    printOption(OptionRow(cur), getOptionText(cur), BrightBlack, BrightWhite,
                1);

  else
    printDBOption(OptionRow(cur), getOptionText(cur), BrightBlack, BrightWhite,
                  1, 1);
}

void deHighlight(int cur) {
  clearArea(OptionRow(cur), 4, OptionRow(cur), BG_WIDTH - 4);

  if (cur < 3)
    printOption(OptionRow(cur), getOptionText(cur));

  else
    printDBOption(OptionRow(cur), getOptionText(cur));
}

// ============ navigate ============
void navigate(int* cur, int direction) {
  deHighlight(*cur);

  if (direction == UP && *cur > 0)
    *cur = *cur - 1;

  else if (direction == DOWN && *cur < MENU_OPTION_COUNT + DB_OPTION_COUNT - 2)
    *cur = *cur + 1;

  else if (direction == RIGHT && *cur < MENU_OPTION_COUNT)
    *cur = 3;

  else if (direction == LEFT && *cur > MENU_OPTION_COUNT - 1)
    *cur = 0;

  highlight(*cur);
}

// ============ pages ============
void mainPage(int* cur, int DBType) {
  hideCursor();
  clearScreen();
  *cur = 0;
  drawFrame(HomePage, DBType);
  printOptions();
  printDBOptions();
}

void exitPage(int* cur, int DBType) {
  clearScreen();
  drawFrame(ExitPage, DBType);
  moveCursor(5, 5);
  cout << "thanks for using our app.";
  moveCursor(6, 5);
  cout << "Press Enter to exit!";
}

void fullMemoryPage(int DBType) {
  clearScreen();
  drawFrame(FullMemoryPage, DBType);
  moveCursor(2, 3);
  cout << "Employee database is full!";
}

employee* selectingStaticDBPage(int* capacity, int* DBType) {
  clearScreen();
  drawFrame(DBSizePage, *DBType);

  int start_col = getWidthCenter("Please enter the size of the satic DB:   ");
  int line = 3;

  showCursor();

  moveCursor(line++, start_col);
  cout << "The curent DB will Be overwrite!!";
  line++;

  moveCursor(line++, start_col);
  cout << "Please enter the size of the satic DB: ";
  cin >> *capacity;
  *DBType = *capacity;
  cin.ignore();

  hideCursor();
  employee* employess = initializeEmployeesArray(*capacity);
  return employess;
}

// ============ employee pages ============
void EmpAddedPage(employee* employees, int capacity, int DBType) {
  int index = findEmptyEmployeeIndex(employees, capacity);

  clearScreen();
  drawFrame(EmployeeAddedPage, DBType);

  int start_col = getWidthCenter("you are using static DB size =   ");
  int line = 3;

  moveCursor(line++, start_col);
  cout << "you are using ";
  if (DBType == -1)
    cout << "Dynamic DB! ";
  else {
    cout << "static DB size = " << capacity;

    moveCursor(line++, start_col);
    cout << "Remaing size is: " << capacity - index;
    line++;
  }

  moveCursor(line++, start_col);
  cout << "Employee added successfully!";

  moveCursor(line++, start_col);
  if (index == capacity && DBType != -1) cout << "DB is Full!";
}

void addEmp(int line, int start_col, int index, employee* employees,
            int capacity) {
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

void addSaticEmpPage(employee* employees, int capacity, int DBType) {
  int index = findEmptyEmployeeIndex(employees, capacity);
  if (index == capacity) fullMemoryPage(DBType);

  clearScreen();
  drawFrame(NewEmpPage, DBType);
  showCursor();

  int start_col = getWidthCenter("you are using static DB size =   ");
  int line = 3;

  moveCursor(line++, start_col);
  cout << "you are using static DB size = " << capacity;

  moveCursor(line++, start_col);
  cout << "Remaing size is: " << capacity - index;
  line++;

  addEmp(line, start_col, index, employees, capacity);
}

void addDynaimcEmpPage(employee* employees, int* capacity, int DBType) {
  int index = findEmptyEmployeeIndex(employees, *capacity);
  int line = 3;
  int start_col = getWidthCenter("you are using Dynamic DB");

  clearScreen();
  drawFrame(NewEmpPage, DBType);
  showCursor();
  
  if (index >= *capacity) {
    extendDB(employees, capacity);
    moveCursor(line++, start_col);
    cout << "DB Extened!!!";
    line++;
  }
  moveCursor(line++, start_col);
  cout << "you are using Dynamic DB";
  line++;

  addEmp(line, start_col, index, employees, *capacity);
}

void dispalyEmployeesPage(employee* employees, int capacity, int DBType) {
  clearScreen();
  drawFrame(EmployeeTablePage, DBType);
  int line = 3;

  int centerCol = getWidthCenter(
      "+----------------------+----------------------+-----+--------+");

  // DB info
  moveCursor(line++, getWidthCenter("you are using static DB size =   "));
  cout << "you are using ";
  if (DBType == -1)
    cout << "Dynamic DB";
  else
    cout << "static DB size = " << capacity;

  // Table header
  moveCursor(line++, centerCol);
  cout << "+----------------------+----------------------+-----+--------+";
  moveCursor(line++, centerCol);
  cout << "| First Name           | Last Name            | Age | Salary |";
  moveCursor(line++, centerCol);
  cout << "+----------------------+----------------------+-----+--------+";

  // Employees rows
  int i = 0;
  while (employees[i].age != 0) {
    moveCursor(line, centerCol);
    cout << "| " << employees[i].firstName;

    moveCursor(line, centerCol + 22);
    cout << " | " << employees[i].lastName;

    moveCursor(line, centerCol + 45);
    cout << " | " << employees[i].age;

    moveCursor(line, centerCol + 51);
    cout << " | " << employees[i].salary;

    moveCursor(line++, centerCol + 60);
    cout << " |";

    moveCursor(line++, centerCol);
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
  int cur = 0;
  bool running = true;
  int capacity = EMPLOYEE_CAPACITY;
  int DBType = capacity;

  mainPage(&cur, DBType);

  employee* employess = initializeEmployeesArray(capacity);
  testData(employess);

  while (running) {
    char byte1 = getch_linux();

    // EXIT
    if (byte1 == 'q' || byte1 == 'Q' || (cur == 2 && byte1 == '\n')) {
      exitPage(&cur, DBType);
      running = false;
    }

    // Employees
    else if (byte1 == 'E' || (cur == 0 && byte1 == '\n')) {
      if (DBType == -1)
        addDynaimcEmpPage(employess, &capacity, DBType);
      else
        addSaticEmpPage(employess, capacity, DBType);
      EmpAddedPage(employess, capacity, DBType);

    }

    // Display
    else if (cur == 1 && byte1 == '\n')
      dispalyEmployeesPage(employess, capacity, DBType);

    // static DB
    else if (cur == 3 && byte1 == '\n') {
      employess = selectingStaticDBPage(&capacity, &DBType);
      mainPage(&cur, DBType);
    }

    // Dynamic DB
    else if (cur == 4 && byte1 == '\n') {
      employess = initializeEmployeesArray(EMPLOYEE_CAPACITY);
      capacity = EMPLOYEE_CAPACITY;
      DBType = -1;
      mainPage(&cur, DBType);

    }

    // home
    else if (byte1 == 'H')
      mainPage(&cur, DBType);

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

        case 'C':
          navigate(&cur, RIGHT);
          break;

        case 'D':
          navigate(&cur, LEFT);
          break;
      }
    }
  }
}
