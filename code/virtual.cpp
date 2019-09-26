#include <iostream>

/*
    VIRTUAL MEMBERS
*/
class baseClass
{
public:
    // Virtual function. A virtual function is supposed to be overriden on the derived class.
    virtual void virtualized()
    {
        std::cout << "I am the base class" << std::endl;
    }
    void hidden()
    {
        std::cout << "I am the base class" << std::endl;
    }
};

class derivedClass : public baseClass
{
public:
    // Overriden virtual function.
    void virtualized() override
    {
        std::cout << "I am the derived class" << std::endl;
    }
    // Function hiding. This is the oposite of virtual, since the function called will be the one from the base when using a ponter to base.
    void hidden()
    {
        std::cout << "I am the derived class" << std::endl;
    }
};

/*
    FINAL OVERRIDE
*/
class subDerivedClass : public derivedClass
{
    // FINAL makes the function so it can't be overriden by new derived classes.
    void virtualized() final
    {
        std::cout << "I am the subderived class" << std::endl;
    }
};

int main()
{
    baseClass *basePointer{new derivedClass()};
    derivedClass *derivedPointer{new derivedClass()};
    baseClass *subDerivedPointer{new subDerivedClass()};

    basePointer->virtualized(); // Since the function is virtual, it is overriden in the derived class. So the funtion called is the one in the derived.
    basePointer->hidden();      // Because the function is not virtual, the base funtion is called instead

    derivedPointer->hidden(); // In this case, since the pointer is not of base class, the function is no longer hidden and can be acessed.
    subDerivedPointer->virtualized();

    return 0;
}