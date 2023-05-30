#pragma once

#include "user.hpp"

#include <iostream>
#include <string>

using namespace std;

class Admin {
public:
    void deleteInactiveUser();

    static bool login();

    static void displayUserList();

    /*
    * void modifyUserDetail(string UserID, string UpdateType, string UpdateData);
    * static void viewUserFeedbackList();
    * static void insertReplyIntoFeedbackNode(string FeedbackID, string Username, string Reply);
    */
};