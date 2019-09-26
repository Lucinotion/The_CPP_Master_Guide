#include <iostream>
#include <string>

class exampleClass
{
private:
    // Everything after this can only be accessed by the class.

    double GenericDouble;
    std::string GenericString;

public:
    // Everything after this can be accessed anyware.

    const int GenericInt{};     // CONST values are assigned when the object is made and can't be changed.
    mutable bool ready = false; // MUTABLE makes variables modificable even if the object has been created as const
    static int instanceCount;   // STATIC members are independent from objects and they can be accessed without making a instance of the class.

    //  CONSTRUCTORS, called when an object of the class is created, everything after the : will execute before the constructor, this is the only way to assign constant values.
    exampleClass()
    {
        // Default constructor, empty.
        // If no constructor is defined, the compiler creates a default empty constructor
        // You can also use exampleClass() = default; to force the compiler to make a default constructor.
    }
    exampleClass(double d, std::string s)
    {
        // Constructor with arguments.
        GenericDouble = d;
        this->GenericString = s; // The this keyword is a pointer to this object, it can be ommited most of the time except when you need a function that returns the object itself.
    }
    exampleClass(int n) : GenericInt{static_cast<double>(n)}, GenericString{std::to_string(n)}, GenericDouble{static_cast<double>(n)}
    {
        // This constructor has a MEMBER INITIALIZER LIST that sets GenericInt, GenericString and GenericDouble. This is the only way to set const values.
    }
    exampleClass(const exampleClass &exampleclass) // Always use reference_to_const or inifnite loop will happen
    {
        // This is a copy constructor, so that you can do exampleClass newExampleClass {anotherExampleClass}; to make a new class that is a copy of another
        // By default the compiler already has a copy constructor that copies everything by value
    }
    explicit exampleClass(double n)
    {
        // This constructor is explicit, which means that if we have a function that requires a exampleClass object, like examplify(exampleClass a), if we do examplify(23.5) this constructor won't be called and the 23.5 won't be converted into an exampleClass object
        GenericDouble = n;
        GenericString = std::to_string(n);
    }

    // DESTRUCTORS, called when the class object is deleted.
    ~exampleClass()
    {
        // You can also use ~exampleClass() = default; to force the compiler to make a default destructor.
    }

    // MEMBERS
    double Sum() // A member is any function inside a class, also known as methods
    {
        return GenericDouble * GenericInt;
    }

    static void Speak() // STATIC members can be accessed without making an object of the class
    {
        std::cout << "Hello friend!";
    }

    // FRIEND FUNCTION DECLARATION
    friend void IncreaseDouble(exampleClass &ex); // FRIEND functions are functions that can access private and protected members of the class they are decladed in as friend.

    // SETTERS set the value of a variable
    exampleClass *setDouble(int d)
    {
        GenericDouble = d;

        return this;
    }
    exampleClass *setString(std::string s)
    {
        GenericString = s;

        return this;
    }

    // GETTERS get the value of a variable
    double getDouble() const // CONST members are members that can be accessed even from const objects because they don't modify the object
    {
        return GenericDouble;
    }
    bool isReady() const // You should allways make const the members that don't modify the object
    {
        return ready;
    }

    // OPERATORS
    /*
        Binary arithmetic operators +  -  *  /  %
        Unary arithmetic operators +  -
        Bitwise operators ~  &  |  ^  <<  >>
        Logical operators !  &&  ||
        Assignment operator =
        Compound assignment operators +=  -=  *=  /=  %=  &=  |=  ^=  <<=  >>=
        Increment/decrement operators ++  --
        Comparison operators ==  !=  <  >  <=  >=
        Array subscript operator [ ]
        Function call operator ( )
        Conversion-to-type-T operator T
        Address-of and dereferencing operators &  *  ->  ->*
        Comma operator ,
    */
    int operator+(const exampleClass &ex) const // addition operation
    {
        return ex.GenericInt + GenericInt;
    }
    bool operator==(const exampleClass &ex) const // equals operator
    {
        return ex.GenericInt == GenericInt;
    }
    exampleClass *operator[](size_t index) // index operator
    {
        return this;
    }
    operator double() const // conversion to double operator
    {
        return GenericDouble;
    }
};

// NON MEMBER OPERATOR OVERLOAD
inline bool operator<(const int &n, const exampleClass &ex)
{
    return n < ex.getDouble();
}

// FRIEND FUNCTION IMPLEMENTATION
void IncreaseDouble(exampleClass &ex)
{
    ex.GenericDouble++;
}

int main()
{
    exampleClass example(5);                    // Creating an instance, or object, of the class.
    const exampleClass anotherExample(10);      // Creating a constant instance, or object, of the class. Only const member are accesible and only mutable fields can be changed.
    auto otherExample = new exampleClass(10.5); // Creating a pointer and assigning a new instance, or object, of the class to it.

    example.setDouble(5.5);                              // Accessing members of object
    std::cout << otherExample->getDouble() << std::endl; // Accessing members of object with pointer
    std::cout << anotherExample.isReady() << std::endl;  // Accessing const members of const object
    std::cout << example + anotherExample << std::endl;  // Using a overloaded operator
    exampleClass::Speak();                               // Calling a static member
    IncreaseDouble(example);

    return 0;
}