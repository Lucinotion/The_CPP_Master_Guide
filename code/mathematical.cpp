/*
    LIBRARY
*/
// This contains the implementation for everything in the mathematical.hpp
// You shoud include this file in the build task every time you use the header
// compile with: cl /c /EHsc MathFuncsLib.cpp
// post-build command: lib MathFuncsLib.obj

#include "mathematical.hpp" // Don't forget to include the header file for the class

#include <stdexcept>

using namespace std;

namespace MathFuncs
{

const double PI = 3.14159265; // External global variable definition

double MyMathFuncs::Add(double a, double b)
{
    return a + b;
}

double MyMathFuncs::Subtract(double a, double b)
{
    return a - b;
}

double MyMathFuncs::Multiply(double a, double b)
{
    return a * b;
}

double MyMathFuncs::Divide(double a, double b)
{
    return a / b;
}

} // End of namespace MathFuncs
