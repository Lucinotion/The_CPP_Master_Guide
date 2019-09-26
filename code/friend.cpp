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
    friend friendMember::execute(regularClass rc);
    
};

// FRIEND CLASS DEFINITION
class friendClass{

    void execute(regularClass rc){
        rc.getPrivate();
    }

};

class friendMember{
    // FRIEND CLASS MEMBER DEFINITION
    auto execute(regularClass rc){
        rc.getPrivate();
    }

};
