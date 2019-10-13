/*
    TEMPLATES
*/
// Templates allow you to use generic types in your classes so that you don't have to overload everything.

// WITH A VARIABLE PARAMETER OF A SPECIFIC TYPE
// All S get replaced by the value, 0 is the default
// Templates get resolved at compile time.
// Dinamically they resolve BEFORE calling the constructor, so they can be used to initialize values.
template <size_t S = 1>
class Array
{
public:
    int elements[S > 1 ? S : 1];
    size_t size{S > 1 ? S : 1};
    size_t max_index{S > 1 ? S - 1 : 0};
};

// WITH A VARIABLE TYPE
// All T get replaced by the type. You can use either class or typename to define the type.
template <class T, size_t S = 1>
class Vector
{
public:
    T elements[S > 1 ? S : 1];
    size_t size{S > 1 ? S : 1};
    size_t max_index{S > 1 ? S - 1 : 0};
};

/*
    SPECIALIZATION
*/
// FULLY SPECIALIZED, all template values are set
template <>
class Vector <float, 0>
{
public:
    float elements[1];
    size_t size{1};
    size_t max_index{0};
};

// PARTILLY SPECIALIZED, some values are set
template <size_t S> // In this list of parameters go everything that is not specialized.
class Vector <float, S> // In here you should put the specific specialization and the parameters not specialized from the upper list.
{
public:
    float elements[S > 1 ? S : 1];
    size_t size{S > 1 ? S : 1};
    size_t max_index{S > 1 ? S - 1 : 0};
};

int main(){
    Array<10>         myArray{};   // Calls template
    Vector<int, 5>    myVector1{}; // Calls base template
    Vector<float, 0>  myVector2{}; // Calls fully specialized template
    Vector<float, 10> myVector3{}; // Calls partially specialized template

    return 0;
}
