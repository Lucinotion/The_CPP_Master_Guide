struct Box{
    int a = 5;
};

int main()
{
    // CONSTRUCTOR CALL
    int answer = 42;				   //assignment notation
    int apple_count(4);				   //functional notation
    int orange_count{8};			   //uniform initialization, gives better warinings and initializes in 0
    int flowerCount{1}, scoreCount{3}; //multiple assignment with commas
    Box my_box;

    /*
        OPERATORS
    */
    // NEW OPERATOR
    int * pointer = new int(5);
    Box * new_pointer = new Box();

    // DELETE OPERATOR
    delete pointer;

    // ASSIGNMENT OPERATORS
    // Assignation
    answer = 42;

    // Additive assignation
    answer += 1;

    // Substractive assignation
    answer -= 2;

    // Multiplicative assignation
    answer *= 3;

    // Divisible assignation
    answer /= 4;

    // Modulative assignation
    answer %= 5;

    // MEMORY POINTERS OPERATORS
    // Adress operator
    pointer = &answer;

    // Dereference operator
    apple_count = *pointer; 

    // ACCESS OPERATORS
    // Member operator
    answer = my_box.a; // Access the member of a object

    // Member of pointer operator
    answer = new_pointer->a; // Access the member of an object from a pointer

    // Member access through pointer to member
    // ->*

    // UNARY ARITHMETIC OPERATIORS
    // Increament
    answer++;
    ++answer;

    // Decrement
    answer--;
    --answer;

    // Sign
    answer = -answer;
    answer = +answer;

    // BINARY ARITHMETIC OPERATORS
    // Addition
    int additive = 1 + 1;

    // Substraction
    int substractive = 3 - 1;

    // Multiplication
    int multiplicative = 8 * 8;

    // Division
    int divisible = 4 / 4;

    // Modulus
    int modulative = 5 % 2;

    // RELATIONAL OR COMPARATION OPERATORS
    // Equial to
    bool equalTo = 5 == 6; // Returns true if they are equal

    // Not equal to
    bool notEqual = 5 != 6; // Returns true if they are unequal

    // Greater than
    bool greater = 6 > 5; // Returns true if the left operand is bigger than the right one

    // Greater or equal
    bool greaterEquals = 6 >= 5; // Returns true if the left operand is bigger or equals the right one

    // Less than
    bool lesser = 6 < 5; // Returns true if the left operand is less than the right one

    // Less or equal
    bool lesserEquals = 6 <= 5; // Returns true if the left operand is less or equals the right one

    // LOGICAL OPERATORS
    // Logical And
    bool LAnd = true && true; // Returns true if all of them are true

    // Logical Or
    bool LOr = false || true; // Returns true if at least one of them is true

    // Logical Not
    bool LNot = !true; // Returns true when false, returns false when true

    // BITWISE OPERATORS
    // Bitwise And
    bool And = true & true; // Returns 1 if both of them are 1
    And &= true;

    // Bitwise Or
    bool Or = true | false; // Returns 1 if one of them is 1
    Or |= false;

    // Bitwise Xor
    bool Xor = true ^ true; // Returns 1 if both are different, {1 ^ 0, 0 ^ 1}
    Xor ^= false;

    // Bitwise Not
    int Not = ~0b1010; // Turns 1 into 0 and 0 into 1

    // Bitwise Right
    int Right = 0b1000 >> 1; // Moves the specified number of bits to the right
    Right >>= 1;

    // Bitwise Left
    int Left = 0b0001 << 1; // Moves the specified number of bits to the left
    Left <<= 1;

    // TERNARY CONDITIONAL OPERATOR
    bool ternary = true ? false : true; // Returns the value before the : if the condition is true, otherwise it returns the value after the :

    // SIZEOF OPERATOR
    int size = sizeof answer; // Returns the size in bytes

    // EXTRA OPERATORS
    // Function call operator
    // ()

    // Index operator
    // []

    // Comma operator
    // ,

    // COMPOUND EXPRESSIONS
    int length = 23;
    int width = 42;
    long perimeter{(2 * width) + (2 * length)}; // Here the parenthesis are optional because multiplications always take place before sums
    long wtf{2 * (length + 3 * (width + 4 * (perimeter + 5 * perimeter)))};

    return 0;
}
