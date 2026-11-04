#include <iostream>

#define ToUpper 0
#define ToLower 1
#define StringCompaare 2
#define StringCopy 3
char* toupper(char* str1) {
  int i = 0;
  while (str1[i] != '\0') {
    if (str1[i] >= 'a' && str1[i] <= 'z') {
      str1[i] -= 32;
    }
    i++;
  }

  return str1;
}

char* tolower(char* str1) {
  int i = 0;
  while (str1[i] != '\0') {
    if (str1[i] >= 'A' && str1[i] <= 'Z') {
      str1[i] += 32;
    }
    i++;
  }

  return str1;
}

int stringcompare(char* str1, char* str2) { return 0; }

int stringcopy(char* str1, char* str2) { return 0; }

int str(int fun, char* str1, char* str2) {
  switch (fun) {
    case ToUpper:
      std::cout << "output: " << toupper(str1);
      break;
    case ToLower:
      std::cout << tolower(str1);
      break;
    case StringCompaare:
      std::cout << stringcompare(str1, str2);
    case StringCopy:
      std::cout << stringcopy(str1, str2);
    default:
      std::cout << "please chose correct function!!";
  }
  return 0;
}
