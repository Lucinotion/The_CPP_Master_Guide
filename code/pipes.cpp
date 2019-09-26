#include <iostream>
#include <string>

/*
    PIPES
*/
// Pipes are a feature from command lines that allows to redirect the output of a program to the input of other program
// This program will output what other program outputs
// The pipe syntax is: outputProgram | inputProgram
// You can try it with: helloworld | pipes

int main(int argc, char **argv)
{
    std::string str{};

    std::getline(std::cin, str);

    std::cout << "I recieved : " << str << std::endl;

    return 0;
}