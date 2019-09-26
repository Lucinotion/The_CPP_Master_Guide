#include <iostream>
#include <iomanip>
#include <string>

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

// DECLARATIONS
int addOne(int n);     // This is a function declaration, separated from it's implementation/definition
int addOne(int n = 5); // This is the default value for n

/*
    FUNCTION TEMPLATES
*/
template <typename T> // T is the type that will be replaced in all T instances
T bigger(T a, T b)
{
    return a > b ? a : b;
}
// WITH DEDUCTED OUTPUT
template <typename T1, typename T2>
auto larger(T1 a, T2 b)
{
    return a > b ? a : b;
}

/*
    INLINE FUNCTIONS
*/
inline int larger(int m, int n) // Inline functions replace treir call by the body of the function, making short fuctions faster to execute
{
    return m > n ? m : n;
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

    std::cout << std::endl;
    return 0;
}

// IMPLEMENTATION/DEFINITION
int addOne(int n) // This is addOne's implementation
{
    return n + 1;
}
