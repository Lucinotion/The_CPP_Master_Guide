#include <iostream>

// INHERITANCE
/*
1. When the base class specifier is public, the access status of the inherited members remains unchanged. Thus, inherited public members are public, and inherited protected members are protected in a derived class. 
2. When the base class specifier is protected, both public and protected members of a base class are inherited as protected members. 
3. When the base class specifier is private, inherited public and protected members become private to the derived class, so they’re accessible by member functions of the derived class but cannot be accessed if they’re inherited in another derived class. 
*/
class A
{
};
class B : public A
{
};
class C : protected B
{
};
class D : private C // By default is private
{
};

// SINGLE INHERITANCE
class Box
{
protected: // Protected fields can only be accessed by derived classes
    double length{1.0};
    double width{1.0};
    double height{1.0};

public: // public fields can be accessed from anywhere
    explicit Box(double side) : Box{side, side, side}
    {
        std::cout << "Box(double) called.\n";
    }
    Box(double le, double wi, double he) : length{le}, width{wi}, height{he}
    {
        std::cout << "Box(double, double, double) called.\n";
    }
    Box()
    {
        std::cout << "Box() called.\n";
    }
    double volume() const
    {
        return length * width * height;
    }
};

class Carton : public Box
{
private:
    std::string material{"Cardboard"};

public:
    Carton(double lv, double wv, double hv, std::string_view mat) : Box{lv, wv, hv}, material{mat}
    {
        std::cout << "Carton(double,double,double,string_view) called.\n";
    }
    explicit Carton(std::string_view mat) : material{mat}
    {
        std::cout << "Carton(string_view) called.\n";
    }
    Carton(double side, std::string_view mat) : Box{side}, material{mat}
    {
        std::cout << "Carton(double,string_view) called.\n";
    }
    Carton()
    {
        std::cout << "Carton() called.\n"; // When we make a new Carton, first Box() is called and then Carton()
    }
};

/*
	MULTIPLE INHERITANCE
*/
class Area
{
public:
    int getArea(int l, int b)
    {
        return l * b;
    }
};

class Perimeter
{
public:
    int getPerimeter(int l, int b)
    {
        return 2 * (l + b);
    }
};
// FINAL makes the class not inheritable
class Square final : public Area, public Perimeter // Square inherits Perimeter and Area
{
    int length;
    int breadth;

public:
    Square(int l, int b)
    {
        length = l;
        breadth = b;
    }
    Square()
    {
        length = 7;
        breadth = 4;
    }

    int area()
    {
        return getArea(length, breadth); // You can use Area::getArea, but here it's not required
    }
    int perimeter()
    {
        return getPerimeter(length, breadth); // You can use Perimeter::getPerimeter, but here it's not required
    }
};

int main()
{
    return 0;
}
