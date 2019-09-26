#include <iostream>
#include <vector>
#include <memory>

long longRetFunction(short shortInteger, int integer)
{
    return static_cast<long>(shortInteger + integer);
}

int main()
{
    /*
		POINTERS
	*/
    // A pointer contains the memory address to other specific type of data as its value

    // UNIDIMENSIONAL
    int *pUninitialized;                       // Pointer to a integer, or a unidimensional array, points at garbage since it hasn't been initializated
    int *pToNull{nullptr};                     // Pointer to a integer, initialized to null, DO THIS ALLWAYS. This is the same as leaving the {} empty
    int *pInt{new int{5}};                     // New allocates memory for the new type and returns the address, you can also use new int(5) instead
    int *pIntArray{new int[5]{1, 2, 3, 4, 5}}; // A pointer to the first element of an array, same as before, but with more initialized values
    auto pAuto{new double{.56213123}};         // The auto keyword allows you to forget about writing the entire pointer syntax
    const char *pString{"This pointer only stores the address of the first element of the string literal, but you can access the hole string by increasing *(p+i) or p[i]\0"};

    // BIDIMENSIONAL
    // Faked
    int **pPInt{new int *[3] {}};    // Pointer to a pointer to a value, or a bidimensional array, initialized to null, is the same as int *pPInt[], the number [3] is the number of rows
    auto pPAutoInt{new int *[3] {}}; // Auto example of the previous
    // Real
    double(*pPDouble)[4]{new double[5][4]{}}; // A pointer to a bidimensional array of type double, Only the 5, the one that indicates the amount of rows the array will have, can be set at runtime
    auto pPAutoDouble{new double[5][4]{}};    // With the auto you don't have to remember the other weird syntax

    // TO FUNCTION
    // Definition
    long (*pFunction)(short, int);
    long (*pInitializedFunction)(short, int){longRetFunction}; // With inicialization

    //Assignation
    pFunction = longRetFunction; // Store longRetFunction in the pointer

    //Usage
    std::cout << pFunction(255, 12345) << std::endl; // Call the function

    /*
		DEREFERENCE and ADDRESS
	*/
    // The indirection or dereference operator, *(address), returns the value in that address
    // The address operator, &(value), returns the address of the value

    std::cout << pInt << '\n';     // This returns the content of pInt, which, because it's a pointer, contains the memory address of a value of type int.
    std::cout << *pInt << '\n';    // This returns the value stored in the address contained inside pInt, which is of type int
    std::cout << &pInt << '\n';    // This returns the memory address of pInt.
    std::cout << *(&pInt) << '\n'; // This returns the content of pInt, a memory address. It's the same as typing pInt alone.

    /*
        ACCESSING MEMBERS
    */
    auto pVec{new std::vector<int>{}};

    pVec->push_back(50); // Same as (*pVec).push_back(50)

    /*
		FREEING MEMORY
	*/

    delete pInt; // For values
    pInt = nullptr;

    delete[] pIntArray; // For arrays
    pIntArray = nullptr;

    /* 
        SMART POINTERS
    */
    // DECLARATION
    // Empty
    std::unique_ptr<int> spUnique(nullptr); // There can only be one unique_ptr pointing at a specific memory address
    std::shared_ptr<int> spShared(nullptr); // These pointers can share the same memory address between them, memory gets released automaticly when all of them stop using a specific adress
    std::weak_ptr<int> spWeak;              // These pointers are used very rarely, they require a shared_ptr to work and wil point at a shared address, they can actualy point to null if the memory is released.
    // Auto delcaration
    auto spAutoShared{std::make_shared<int>(42)}; // Makes a shared pointer to int and fills it with a new int

    // ASSIGN VALUES
    spShared = std::make_shared<int>(23);     // Creates a new int and assigns it to the empty pointer
    spAutoShared = std::make_shared<int>(15); // Creates a new int and assigns it to the full pointer, the other values is freed

    auto spVector{std::make_shared<std::vector<int>>(10, 0)};
    (*spVector)[0] = 1;

    // CHANGE REFERENCE
    std::shared_ptr<std::vector<int>> spOtherVector(nullptr);
    spOtherVector = spVector;

    // CALL MEMBERS
    spVector->push_back(10);

    /* 
        ARRAYLIKE POINTERS
    */
    // Generally allocate only a single unidimensional array of rows * columns elements and then you can turn it into a bidimensional array using the formula (columns * i + j) to get the unidimensional index.

    // Unidimensional
    char controlChar{'a'};
    for (int i{}; controlChar != '\0'; i++)
    {
        std::cout << pString[i];
        controlChar = pString[i];
        // *(pString + i) OMFG Way

        std::cout.flush();
    }
    std::cout << std::endl;

    std::cout << pString << std::endl; // <-- In the case of string literals you can print them by just doing this

    // Bidimensional
    for (int i{}, g{1}; i < 3; i++) // Initialize
    {
        pPInt[i] = new int{};
        // You need to allocate memory for the first element of each row
        // *(pPInt + i) = new int{}; OMFG way
        for (int j{}; j < 3; j++, g++)
        {
            pPInt[i][j] = g;
            // You then need to assign values for each element
            // *(*(pPInt + i) + j) = g; OMFG way
        }
    }

    for (int i{}; i < 3; i++) // Show array
    {
        std::cout << std::endl;
        for (int j{}; j < 3; j++)
        {
            std::cout << pPInt[i][j];
            std::cout.flush();
        }
    }

    return 0;
}