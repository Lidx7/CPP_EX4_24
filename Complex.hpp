#pragma once
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0);

    // Copy constructor
    Complex(const Complex &other);

    // Getter for real part
    double getReal() const;

    // Getter for imaginary part
    double getImag() const;

    // Addition
    Complex operator+(const Complex &other) const;

    // Subtraction
    Complex operator-(const Complex &other) const;

    // Multiplication
    Complex operator*(const Complex &other) const;

    // Division
    Complex operator/(const Complex &other) const;

    // Overload the stream insertion operator for output
    friend std::ostream& operator<<(std::ostream &out, const Complex &c);

    // Overload the stream extraction operator for input
    friend std::istream& operator>>(std::istream &in, Complex &c);
};

#endif // COMPLEX_HPP