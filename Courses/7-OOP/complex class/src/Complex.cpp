#include "../include/Complex.h"

// ctor
Complex::Complex() {
  cout << "Initialization (0, 0) Object Complex" << endl;
  real = 0;
  img = 0;
}

// ctor
Complex::Complex(int real, int img) {
  cout << "Initialization (" << real << ", " << img << ") Object Complex"
       << endl;
  this->real = real;
  this->img = img;
}

int Complex::getImg() const { return img; }
int Complex::getReal() const { return real; }

void Complex::setComplex(int real, int img) {
  this->real = real;
  this->img = img;
}

// copy ctor
// Complex::Complex(Complex& s) {}

// dtor
Complex::~Complex() { cout << "Good By Complex :: " << endl; }

// =========================
void Complex::display(void) {}

// operator-overloading
//   Arithmetic:
//     - Addition (+) (Returning a new Complex object)
Complex Complex::operator+(const int x) const {
  return Complex(this->real + x, this->img);
}
Complex Complex::operator+(const Complex& other) const {
  return Complex(this->real + other.real, this->img + other.img);
}
Complex operator+(const int x, const Complex& c) {
  return Complex(x + c.real, c.img);
}

//     - Subtraction (-) (Returning a new Complex object)
Complex Complex::operator-(const int x) const {
  return Complex(this->real - x, this->img);
}
Complex Complex::operator-(const Complex& other) const {
  return Complex(this->real - other.real, this->img - other.img);
}
Complex operator-(const int x, const Complex& c) {
  return Complex(x - c.real, c.img);
}

//     - Multiplication (*) (Returning a new Complex object)
Complex Complex::operator*(const int x) const {
  return Complex(this->real * x, this->img * x);
}
Complex Complex::operator*(const Complex& other) const {
  return Complex(this->real * other.real, this->img * other.img);
}
Complex operator*(const int x, const Complex& c) {
  return Complex(x * c.real, c.img * x);
}

//     - Division (/) (Returning a new Complex object)
Complex Complex::operator/(const int x) const {
  return Complex(this->real / x, this->img / x);
}
Complex Complex::operator/(const Complex& other) const {
  return Complex(this->real / other.real, this->img / other.img);
}
Complex operator/(const int x, const Complex& c) {
  return Complex(x / c.real, c.img / 5);
}

//   Compound arithmetic:
//     - Addition assignment (+=) (Modifying the current Complex object)
Complex& Complex::operator+=(const int x) {
  this->real += x;
  this->img += x;
  return *this;
}
Complex& Complex::operator+=(const Complex& other) {
  this->real += other.real;
  this->img += other.img;
  return *this;
}

//     - Subtraction assignment (-=) (Modifying the current Complex object)
Complex& Complex::operator-=(const int x) {
  this->real -= x;
  this->img -= x;
  return *this;
}
Complex& Complex::operator-=(const Complex& other) {
  this->real -= other.real;
  this->img -= other.img;
  return *this;
}

//     - Multiplication assignment (*=) (Modifying the current Complex object)
Complex& Complex::operator*=(const int x) {
  this->real *= x;
  this->img *= x;
  return *this;
}
Complex& Complex::operator*=(const Complex& other) {
  this->real *= other.real;
  this->img *= other.img;
  return *this;
}

//     - Division assignment (/=) (Modifying the current Complex object)
Complex& Complex::operator/=(const int x) {
  this->real /= x;
  this->img /= x;
  return *this;
}
Complex& Complex::operator/=(const Complex& other) {
  this->real /= other.real;
  this->img /= other.img;
  return *this;
}

// Comparison:
//     - Equality (==) (Returning a boolean)
bool Complex::operator==(const Complex& other) const {
  return (this->real == other.real && this->img == other.img);
}

//     - Inequality (!=) (Returning a boolean)
bool Complex::operator!=(const Complex& other) const {
  return (this->real != other.real && this->img != other.img);
}

//     - Less than (<) (Returning a boolean)
bool Complex::operator<(const Complex& other) const {
  if (this->real < other.real && this->img < other.img) return 1;
  return 0;
}

//     - Greater than (>) (Returning a boolean)
bool Complex::operator>(const Complex& other) const {
  if (this->real > other.real && this->img > other.img) return 1;
  return 0;
}

// Increment/decrement:
//     - Pre-increment (++Complex) (Modifying the current Complex object)
Complex& Complex::operator++() {
  this->real++;
  this->img++;
  return *this;
}

//     - Post-increment (Complex++) (Returning a new Complex object)
Complex Complex::operator++(int) {
  Complex old = *this;
  this->real++;
  this->img++;
  return old;
}

//     - Pre-decrement (--Complex) (Modifying the current Complex object)
Complex& Complex::operator--() {
  this->real--;
  this->img--;
  return *this;
}

//     - Post-decrement (Complex--) (Returning a new Complex object)
Complex Complex::operator--(int) {
  Complex old = *this;
  this->real--;
  this->img--;
  return old;
}

// Unary operators:
//     - Unary minus (-Complex) (Returning a new Complex object)
Complex operator-(Complex c) { return Complex(-c.real, c.img); }

// Stream input/output:
//     - Output stream (<<) (Returning a reference to the output stream)
ostream& operator<<(ostream& out, const Complex& c) {
  if (c.real != 0) {
    out << c.real;
  }
  if (c.img != 0) {
    (c.img > 0) ? out << "+" << c.img << "j" << endl
                : out << c.img << "j" << endl;
  }
  return out;
}

//     - Input stream (>>) (Returning a reference to the input stream)
std::istream& operator>>(std::istream& in, Complex& c) {
  int r;
  int i;
  if (in >> r >> i) {
    c.setComplex(r, i);
  }
  return in;
}

// Assignment:
//     - Assignment (=) (Modifying the current Complex object)
Complex& Complex::operator=(const Complex& other) {
  this->real = other.real;
  this->img = other.img;
  return *this;
}

// Logical:
//     - Logical AND (&&) (Returning a boolean)
bool Complex::operator&&(const int x) const {
  return (x != 0 && this->real != 0);
}

bool Complex::operator&&(const Complex& other) const {
  return (this->real != 0 && other.real != 0);
}

bool operator&&(const int x, const Complex& c) {
  return (x != 0 && c.real != 0);
}

//     - Logical OR (||) (Returning a boolean)
bool Complex::operator||(const int x) const {
  return (x != 0 || this->real != 0);
}

bool Complex::operator||(const Complex& other) const {
  return (this->real != 0 || other.real != 0);
}
bool operator||(const int x, const Complex& c) {
  return (x != 0 && c.real != 0);
}

//     - Logical NOT (!) (Returning a boolean)
bool Complex::operator!() const { return !(this->real); }

// Access and call:
//     - Subscript operator ([]) (Returning a reference to the real or
//     imaginary part)
int& Complex::operator[](const int x) {
  switch (x) {
    case 0:
      return this->real;
    case 1:
      return this->img;
  }
  // Throw Ex
  return this->real;
}

//     - Function call operator () (Returning a new Complex object)
int& Complex::operator()(const int x) {
  switch (x) {
    case 0:
      return this->real;
    case 1:
      return this->img;
  }
  // Throw Ex
  return this->real;
}
