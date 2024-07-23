#pragma once
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0);

    Complex(const Complex &other);

    double getReal() const;

    double getImag() const;

    Complex operator+(const Complex &other) const;

    Complex operator-(const Complex &other) const;

    Complex operator*(const Complex &other) const;

    Complex operator/(const Complex &other) const;

    friend std::ostream& operator<<(std::ostream &out, const Complex &c);

    friend std::istream& operator>>(std::istream &in, Complex &c);
};

#endif // COMPLEX_HPP