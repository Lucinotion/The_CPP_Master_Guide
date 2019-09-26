#include <iostream>

int main()
{
    /*
        REFERENCES
    */
    // A reference is an alias for a variable
    // They MUST BE INITIALIZED with the variable name they referenciate
    // They CANNOT CHANGE the variable they are referencing/aliasing after inicialization
    int regularInt{5};

    auto &refInt{regularInt}; //This is a reference to the variable created before

    refInt = 10; // Changing the value of the refInf alias will actually change the value of regularInt

    std::cout << regularInt << std::endl;

    return 0;
}