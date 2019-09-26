class regularClass{

    private:

    auto getPrivate(){
        return "This fuction is private";
    }

    public:

    auto getPublic(){
        return "This function is public";
    }

    friend class friendClass;
};

class friendClass{

    void execute(regularClass rc){
        rc.getPrivate();
    }

};

class friendMember{

};