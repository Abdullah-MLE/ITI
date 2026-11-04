#include "../include/app.h"
#include "../include/str.h"
#include <iostream>
#define ToUpper 0
#define ToLower 1
#define StringCompaare 2
#define StringCopy 3

int main() {
  char str1[] = "Hi";
  char str2[] = "hi2";
  str(ToLower, str1, str2);
  return 0;
}