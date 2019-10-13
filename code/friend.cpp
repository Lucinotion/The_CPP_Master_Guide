/*
    THE FRIEND KEYWORD
/*
// This allows functions, members of classes or entire classes to access the private or protected members of another class.
// A class can befriend another function/ member/ class so that this can access it's private and protected members. However.
// This relationship is not mutual unless the other class also befriends the other.
// This keyword is considered bad praxis for a lot of people and has been removed from newer OOP languajes.

/*
    DECLARATIONS
*/
// GLOBAL FUNCTION DECLARATION
void Say(regularClass rc);

// CLASS DECLARATIONS
class friendMember{
    void execute(regularClass rc);
};
class friendClass{
    void execute(regularClass rc);
};
class regularClass{

private:

    auto getPrivate();

public:

    /*
        BEFRIEND
    */
    // BEFRIEND CLASS
    // That class can now access all the private members of this class
    friend class friendClass;
    
    // BEFRIEND CLASS MEMBER
    // That class member can now access all the private members of this class
    friend void friendMember::execute(regularClass rc);

    // BEFRIEND FUNCTION
    // That global function can now access all the private members of this class
    friend void Say(regularClass rc); // FRIEND functions are functions that can access private and protected members of the class they are decladed in as friend.
    
};

/*
    DEFINITIONS
*/
// PRIVATE CLASS MEMBER DEFINITION
auto regularClass::getPrivate(){
    return "This fuction is private";
}

// CLASS MEMBER DEFINITIONS
void friendClass::execute(regularClass rc){
    rc.getPrivate();
}
void friendMember::execute(regularClass rc){
    rc.getPrivate();
}

// GLOBAL FUNCTION DEFINITION
void Say(regularClass rc){
    rc.getPrivate();
}