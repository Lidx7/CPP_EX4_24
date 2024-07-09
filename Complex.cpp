#include "Complex.hpp"
#include <iostream>

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Copy constructor
Complex::Complex(const Complex &other) : real(other.real), imag(other.imag) {}

// Getter for real part
double Complex::getReal() const {
    return real;
}

// Getter for imaginary part
double Complex::getImag() const {
    return imag;
}

// Addition
Complex Complex::operator+(const Complex &other) const {
    return Complex(real + other.real, imag + other.imag);
}

// Subtraction
Complex Complex::operator-(const Complex &other) const {
    return Complex(real - other.real, imag - other.imag);
}

// Multiplication
Complex Complex::operator*(const Complex &other) const {
    return Complex(real * other.real - imag * other.imag,
                   real * other.imag + imag * other.real);
}

// Division
Complex Complex::operator/(const Complex &other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denominator,
                   (imag * other.real - real * other.imag) / denominator);
}

// Overload the stream insertion operator for output
std::ostream& operator<<(std::ostream &out, const Complex &c) {
    out << c.real;
    if (c.imag >= 0) {
        out << " + " << c.imag << "i";
    } else {
        out << " - " << -c.imag << "i";
    }
    return out;
}

// Overload the stream extraction operator for input
std::istream& operator>>(std::istream &in, Complex &c) {
    std::cout << "Enter real part: ";
    in >> c.real;
    std::cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}