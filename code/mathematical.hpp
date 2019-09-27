/**
 * @file mathematical.hpp
 * @author Luciano Manuel Álvarez Candal (lucinotion.com)
 * @brief 
 * @version 0.1
 * @date 2019-09-27
 * 
 * @copyright Copyright Lucinotion(c) 2019
 * 
 */

/*
    HEADER FILE
*/
// Header file for mathematical.cpp
// Header files constain all de declarations for each function. They also contain documentation for each function

// By doing this we check that this hasn't been included before, you could also use the preprocess pragma, but not all compilers support it
#ifndef MATHEMATICAL_H
#define MATHEMATICAL_H

namespace MathFuncs
{

extern const double PI; // External variable declaration

class MyMathFuncs
{
public:
    
    // DOCUMENTATION for functions in c++ is written like a block comment but you need to put an extra * at the start.
    // This is used by Doxygen http://www.doxygen.nl/index.html later to generate documentation
    
    /**
     * @brief <b> Returns the sum of two arguments. </b>
     * @details This function takes a `double` and another `double` and *ADDS* them together.
     * 
     * @param a double
     * @param b double
     * @return double
     * 
     * @b Example
     * @code
     * Add(2.4, 3.7);
     * @endcode
     */
    static double Add(double a, double b);

    /**
     * @brief <b> Returns the substraction of two arguments. </b>
     * @details This function takes a `double` and another `double` and *SUBSTRACTS* them together.
     * 
     * @param a double
     * @param b double
     * @return double
     * 
     * @b Example
     * @code
     * Subtract(2.4, 3.7);
     * @endcode
     */
    static double Subtract(double a, double b);

    /**
     * @brief <b> Returns the multiplication of two arguments. </b>
     * @details This function takes a `double` and another `double` and *MULTIPLIES* them.
     * 
     * @param a double
     * @param b double
     * @return double
     * 
     * @b Example
     * @code
     * Multiply(2.4, 3.7);
     * @endcode
     */
    static double Multiply(double a, double b);

    /**
     * @brief <b> Returns the division of the first argument by the other. </b>
     * @details This function takes a `double` and another `double` and *DIVIDES* the first (`a`) between the second argument (`b`).
     * 
     * @param a double
     * @param b double
     * @return double
     * 
     * @b Example
     * @code
     * Divide(2.4, 3.7);
     * @endcode
     */
    static double Divide(double a, double b);
};

} // End of namespace MathFuncs

#endif