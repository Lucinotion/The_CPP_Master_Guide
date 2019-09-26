// GLOBAL FRIEND FUNCTION DECLARATION
void Say(regularClass rc);

// CLASS DECLARATION
class friendMember{
    void execute(regularClass rc);
};

// CLASS DECLARATION
class friendClass{
    void execute(regularClass rc);
};

// CLASS DECLARATION
class regularClass{

private:

    auto getPrivate();

public:

    // BEFRIEND CLASS
    friend class friendClass;
    
    // BEFRIEND CLASS MEMBER
    friend void friendMember::execute(regularClass rc);

    // BEFRIEND FUNCTION
    friend void Say(regularClass rc); // FRIEND functions are functions that can access private and protected members of the class they are decladed in as friend.
    
};

// PRIVATE MEMBER OF CLASS
auto regularClass::getPrivate(){
    return "This fuction is private";
}

// FRIEND CLASS DEFINITION
void friendClass::execute(regularClass rc){
    rc.getPrivate();
}

// FRIEND CLASS MEMBER DEFINITION
void friendMember::execute(regularClass rc){
    rc.getPrivate();
}

// FRIEND GLOBAL FUNCTION DEFINITION
void Say(regularClass rc){
    rc.getPrivate();
}