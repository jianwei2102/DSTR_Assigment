#pragma once
#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "user.hpp"
#include "uni.hpp"
#include "favUniCount.h"

class Repository {
private:
    static Repository * objPtr;
public:
    UserNode* loginUser;

    UserList* AllUserList;
    UniList* AllUniList;
    Feedbacklist* AllFeedbackLists;
    HashMap FavUniCount;

    Repository();

    static Repository* getInstance();

private:
    ~Repository();
};


#endif // REPOSITORY_H