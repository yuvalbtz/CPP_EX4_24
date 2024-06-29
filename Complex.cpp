#include <cmath>
#include <ostream>
#include <sstream>
#include "Complex.hpp"

using namespace std;

// Constructors
Complex::Complex() : real(0), imag(0) {}

Complex::Complex(double r, double i) : real(r), imag(i) {}

// Getter methods
double Complex::getReal() const { return real; }

double Complex::getImag() const { return imag; }

// Overloaded operators for arithmetic operations
Complex Complex::operator+(const Complex &other) const {
    return {real + other.real, imag + other.imag};
}

Complex Complex::operator-(const Complex &other) const {
    return {real - other.real, imag - other.imag};
}

Complex Complex::operator*(const Complex &other) const {
    return {real * other.real - imag * other.imag, real * other.imag + imag * other.real};
}


// Overloaded operators for comparison
bool Complex::operator==(const Complex &other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

bool Complex::operator<(const Complex &other) const {
    return sqrt(real * real + imag * imag) < sqrt(other.real * other.real + other.imag * other.imag);
}

bool Complex::operator>(const Complex &other) const {
    return other < *this;
}

bool Complex::operator<=(const Complex &other) const {
    return !(other < *this);
}

bool Complex::operator>=(const Complex &other) const {
    return !(*this < other);
}

// Output stream operator
ostream &operator<<(ostream &os, const Complex &c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}


// Method to return string representation
string Complex::to_string_complex() const {
    ostringstream os;
    os << real << " + " << imag << "i";
    return os.str();
}
