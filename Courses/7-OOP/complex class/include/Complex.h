#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

#define LOG(str) std::cout << str << std::endl  // Macors
class Complex {
 public:
  Complex();
  Complex(int real = 0, int img = 0);
  Complex(Complex& s);
  ~Complex();

  void setComplex(int real, int img);
  int getReal() const;
  int getImg() const;
  void display();

  // operator-overloading
  //   Arithmetic:
  //     - Addition (+) (Returning a new Complex object)
  Complex operator+(const int x) const;
  Complex operator+(const Complex& other) const;
  friend Complex operator+(const int x, const Complex& c);

  //     - Subtraction (-) (Returning a new Complex object)
  Complex operator-(const int x) const;
  Complex operator-(const Complex& other) const;
  friend Complex operator-(const int x, const Complex& c);

  //     - Multiplication (*) (Returning a new Complex object)
  Complex operator*(const int x) const;
  Complex operator*(const Complex& other) const;
  friend Complex operator*(const int x, const Complex& c);

  //     - Division (/) (Returning a new Complex object)
  Complex operator/(const int x) const;
  Complex operator/(const Complex& other) const;
  friend Complex operator/(const int x, const Complex& c);

  //   Compound arithmetic:
  //     - Addition assignment (+=) (Modifying the current Complex object)
  Complex& operator+=(const int x);
  Complex& operator+=(const Complex& other);

  //     - Subtraction assignment (-=) (Modifying the current Complex object)
  Complex& operator-=(const int x);
  Complex& operator-=(const Complex& other);

  //     - Multiplication assignment (*=) (Modifying the current Complex object)
  Complex& operator*=(const int x);
  Complex& operator*=(const Complex& other);

  //     - Division assignment (/=) (Modifying the current Complex object)
  Complex& operator/=(const int x);
  Complex& operator/=(const Complex& other);

  // Comparison:
  //     - Equality (==) (Returning a boolean)
  bool operator==(const Complex& other) const;

  //     - Inequality (!=) (Returning a boolean)
  bool operator!=(const Complex& other) const;

  //     - Less than (<) (Returning a boolean)
  bool operator<(const Complex& other) const;

  //     - Greater than (>) (Returning a boolean)
  bool operator>(const Complex& other) const;

  // Increment/decrement:
  //     - Pre-increment (++Complex) (Modifying the current Complex object)
  Complex& operator++();

  //     - Post-increment (Complex++) (Returning a new Complex object)
  Complex operator++(int);

  //     - Pre-decrement (--Complex) (Modifying the current Complex object)
  Complex& operator--();

  //     - Post-decrement (Complex--) (Returning a new Complex object)
  Complex operator--(int);

  // Unary operators:
  //     - Unary minus (-Complex) (Returning a new Complex object)
  friend Complex operator-(Complex c);

  // Stream input/output:
  //     - Output stream (<<) (Returning a reference to the output stream)
  friend ostream& operator<<(ostream& out, const Complex& c);

  //     - Input stream (>>) (Returning a reference to the input stream)
  friend istream& operator>>(istream& out, const Complex& c);

  // Assignment:
  //     - Assignment (=) (Modifying the current Complex object)
  Complex& operator=(const Complex& other);

  // Logical:
  //     - Logical AND (&&) (Returning a boolean)
  bool operator&&(const int x) const;
  bool operator&&(const Complex& other) const;
  friend bool operator&&(const int x, const Complex& c);

  //     - Logical OR (||) (Returning a boolean)
  bool operator||(const int x) const;
  bool operator||(const Complex& other) const;
  friend bool operator||(const int x, const Complex& c);

  //     - Logical NOT (!) (Returning a boolean)
  bool operator!() const;

  // Access and call:
  //     - Subscript operator ([]) (Returning a reference to the real or
  //     imaginary part)
  int& operator[](const int x);

  //     - Function call operator () (Returning a new Complex object)
  int& operator()(const int x);

 protected:
 private:
  int real;
  int img;
};

#endif  // COMPLEX_H
