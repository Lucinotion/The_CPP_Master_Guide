/* 
    PREPROCESSES
*/
// Preproceses are a series of replacing operations that are executed only at compile time
// They add the source code from libraries into your code, and they replace expressions by other expressions
// They can also be used to choose different pieces of code to be included or excluded from compilation by the use of conditional preprocesses

//INCLUDE "file" or <header>
//DEFINE variable value or macroname() (operation)
//UNDEF variable, undefines a specific variable, you need to undefine before you can redefine
//IFDEF variable, Executes until the next endif when the value is defined
//IFNDEF variable, Executes until the next endif when the value is not defined
//IF condition, Executes until the next endif when the condition is met
//ELIF condition, Executes when the condition is met and the previous IF condition is not
//ELSE condition, Executes until the next endif when the previous IF condition is not met
//ENDIF, end of if body
//ERROR text, Displays error text
//LINE number "text" ?

#include <iostream> // Inlcudes the header inside the source file

#define DEFCON 1                          // Defines a macro constant variable
#define POW2(N) N *N                      // Defines a macro function
#define STR(S) #S                         // Defines a macro function, placing # returns whatever you put into a string
#define JOIN(A, B) A##B                   // Defines a macro, with ## two values are concatenated
#define FOR(X, Y) for (X = 0; X < Y; X++) // Defines a macro function that increases A until it is the same as B

#ifndef DEFCON
#error DEFCON NOT DEFINED!
#endif

#ifdef DEFCON
#if DEFCON > 3
#undef DEFCON
#define DEFCON 4
#elif DEFCON < 3
#undef DEFCON
#define DEFCON 5
#else
#undef DEFCON
#define DEFCON 2
#endif
#endif

int main()
{
    auto x{3.14159265359L};
    auto y{"Bazinga!"};
    auto z{16};
    auto xy{"WTF"};

    std::cout << POW2(x) << std::endl;
    std::cout << JOIN(x, y) << std::endl;
    std::cout << STR(La vida es una lenteja o la tomas o la dejas) << std::endl;

    FOR(x, z)
    {
        std::cout << x << std::endl;
    }

    std::cout.flush();

    return 0;
}