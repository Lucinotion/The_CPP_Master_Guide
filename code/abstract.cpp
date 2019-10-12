#include <iostream>


/*
    ABSTRACT CLASS / PURELY VIRTUAL CLASS
*/
// This classes contain at least one virtual method (a method with no implementation)
// This means that you cannot make a object out of this class
// But other classes can inherit from this class, and you can make a pointer from this class and then point it to a child that inherits it.

// BOXING
// Boxing is a concept introduced by polymorphism
// This means that you can have methods that only operate with the base class so that:
// You can cast the child into the base class (boxing), operate with them in the functions that only accept base objects, and then cast them back (unboxing).

class AbstractClass
{
protected:

    int baseInt = 5;

public:

    virtual void DoSomething() = 0; // By doing this now the class is abstract

    void SayName() const // Abstract classes can contain any other non-virtual or non-purely-virtual members
    {
        std::cout << "Hello" << std::endl;
    }

    virtual ~AbstractClass() = default; // The destructor must be set to virtual so that it can be overriden by the child clases
};

class FirstDerivedClass : public AbstractClass
{
public:

    void DoSomething() override
    {
        baseInt++;
    }
};

class SecondDerivedClass : public AbstractClass
{
public:

    void DoSomething() override
    {
        baseInt--;
    }
};

int main()
{
    AbstractClass * pointer = new SecondDerivedClass();

    pointer->DoSomething();

    // dynamic_cast must be used in pointers to cast a pointer into it's parent class or child class when one of them has any virtual members.
    dynamic_cast<FirstDerivedClass *>(pointer);

    pointer->DoSomething();

    return 0;
}