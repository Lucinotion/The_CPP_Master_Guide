/*
    LAMBDA EXPRESSIONS
*/
// A lambda expression is a special type of SHORT function that doesn't have a specific type, and are usually made to not be reusable.
// You cannot specify the type of a lambda function and must use auto if you want to declare one.
// They have the next structure:
// [capture](arguments){body}.
// CAPTURE: It's a variable that comes from the scope where the lambda gets defined. If you put = you have access to everything by value, if you put & you have access to everything by reference.
// ARGUMENTS: Those are arguments that are declared inside the lambda scope and cannot be used outside.
// BODY: The place where the operations and logic of the function is.

const int apply_function_to_integer(int x, int (*function)(int i)){ return function(x);}

int main()
{
    int a{13};
    int b{};
    double d{};

    // CREATING a lambda expression.
    auto f = [=](int i, int j){ return i * j + a; }; // Here the = inside the [capture] means that the values of the scope are accessed by value.
    auto r = [&](){ return a++; };                   // Here the & inside the [capture] means that the values of the scope are accessed by reference.
    auto pi = []()->double { return 355.0/113.0; };  // If the return type is not clear, you can specify it with the ->type declaration after the (arguments).

    // CALLING the lambda expression.
    r();
    d = pi();
    b = f(5, 6);

    // PASSING lambdas to functions.
    apply_function_to_integer(5, [](int i)->int { return i * i;}); // You cannot put anything inside the [capture] when sending a lambda to a function.

    return 0;
}
