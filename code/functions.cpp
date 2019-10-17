#include <iostream>
#include <iomanip>
#include <string>
#include <cstdarg> // Allows oyou to use ... for giving functions a not limited number of arguments

/*
    FUNCTIONS
*/
    // WITH RETURN VALUES
double power(double x, int n) // This function has a return type double, and takes arguments x and n
{
    double result{1.0};

    if (n >= 0)
    {
        for (int i{1}; i <= n; ++i)
        {
            result *= x;
        }
    }
    else
    {
        for (int i{1}; i <= -n; ++i)
        {
            result /= x;
        }
    }

    return result;
}

    // WITH CONST RETURN
const int factorial(int number) // This way you cannot do factorial(5)++, but you can assign the value to a non const variable.
{
    int res{1};

    for(int i{}; i < number; ++i)
    {
        res *= i;
    }

    return res;
}

    // WITHOUT RETURN VALUES
void saySomething(const std::string s) // Functions of type void don't return anything.
{
    std::cout << s << std::endl;

    return; // Even if void functions don't return any value, you can still use return to exit the function.
}

    // WITH DEDUCTED OUTPUT
auto larger(int a, int b)
{
    return a > b ? a : b;
}

    // WITH OUTPUT PARAMETERS
void increaseByReference(int &n) // Value passed by reference
{
    n++;
}
void increaseByPointer(int *n) // Value passed by pointer
{
    (*n) += 1;
}

    // WITH UNLIMITED AMOUNT OF ARGUMENTS
int addAllArguments(int n_args, ...)
{
    va_list list; // Make list of arguments
    va_start(list, n_args); // Start list of arguments

    int res{};

    for(size_t i = 0; i < n_args; ++i)
    {
        res += va_arg(list, int); // Get next argument of list
    }

    va_end(list); // End list

    return res;
}

/*
    FUNCTION TEMPLATES
*/
template <typename T> // T is the type that will be replaced in all T instances.
T bigger(T a, T b)
{
    return a > b ? a : b;
}

    // WITH DEDUCTED OUTPUT
template <class T1, class T2> // The keywords class and typename are equivalent.
auto larger(T1 a, T2 b)
{
    return a > b ? a : b;
}

/*
    INLINE FUNCTIONS
*/
// Inline functions replace treir call by the body of the function, making short fuctions faster to execute
inline int xlarger(int m, int n)
{
    return m > n ? m : n;
}

/*
    NEW FUNCTION SYNTAX
*/
template<typename T1, typename T2>
auto myNewFunction(T1 a,T2 b) -> decltype(a + b) // Declttype declares the return type based on the expression, if already know the return type just use the regular syntax, don't use -> type
{
    return a + b;
}

/*
    DEFINITION AND DECLARATION
*/
// DECLARATIONS
int addOne(int n);     // This is a function declaration, separated from it's implementation/definition
int addOne(int n = 5); // This is the default value for n

// IMPLEMENTATION / DEFINITION
int addOne(int n) // This is addOne's implementation
{
    return n + 1;
}

int main()
{
    int foobar{5};

    // Calculate powers of 8 from -3 to +3
    for (int i{-3}; i <= 3; ++i)
    {
        std::cout << std::setw(10) << power(8.0, i);
    }

    // Say Hi
    saySomething(std::to_string(addOne(5)));

    // increase reference
    increaseByReference(foobar);

    // increase pointer
    increaseByPointer(&foobar);

    int value = 5;
    value = factorial(value);

    addAllArguments(5, 1, 2, 3, 4, 5);

    std::cout << std::endl;
    return 0;
}