#include <iostream>

/* 
    INTERFACE / PURELY ABSTRACT CLASS
*/
// An interface is a type of class that only contains purely virtual members.
// This means that every class that inherits from it must implement each of it's members.
// Like abstract classes, they cannot be made into an object, but you can make pointers to them.

class Ibase // By convention, all interface names start with a capital I and all the methods are protected or public.
{
public:
    // The destructor must be set to virtual so that it can be overriden by the child clases
    virtual ~Ibase() = default;

protected:
    // All members must be purely virtual to make a Interface
    virtual void execute() const = 0;
    virtual void to_string() const = 0;
    virtual void get_name() const = 0;
};

class InplementsIbase : public Ibase
{
    int a{1};

public:
    void execute() const override
    {
        std::cout << "sound of execution" << std::endl;
    }

    void to_string() const override
    {
        std::cout << "the string strings" << std::endl;
    }

    void get_name() const override
    {
        std::cout << "my name is Jeff" << std::endl;
    }

    ~InplementsIbase()
    {
        a = 0;
    }
};

int main()
{
    Ibase * basepointer = new InplementsIbase();

    // dynamic_cast must be used in pointers to cast a pointer into it's parent class or child class when one of them has any virtual members.
    dynamic_cast<InplementsIbase *>(basepointer)->to_string();

    return 0;
}