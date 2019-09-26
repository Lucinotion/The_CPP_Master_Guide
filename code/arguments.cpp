#include <iostream>

// argc is the ARGument Count, an integer
// argv is the ARGument Values, a array of pointers of type char, the number of values is equal to argc + 1 since it saves the name of the program in argv[0]
int main(int argc, char **argv)
{
    if (argc) // When arguments are included argc > 0
    {
        std::cout << "You have added " << std::endl;
        for (int i{}; i < argc; i++)
        {
            std::cout << argv[i + 1] << std::endl;
        }
    }
    else // When no arguments are included argc is 0, unless the user included extra syntax in the program command like pipes | or redirectors >>
    {
        std::cout << "You haven't added any arguments" << std::endl;
    }
    return 0;
}