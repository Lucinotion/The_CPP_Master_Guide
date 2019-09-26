/*
    HEADER FILE
*/
// Header file for mathematical.cpp
// Header files constain all de declarations for each function. They also contain documentation for each function

// By doing this we check that this hasn't been included before, you could also use the preprocess pragma, but not all compilers support it
#ifndef MATHEMATICAL_H
#define MATHEMATICAL_H

// Start of namespace mathfunctions
namespace MathFuncs
{

extern const double PI; // External variable declaration

class MyMathFuncs
{
public:
    static double Add(double a, double b); // Returns a + b

    static double Subtract(double a, double b); // Returns a - b

    static double Multiply(double a, double b); // Returns a * b

    static double Divide(double a, double b); // Returns a / b
};

} // End of namespace MathFuncs

#endif
