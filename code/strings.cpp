#include <iostream>
#include <locale.h>
#include <string>

int main()
{
    setlocale(LC_ALL, "spanish"); // Allows the display of extended ASCII in the command line

    /*
        CHAR ARRAYS
    */
    // C style string
    char cString1[5] = {'h', 'e', 'l', 'l', 'o'}; // char *var is the same as char var[], in both cases var is a pointer to the first letter
    char cString2[6] = {"hello"};
    char cString3[] = {"This is a string literal whose size is set by the compiler"}; // A string literal is const char []
    char *cString4;                                                                   // Pointer to string

    /*
        STRINGS
    */
    // C++ style strings
    std::string cppString1{"This is a better string, from the string header inside the standar library"};
    std::string cppString2 = "You can also use the assignation inicialization";
    std::string cppString3("You can also use the functional inicialization");
    std::string *cppString4 = new std::string("Or you can use a pointer like so");

    /*
        RAW STRINGS
    */
    std::string rawString{R"(You don't need scape sequences here \ / ' ? )"};                 // The R denotates that this is a Raw string The () are mandatory
    std::string foolProofRawString{R"~(You don't need scape sequences here )( " \ / ' ? )~"}; // The ~ is the delimiter, you can use almost any character for it and it lets you put " and () inside without breaking the string

    /*
        Escape sequences

        \n Newline
        \t Horizontal tab
        \v Vertical tab
        \b Backspace
        \r Carriage return
        \f Form feed
        \a Alert/bell
        \0 null character, by default all strings contain one at the end or they will contain garbage data after the last character.
        \\ backslash
        \' single quote
        \" double quote
    */

    // Show and get C++ strings
    std::cout << "Write some text: ";

    std::getline(std::cin, cppString1); // Saves string to variable

    std::cout << "You wrote: " << cppString1 << std::endl;

    // Show and get C strings
    std::cout << "Write some text: ";

    std::cin.getline(cString1, std::size(cString1), '\n'); // Takes the input until \n, then saves the string to a variable (varialbe, lenght, breakCharacter), the las argument is optional.

    std::cout << "You wrote: " << cString1 << std::endl;

    // Show and get C strings pointer version
    fputs("Write some text: ", stdout);

    fgets(cString4, 10, stdin);

    fputs(cString4, stdout);

    /*
        STRING OPERATIONS
    */
    // DEFINE
    std::string newString{};
    std::string part_literal("La vida es una lenteja O la tomas o la dejas", 22); // "La vida es una lenteja"
    std::string sleeping(6, 'z');                                                 // 6 times z
    std::string substring{part_literal, 15, 22};                                  // This takes a sub string from part_literal form position 15(exclusive) to 22(inclusive)

    // ASSIGN
    newString = "This is the content of the string";

    // STD::STRING TO CHAR ARRAY
    const char *cConstCharArray[] = {newString.c_str()};
    char *cCharArray[] = {newString.data()};

    // CHAR ARRAY TO STD::STRING
    // std::string(*cCharArray);

    // GET LENGHT
    newString.length();

    // CONCATENATION
    newString = {"I am " + sleeping + " very sleepy... I haven't sleept in " + std::to_string(14) + " hours!"};

    // SUBSTRING
    substring = newString.substr(5, 6); // (beginning AKA offset, count)

    // COMPARE
    auto same{substring == sleeping};
    same = substring.compare(sleeping);
    same = substring.compare(2, 3, sleeping); // (beginning AKA offset, count, stringToCompare)

    // FIND
    auto wordIndex{newString.find("sleept")};

    // INSERT
    newString.insert(newString.length(), "5555555"); // (offset, stringToInsert)

    // REPLACE
    newString.replace(0, 5, "Wow "); // (offset, count, string)

    // ERASE
    newString.erase(0, 5); // (offset, count)

    // TO INT
    int number{std::stoi(newString.substr(newString.length() - 7, 7))}; // stoi(string)

    return 0;
}