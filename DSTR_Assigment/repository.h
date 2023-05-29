#pragma once

#include "user.hpp"
#include "uni.hpp"

class Repository {
private:
    static Repository * objPtr;
public:
    UserNode* loginUser;

    UserList* AllUserList;
    UniList* AllUniList;

    Repository(){}

    static Repository* getInstance()
    {
        if (objPtr == NULL)
        {
            objPtr = new Repository();
        }
        return objPtr;
    }

private:
    ~Repository() {
        delete AllUserList;
        delete AllUniList;
    }
};

Repository* Repository::objPtr = nullptr;
