#pragma once
#include "repository.h"

Repository* Repository::objPtr = nullptr;

Repository::Repository() {
    loginUser = nullptr;
    AllUserList = new UserList();
    AllUniList = new UniList();
    AllFeedbackLists = new Feedbacklist();
}

Repository::~Repository() {
    delete AllUserList;
    delete AllUniList;
    delete AllFeedbackLists;
}

Repository* Repository::getInstance() {
    if (objPtr == nullptr) {
        objPtr = new Repository();
    }
    return objPtr;
}

