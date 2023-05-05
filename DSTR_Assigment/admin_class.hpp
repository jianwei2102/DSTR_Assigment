#pragma once
#include "user_class.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Admin {
public:
    void deleteInactiveUser();

    bool login(string Username, string Password);

    void displayUserList();

    void modifyUserDetail(string UserID, string UpdateType, string UpdateData);

    void viewUserFeedbackList();

    void insertReplyIntoFeedbackNode(string FeedbackID, string Username, string Reply);

    void generateReport();

};