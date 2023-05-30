#pragma once
#include "user.hpp"
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


    
    static void viewUserFeedbackList();

    static void insertReplyIntoFeedbackNode(string FeedbackID, string Username, string Reply);

    /*void generateReport();
    */
};