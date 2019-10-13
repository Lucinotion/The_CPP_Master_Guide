#include <iostream>
#include <string>

/*
    CLASSES
*/
// Classes in C++ behave just like structs, except everything is private by default.

class exampleClass
{
private:
    // Everything after this can only be accessed by the class.

    double GenericDouble;
    int intArray[10]{};
    std::string GenericString;

public:
    // Everything after this can be accessed anywhere.

    const int GenericInt{};     // CONST values are assigned when the object is made and can't be changed.
    mutable bool ready = false; // MUTABLE makes variables modificable even if the object has been created as const
    static int instanceCount;   // STATIC members are independent from objects and they can be accessed without making a instance of the class. They must be accessed using the scope (::) operator. 

    //  CONSTRUCTOR, called when an object of the class is created, everything after the : will execute before the constructor, this is the only way to assign constant values and references.
    exampleClass()
    {
        // Default constructor, empty.
        // If no constructor is defined, the compiler creates a default empty constructor
        // You can also use exampleClass() = default; to force the compiler to make a default constructor. This keeps the class as POD (Plain old data).
        // To delete the copy constructor you can use exampleClass() = delete;
    }

    exampleClass(double d, std::string s)
    {
        // Constructor with arguments.
        GenericDouble = d;
        this->GenericString = s; // The this keyword is a pointer to this object, it can be ommited most of the time except when you need a function that returns the object itself.
    }

    exampleClass(int n) : GenericInt{static_cast<double>(n)}, GenericString{std::to_string(n)}, GenericDouble{static_cast<double>(n)}
    {
        // This constructor has a MEMBER INITIALIZER LIST that sets GenericInt, GenericString and GenericDouble. This is the only way to set const values AND references.
    }

    explicit exampleClass(double n)
    {
        // This constructor is explicit, which means that if we have a function that requires a exampleClass object, like examplify(exampleClass a), if we do examplify(23.5) this constructor won't be called and the 23.5 won't be converted into an exampleClass object
        GenericDouble = n;
        GenericString = std::to_string(n);
    }

    // COPY CONSTRUCTOR
    exampleClass(const exampleClass & other){
        // Default copy constructor, empty.
        // If no copy constructor is defined, the compiler creates a default copy constructor that copies everything by value.
        // To delete the default copy constructor you can use exampleClass(const exampleClass&) = delete; exampleClass operator=(const exampleClass&) = delete;
    }

    // DESTRUCTORS, called when the class object goes out of scope or when delete is called.
    ~exampleClass()
    {
        // You can also use ~exampleClass() = default; to force the compiler to make a default destructor.
    }

    // MEMBERS
    double Sum() // A member is any function inside a class, also known as methods.
    {
        return GenericDouble * GenericInt;
    }

    static void Speak() // STATIC members can be accessed without making an object of the class.
    {
        std::cout << "Hello friend!";
    }
    
    const int printInt() // CONST, at the beginning of the member, means that the return is a constant value.
    {
        return 42;
    }

    double veryConstantMember() const{ // COSNT, after the parenthesis, means that the member won´t alter the state (values) of the class.
        return GenericDouble + 1.5;
    }

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
    double getDouble() const // CONST members are members that can be accessed even from const objects because they don't modify the object.
    {
        return GenericDouble;
    }

    bool isReady() const // You should ALLWAYS make const the members that don't modify the object.
    {
        return ready;
    }

    // OPERATOR OVERLOADING
    // You can overload operators so that they work with instances of your class.
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

    // Binary +
    int operator+(const exampleClass &ex) const // Addition operator.
    {
        return ex.GenericInt + GenericInt;
    }

    // Binary -
    int operator-(const exampleClass &ex) const // Subtraction operator.
    {
        return ex.GenericInt - GenericInt;
    }

    // Binary *
    int operator*(const exampleClass &ex) const // Multiplication operator.
    {
        return ex.GenericInt * GenericInt;
    }

    // Binary /
    int operator/(const exampleClass &ex) const // Division operator.
    {
        return ex.GenericInt / GenericInt;
    }

    // Binary %
    int operator%(const exampleClass &ex) const // Modulus operator.
    {
        return ex.GenericInt / GenericInt;
    }

    // Unary -
    int operator-(){
        return -GenericInt;
    }

    // Unary +
    int operator+()
    {
        return +GenericInt;
    }

    // Unary pre ++
    exampleClass & operator++()
    {
        ++GenericDouble;
        return *this;
    }

    // Unary post ++
    exampleClass & operator++(int)
    {
        GenericDouble++;
        return *this;
    }

    // Unary pre --
    exampleClass & operator--()
    {
        --GenericDouble;
        return *this;
    }

    // Unary post --
    exampleClass & operator--(int)
    {
        GenericDouble--;
        return *this;
    }

    // Index operator (for assignation)
    int & operator [] (size_t index)
    {
        return intArray[index];
    }

    // Index operator [] CONST version (for getting values)
	const int const & operator [] (size_t index) const
    {
        return intArray[index];
    }

    // Call operator ()
    void operator()(const double d){ // Can have any return type and any arguments
        GenericDouble = d;
    }

    // Equals operator (for comparing objects)
    bool operator==(const exampleClass &ex) const
    {
        return ex.GenericInt == GenericInt;
    }

    // Not equals operator (for comparing different objects)
    bool operator!=(const exampleClass &ex) const
    {
        return ex.GenericInt != GenericInt;
    }

    // Conversion to double operator (same for any other basic type).
    operator double() const 
    {
        return GenericDouble;
    }
};

// NON MEMBER OPERATOR OVERLOAD
// When you do 5 + 6 you are executing the + operator of the 5 and passing 6 as the operator.
// So if you want it so that 6 + 5 also works, you need to make a global operator overload.
inline bool operator<(const int &n, const exampleClass &ex)
{
    return n < ex.getDouble();
}

int main()
{
    exampleClass example(5);                    // Creating an instance, or object, of the class.
    const exampleClass anotherExample(10);      // Creating a constant instance, or object, of the class. Only const member are accesible and only mutable fields can be changed.
    auto otherExample = new exampleClass(10.5); // Creating a pointer and assigning a new instance, or object, of the class to it.

    example.setDouble(5.5);                              // Accessing members of object.
    std::cout << otherExample->getDouble() << std::endl; // Accessing members of object with pointer.
    std::cout << anotherExample.isReady() << std::endl;  // Accessing const members of const object.
    std::cout << example + anotherExample << std::endl;  // Using a overloaded operator.
    exampleClass::Speak();                               // Calling a static member.

    return 0;
}
