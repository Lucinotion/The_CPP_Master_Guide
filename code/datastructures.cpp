#include <iostream>
#include <bitset>
#include <string>

int main()
{
    /*
        DATA STRUCTURES
    */
    // ENUMS
    // Enums contain a series of values represented as an integer.
    enum class day // New style, using class, less error prone when casting.
    {
        Monday,
        Tuesday,
        Wendsday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };

    enum color // Old style, more error prone when casting.
    {
        Blue,
        Red,
        White,
        Brown,
        Green
    };

    enum symbols // You can initialize the enums values like so, this way they are no longer ints from 0 to elements-1.
    {
        Comma = ',',
        Dot = '.',
        Exclamation = '!',
        questionMark = '?'
    };

    enum // Static enum, doesn't have a type
    {
        LOADING,
        RUNNING,
        FINISHED
    } static;

    // STRUCTS
    // Strucs in C++ are like classes, but everything is public by default.
    struct duck
    {
        const char *name; // pointer to string literal (const char[])
        int age;

        duck(const char Name[10], int Age) : age(Age) // : age(Age) assings Age to the age varialbe before executing anything else
        {
            name = Name; // assign the pointer the memory direction. Since Name is a string literal (const char[]), Name returns the memory direction of the first letter.
        }

        void talk()
        {
            std::cout << "cuack" << std::endl;
        }
    };

    typedef struct cat // This is old C style, do NOT use.
    {
        char name[25];
        int age;
    } cat; // Using typedef to make it easier to define, instead of 'struct cat varname' you would do 'cat varname'.

    // UNIONS
    // All values inside a union share the same memory direction, so they will overlap 
    union font {
        short data;
        struct
        {
            char fontSize;
            char fontWeight;
        } partitions;
    };

    union entire4Bytes {
        int data;
        struct
        {
            char first;
            char second;
            char third;
            char forth;
        } parts;
    };

    union entire8Bytes {
        uint64_t data;
        uint8_t values[8];
    };

    //____________________________________________________________________

    // INITIALIZATION OF ENUMS
    color choosedColor = Green;
    day choosedDay = day::Monday; // When using enum class you MUST use ::
    symbols choosenSymbol = Dot;

    //____________________________________________________________________

    // INICIALIZATION OF STRUCTS
    cat newCat{"Felix", 7};     // This struct uses the standar constructor
    duck aDuck("DuckDasy", 10); // This one uses the provided constructor

    duck *newDuck;
    newDuck = new duck("DuckLord", 50);

    newDuck->age = 30;
    newDuck->name = "DuckDonald";
    newDuck->talk();

    delete newDuck;

    newDuck = &aDuck;

    //____________________________________________________________________

    // INICIALIZATION OF UNIONS

    union font newFont;
    newFont.data = 0b0000000000000000;
    newFont.partitions.fontSize = 0b11111111;
    newFont.partitions.fontWeight = 0b10101010;

    std::bitset<16> *x;
    x = new std::bitset<16>(newFont.data);

    std::cout << *x << '\n';

    union entire4Bytes new4Bytes;
    new4Bytes.data = 0;
    new4Bytes.parts.forth = 0b00110011;
    new4Bytes.parts.first = 0b00101010;

    std::bitset<32> *y;
    y = new std::bitset<32>(new4Bytes.data);

    std::cout << *y << '\n';

    return 0;
}