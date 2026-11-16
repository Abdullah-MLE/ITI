#include <iostream>
using namespace std;

#include "../include/Complex.h"

int main() {
  Complex c(5, 5);
  c[0] = 8;
  cout<<c.getReal();
  return 0;
}
