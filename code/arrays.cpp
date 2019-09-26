#include <iostream>
#include <array>
#include <vector>

int main()
{
    /*
        ARRAYS
    */
    // C arrays are pointers
    //In unidimensional arrays the name of the array returns the first memory address, it can be incremmented with +, the you can access its value with * 	EX arrVar returns the first direction, #045345, BUT *arrVar returns the value stored in #045345, 'a' for example
    //In bidimensionales arrays you can access the first memory address with arrName[0], if you incremment de index you incremment the memory address and with * you can access its value	EX arrVar[0] returns the first direction, #045345, BUT *arrVar[0] returns the value stored in #045345, 'a' for example
    // C Array declaration
    int cArray[6];      // This array can store up to 5 elements of type int, it is initialiized empty
    int cBiArray[2][3]; // This is a 2 rows by 3 cols array
    // Array inicialization
    int cInitializedArray[6] = {1, 2, 3, 4, 5, 6};
    int cInitializedBiArray[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // Array auto size
    int cAutoArray[] = {1, 2, 3, 4, 5};
    int cAutoBiArray[][3] = {{1, 2, 3}, {4, 5, 6}};

    // New C++17 inicialization
    int newAssignArray[6]{1, 2, 3, 4, 5, 6};
    int newAssignBiArray[2][3]{{1, 2, 3}, {4, 5, 6}};
    // New C++17 auto size
    int newAssignAutoArray[]{1, 2, 3, 4, 5, 6};          // In this case ommiting the array size helps preventing errors, sinze the size is calculated by the compiler
    int newAssignAutoBiArray[][3]{{1, 2, 3}, {4, 5, 6}}; // You can only ommit the first size in multidimensional arrays
    // New C++17 zero inicialization
    int newAssignZeroArray[10]{}; // All elements are initialized to 0
    int newAssignZeroBiArray[10][10]{};

    /*
    STD::ARRAY
    */
    // std::array declaration
    std::array<int, 6> stdArray;
    std::array<std::array<int, 3>, 2> stdBiArray; // 2*3 array
    // std::array inicialization
    std::array<int, 6> stdInitializedArray{1, 2, 3, 4, 5, 6};
    // std::array zero inicialization
    std::array<int, 10> stdZeroArray{};

    /*
    STD::VECTOR
    */
    // std::vector declaration
    std::vector<int> stdVector;
    // std::vector inicialization with values
    std::vector<int> stdInitializedVector{1, 2, 3, 4, 5, 6};
    // std::vector inicialization size
    std::vector<int> stdSizedVector(100, 0); // (size, values)
    // std::vector zero inicialization
    std::vector<int> stdZeroVector{};

    //-----------------------------------------------------------------

    // ASSIGN VALUES TO ELEMENTS OF THE ARRAY
    cArray[0] = 23;
    cBiArray[0][1] = 5;
    // New way, less error prone
    cArray[1] = {42};

    // ASSIGN VALUES TO ELEMENTS OF THE STD::ARRAY
    stdArray[0] = 23;
    stdBiArray[0][1] = 5;
    // New way, less error prone
    stdArray[0] = {23};
    // Fill
    stdArray.fill(5);

    // ASSIGN VALUES TO ELEMENTS OF THE STD::VECTOR
    stdInitializedVector[2] = 3;
    // New way, less error prone
    stdInitializedVector[2] = {3};
    // Insertion
    stdInitializedVector.push_back(5);                            // Inserts the element at the end
    stdInitializedVector.insert(stdInitializedVector.begin(), 0); // Inserts the element at the beggining, you can do .begin()+5 to insert in the fifth position
    // Deletion
    stdInitializedVector.pop_back();                                                                // Removes the element at the end
    stdInitializedVector.erase(stdInitializedVector.begin() + 3, stdInitializedVector.begin() + 4); // Removes the elements from [3] (inclusive) to [4] (exclusive)
    // Clear, removes all elements.
    stdInitializedVector.clear();

    //-----------------------------------------------------------------

    // SIZE OF THE ARRAY
    int arrSize = sizeof(cArray) / sizeof(cArray[0]); // Old method
    size_t newArrSize = std::size(cArray);            // New method

    // SIZE OF THE STD::ARRAY
    stdArray.size();

    // SIZE OF THE STD::VECTOR
    stdInitializedVector.size();

    return 0;
}