#include <iostream>
#include <cstring>

/*
    LOOPS
*/

int main()
{
    double rainfall[12]{1.1, 2.8, 3.4, 3.7, 2.1, 2.3, 1.8, 0.0, 0.3, 0.9, 0.7, 0.5};
    double copy[12]{};
    int fibonacci{};
    int prev{1};
    int prevprev{};
    int i{};
    unsigned long long factorial{1ULL};
    char msg[8]{};

    /*
        Loop control statements

        continue; ingnores the rest of the code and goes directly to the condition
        break; breaks out of the loop or switch
    */

    // FOR
    for (size_t i{}; i < 12; ++i) // for(inicialization; condition; endofiteration) In a 32bit program size_t holds 32bits. In a 64bit, it holds 64bits. It's commonly used for array iterators
    {
        copy[i] = rainfall[i];
    }

    // FOREACH
    for (auto &x : copy) // for(controlvariable, collection), it is recommended to use auto for the control variable declaration, also, the control variable has a COPY of the value in the array, not a reference, you can use auto& so that it is a REFERENCE
    {
        std::cout << x << std::endl;
    }

    // WHILE
    while (fibonacci < 317811) // while(condition) while the condition is true, the body executes.
    {
        // fibonacci
        fibonacci = prev + prevprev;
        prevprev = prev;
        prev = fibonacci;

        std::cout << fibonacci << std::endl;
    }

    // DO WHILE
    do
    {
        // factorial
        factorial *= ++i;

        std::cout << factorial << std::endl;
    } while (i < 20); // do{}while(condition); Executes its body at least one time, and it keeps executing while the condition is true

    // GOTO (gotos have been deprecated for many years now)
start: // This is a tag you can goto

    std::cout << "Write \'hello\':" << std::endl;
    std::cin.getline(msg, sizeof(msg));

    if (strcmp(msg, "hello") != 0)
    {
        goto start;
    }
    else
    {
        goto end;
    }

end: // Another tag

    return 0;
}
