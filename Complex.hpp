#ifndef CPP_EX4_COMPLEX_H
#define CPP_EX4_COMPLEX_H

#include <iostream>

class Complex {
private:
  double real;
  double imag;

public:
  // Constructors
  Complex();
  Complex(double r, double i);

  // Getter methods
  double getReal() const;
  double getImag() const;

  // Overloaded operators for arithmetic operations
  Complex operator+(const Complex &other) const;
  Complex operator-(const Complex &other) const;
  Complex operator*(const Complex &other) const;

  // Overloaded operators for comparison
  bool operator==(const Complex &other) const;
  bool operator!=(const Complex &other) const;
  bool operator<(const Complex &other) const;
  bool operator>(const Complex &other) const;
  bool operator<=(const Complex &other) const;
  bool operator>=(const Complex &other) const;

  // Output stream operator
  friend std::ostream &operator<<(std::ostream &os, const Complex &c);


  std::string to_string_complex() const;
};

#endif // CPP_EX4_COMPLEX_H
