class friendMember{
    void execute(regularClass rc);
};

class regularClass{

private:

    auto getPrivate(){
        return "This fuction is private";
    }

public:

    auto getPublic(){
        return "This function is public";
    }

    // FRIEND CLASS DECLARATION
    friend class friendClass;
    
    // FRIEND CLASS MEMBER DECLARATION
    friend void friendMember::execute(regularClass rc);
    
};

// FRIEND CLASS DEFINITION
class friendClass{

    void execute(regularClass rc){
        rc.getPrivate();
    }

};

// FRIEND CLASS MEMBER DEFINITION
void friendMember::execute(regularClass rc){
    rc.getPrivate();
}