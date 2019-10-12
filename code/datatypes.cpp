const long double PI{3.1415968L}; // Global variable, default value is 0, can be accessed with ::PI

#include <cstddef>

/*
    ALIASES
*/
using veryBigNumber = unsigned long long; // This is the new way to define an alias name for initializing unsigned long longthis
typedef long double veryBigFloats;        // This is the old way of defining an alias name for initializing long doubles
#define END ;                             // Using preprocesses you can also define symbols or values, now writing END is the same as pressing ;

int main()
{
    /* 
        DATATYPES
    */
    // Most datatypes are signed by default.
    // You can use 0xnnnn where n is a hexadecimal number to assign values to variables like 0xDEADlu
    // You can use 0nnnn where n is a octal number to assign values to variables like 0657
    // You can use 0bnnnn where n is a binary number to assign values to variables like 0b11111111

    // BOOLEANS
    bool myBoolean = true; // 1 bit, can be true or false, 1 or 0. In memory it's actually 1 byte because nothing can be smaller than 1 byte.

    // CHARACTERS
    char caracter{'a'}, caracterDEC{97}, caracterHEX{'\x61'}; // 1 byte from -128 to 127 same as {signed char} In most compilers chars are unsigned.
    wchar_t wideChar{L'a'};                                   // 2 or 4 bytes L prefix is required
    char16_t veryLongChar{u'\xe1'};                           // 2 bytes u prefix is required
    char32_t extraLongChar{U'\xfa'};                          // 4 bytes U prefix is required

    // STRINGS
    char oldString[]{"This is a old C STYLE STRING"};
    const char *oldConstantString{"This is a pointer to a constant C STYLE STRING"};
    // Raw strings
    const char *oldCharConstantString{R"~(This is a pointer to a constant RAW STRING LITERAL)~"}; // Raw string literals don't need scape sequences for special characters like \ they do need a delimitator for " and )(. I like to use ~ as the delimitator
    const wchar_t *oldWCharConstantString{LR"~(This is a pointer to a constant WCHAR_T RAW STRING LITERAL)~"};
    const char16_t *oldChar16ConstantString{uR"~(This is a pointer to a constant CHAR16_T RAW STRING LITERAL)~"};
    const char32_t *oldCahr32ConstantString{UR"~(This is a pointer to a constant CHAR32_T RAW STRING LITERAL)~"};

    // INTEGERS
    short shortier{32767};                            // 2 bytes from -32768 to 32767 same as {short int / signed short / signed short int}, short is supposed to be equal or smaller than a int.
    int integer{2147483647};                          // 4 bytes from -2147483648 to 2147483647 same as {signed / signed int}, it can also be 2 or 8 bytes in some compilers.
    long longInteger{2147483647L};                    // 4 bytes from -2147483648 to 2147483647 same as {long int / signed long / signed long int}, long is supposed to be larger or equal to int.
    long long veryLongInteger{9223372036854775807LL}; // 8 bytes from -9223372036854775808 to 9223372036854775807 same as {long long int / signed long long/ signed long long int}, long long is supposed to be larger than int.
    
    // FLOATING POINT
    float singlePrecission{.1234567F};                          // 4 bytes from -2147483648 to 2147483647 up to 7 decimals of precission with no integer-part
    double doublePrecission{.123456789012345};                  // 8 bytes from -9223372036854775808 to 9223372036854775807  up to 15 decimals of precission with no integer-part
    long double doubleExtendedPrecission{.123456789012345678L}; // 8 bytes from -9223372036854775808 to 9223372036854775807  up to 18 decimals of precission with no integer-part

    // OTHERS
    size_t sizeT{18446744073709551615ULL}; // Maximun size of anything, 8 bytes unsigned, from 0 up to 1844674407370955161, it varies depending on the architecture of the processor.

    //const char bigChungus[18446744073709551615]{}; // DO NOT UNCOMMENT THIS LINE, THIS ARRAY RIQUIRES A TOTAL OF 16777216TB OF RAM!!!

    // AUTO
    auto autovar0{10};
    auto autovar1{1000000UL};
    auto autovar2{3.14159};
    auto autovar3{79832473274LL};
    auto autovar4{.1234F};
    auto autovar5{'a'};
    auto autovar6{L'a'};
    auto autovar7{u'a'};
    auto autovar8{U'a'};
    auto autovar9{R"~(Raw string)~"};

    /*
        MODIFIERS
    */

    // SIGN
    signed int signedInt{-15439};
    unsigned int unsignedInt{5412U};

    // STATIC
    static int staticVar{32}; // Static variables last until the end of the program and there is only one instance of each. The static members of a class can be accessed without instantiating the class.

    // CONST
    const double pi{3.14159265}; // Constant objects cannot be modified at runtime, however, if they have mutable fields, those fields can be altered.

    // MUTABLE
    // Mutable makes fields inside a const class or structure modificable at runtime

    // VOLATILE
    volatile int explode; // Volatile fields are not optimized by the compiler, since they can be modified depending on the hardware specifications. I'm volatile and, you know, I can be changed by some XYZ that you're not even aware of. That XYZ could be anything. Maybe some alien outside this planet called program. Maybe some lighting, some form of interrupt, volcanoes, etc can mutate me. Maybe. You never know who is going to change me! So O you ignorant, stop playing an all-knowing god, and don't dare touch the code where I'm present. Okay?

    // EXTERN
    extern int alien; // External linkage, used in global variables defined in header files

    // THREAD_LOCAL
    thread_local int localDuration; // Makes the varialbe have tread storage duration, which means that every thread will have its own variable initialized, and it can only be changed by that thread.

    /*
        CASTING
    */

    // IMPLICIT
    integer = singlePrecission + longInteger;

    // EXPLICIT OLD C style
    integer = (int)singlePrecission + (int)longInteger; // In c++ you can also use int(var) to cast like if you where calling the int's constructor.

    // EXPLICIT NEW C++17 style
    integer = static_cast<signed int>(singlePrecission) + static_cast<signed int>(longInteger);

    /*
        static_cast is the first cast you should attempt to use. It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions (or implicit ones). In many cases, explicitly stating static_cast isn't necessary, but it's important to note that the T(something) syntax is equivalent to (T)something and should be avoided. A T(something, something_else) is safe, however, and guaranteed to call the constructor.
        static_cast can also cast through inheritance hierarchies. It is unnecessary when casting upwards (towards a base class), but when casting downwards it can be used as long as it doesn't cast through virtual inheritance. It does not do checking, however, and it is undefined behavior to static_cast down a hierarchy to a type that isn't actually the type of the object.

        const_cast can be used to remove or add const to a variable; no other C++ cast is capable of removing it (not even reinterpret_cast). It is important to note that modifying a formerly const value is only undefined if the original variable is const; if you use it to take the const off a reference to something that wasn't declared with const, it is safe. This can be useful when overloading member functions based on const, for instance. It can also be used to add const to an object, such as to call a member function overload.
        const_cast also works similarly on volatile, though that's less common.

        dynamic_cast is almost exclusively used for handling polymorphism. You can cast a pointer or reference to any polymorphic type to any other class type (a polymorphic type has at least one virtual function, declared or inherited). You can use it for more than just casting downwards -- you can cast sideways or even up another chain. The dynamic_cast will seek out the desired object and return it if possible. If it can't, it will return nullptr in the case of a pointer, or throw std::bad_cast in the case of a reference.
        dynamic_cast has some limitations, though. It doesn't work if there are multiple objects of the same type in the inheritance hierarchy (the so-called 'dreaded diamond') and you aren't using virtual inheritance. It also can only go through public inheritance - it will always fail to travel through protected or private inheritance. This is rarely an issue, however, as such forms of inheritance are rare.

        reinterpret_cast is the most dangerous cast, and should be used very sparingly. It turns one type directly into another - such as casting the value from one pointer to another, or storing a pointer in an int, or all sorts of other nasty things. Largely, the only guarantee you get with reinterpret_cast is that normally if you cast the result back to the original type, you will get the exact same value (but not if the intermediate type is smaller than the original type). There are a number of conversions that reinterpret_cast cannot do, too. It's used primarily for particularly weird conversions and bit manipulations, like turning a raw data stream into actual data, or storing data in the low bits of an aligned pointer.
    */

    return 0;
}
