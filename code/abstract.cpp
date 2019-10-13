#include <iostream>

/*
    ABSTRACT CLASS / PURELY VIRTUAL CLASS
*/
// This classes contain at least one virtual method (a method with no implementation).
// This means that you cannot make a object out of this class.
// But other classes can inherit from this class, and you can make a pointer from this class and then point it to a child that inherits it.

// BOXING
// Boxing is a concept introduced by polymorphism.
// This means that you can have methods that only operate with the base class so that:
// You can cast the child into the base class (boxing), operate with them in the functions that only accept base objects, and then cast them back (unboxing).

class AbstractClass
{
protected:

    int baseInt = 5;

public:

    // By doing this now the class is abstract, this is called a purely virtual or abstract member.
    virtual void DoSomething() = 0;

    // Abstract classes can contain non-virtual or non-purely-virtual members.
    void SayName() const
    {
        std::cout << "Hello" << std::endl;
    }

    // The destructor must be set to virtual so that it can be overriden by the child clases
    virtual ~AbstractClass() = default;
};

class FirstDerivedClass : public AbstractClass
{
public:

    void DoSomething() override
    {
        baseInt++;
    }

    void Extra()
    {
        std::cout << "This is first" << std::endl;
    }
};

class SecondDerivedClass : public AbstractClass
{
public:

    void DoSomething() override
    {
        baseInt--;
    }

    void Extra()
    {
        std::cout << "This is second" << std::endl;
    }
};

int main()
{
    // Pointer of type base class that points to an object of type child class.
    FirstDerivedClass * first = new FirstDerivedClass();
    SecondDerivedClass * second = new SecondDerivedClass();
    AbstractClass * pointer{};

    // POLYMORPHISM EXAMPLE
    second->Extra();

    pointer = second;

    pointer->DoSomething();

    first->Extra();

    pointer = first;

    pointer->DoSomething();

    // BOXING
    // dynamic_cast must be used in pointers to cast a pointer into it's parent class or child class when one of them has any virtual members.
    pointer = dynamic_cast<AbstractClass *>(first);

    pointer->SayName();

    // UNBOXING
    first = dynamic_cast<FirstDerivedClass *>(pointer);

    first->DoSomething();

    first->Extra();

    return 0;
}