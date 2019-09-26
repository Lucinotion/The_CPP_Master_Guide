/*
    LIBRARIES
*/
// You can use <> or "" with the std headers, the reason why <> work only with them is because they are included inside the compiler's include folder, which is accessed with <>

// C
#include <cstdio>    //c standar input output library (scanf(), printf(), puts(), gets(), fputs(), fgets(), fprintf(), fscanf(), getchar())
#include <cstdlib>   //c standard library (atoi(string a int), malloc(), calloc(), free(), exit(), rand(proporciona un numero random), srand(recibe una semilla que indica a rand() dónde comenzar), system(), qsort())
#include <ctime>     //c time library (time());
#include <cmath>     //c math library (sin(), cos(), tan(), ceil(), floor(), fmin(), fmax(), round(), log(), pow(), sqrt(), fabs())
#include <cstring>   //c string library (strlen(), strcmp(), strcpy(), strcat(), strstr(), strchr())
#include <windows.h> //c windows library (hacer ventanas de windows, Sleep() y para cambiar colores)

// C++
#include <iostream>  //input output stream (cout, cin, ,wcout, wcin)
#include <array>     //array library (requiere de -std=c++11 para funcionar) (.size() .at() .front() .back() .empty())
#include <vector>    //vector library (at() insert() pop_back() push_back() clear() resize())
#include <string>    //string library ()
#include <memory>    //smart pointers library  ptr_unique,  ptr_shared, ptr_weak
#include <iterator>  //iterators library (.begin() y .end())
#include <algorithm> //sorting algorithm library (sort())

// CUSTOM
#include "mathematical.hpp" // Our libraries header files have to be included using " " which is relative to this file location, you can also include the full path to the header

/*
    USING
*/
using namespace std;          // Allows you to skip the std:: for EVERYTHING, it is considered bad praxis
using MathFuncs::MyMathFuncs; // Allows you to skip the MathFuncs:: only for MyMathFuncs, this is ok because it only affects one class

int main()
{
    cout << "PI * The answer to life, the universe and everything else" << MyMathFuncs::Multiply(3.14159265359, 42.0) << endl;
    cout << "PI / The answer to life, the universe and everything else" << MyMathFuncs::Divide(3.14159265359, 42.0) << std::endl;
    cout << MathFuncs::PI << std::endl;
    // Because of the using namespace, MathFuncs:: is optional

    return 0;
}
