#include <iostream>
using namespace std;
#define ToUpper 0
#define ToLower 1
#define StringCompaare 2
#define StringCopy 3
#define NotEqule 4
#define SizeDiff 5

#include "../include/str.h"


void toupper(char* str) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 32;
    }
    i++;
  }
}

void tolower(char* str) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
    }
    i++;
  }
}

int stringcompare(char* str1, char* str2) {
  while (true) {
    if (*str1 == '\0' && *str2 == '\0') return 0;
    if (*str1 == '\0' || *str2 == '\0') return SizeDiff;
    if (*str1 != *str2) return NotEqule;
    str1++;
    str2++;
  }
}

int lenth_of_array_of_chars(char* str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return ++i;
}

char* stringcopy(char* str) {
  int size = lenth_of_array_of_chars(str);
  char* copy = new char[size];
  for (int i = 0; i <= 5; i++) copy[i] = str[i];
  return copy;
}

int str(int fun, char* str1, char* str2) {
  int reslut;
  char* str_copy = NULL;
  switch (fun) {
    case ToUpper:
      toupper(str1);
      cout << "output: " << str1 << endl;
      break;

    case ToLower:
      tolower(str1);
      cout << "output: " << str1 << endl;
      break;

    case StringCompaare:
      // int reslut = stringcompare(str1, str2);
      // crosses initialization of ‘int reslut’
      reslut = stringcompare(str1, str2);
      switch (reslut) {
        case SizeDiff:
          cout << "the 2 given strings are not the sane size." << endl;
          break;

        case NotEqule:
          cout << "the 2 given strings are not the same value" << endl;
          break;

        default:
          cout << "string1 == string2!" << endl;
      }

      break;

    case StringCopy:
      str_copy = stringcopy(str1);
      cout << "the orginla string adress is: " << str1 << " is the stack."
           << endl;
      cout << "the copyes string adress is: " << str_copy << " in the heap."
           << endl;
      break;

    default:
      cout << "please chose correct function!!";
  }
  return 0;
}
