#pragma once

#include "favouriteUni_class.hpp"
#include "feedback_class.hpp"
#include <iostream>
#include <string>
using namespace std;

class FavouriteUnilist; // forward declaration
class Feedbacklist; // forward declaration

struct UserNode {
    string UserID, Username, Email, Password;
    time_t LastLogin;
    FavouriteUnilist* FavouriteUniList;
    Feedbacklist* FeedbackList;
    UserNode* NextUser;
};

class UserList;
extern UserList* AllUserList;
class UserList {
public:
    UserNode* head = NULL;
    UserNode* tail = NULL;

    UserNode* createNewUserNode(string Username, string Email, string Password);

    void insertIntoUserList(string Username, string Email, string Password);

    UserNode* login(string Username, string Password);

    UserNode* getUserNode(string UserID);

    void deleteUserNode(string UserID);

    void addFavouriteUniToUser(UserNode* User, string UniID);

    void showOwnFavoriteUni(UserNode* User);

    void addFeedbackToUser(UserNode* User, const string& Feedback);

    void showOwnFeedback(UserNode* User);

    void insertReplyIntoFeedbackNode(string FeedbackID, UserNode* User, const string& Reply);
};