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
    UserNode* leftUser;
    UserNode* rightUser;
    UserNode* parent;
    char color;
};

class UserList;
extern UserList* AllUserList;
class UserList {

private:
    UserNode* root;
    UserNode* nullNode = new UserNode;

public:
    UserList()
    {
        nullNode->color = 'B';
        nullNode->leftUser = nullptr;
        nullNode->rightUser = nullptr;
        root = nullNode;
    }

    UserNode* createNewUserNode(string Username, string Email, string Password);

    void leftRotate(UserNode* node);

    void rightRotate(UserNode* node);

    void insertIntoUserTree(string Username, string Email, string Password);

    void insertFixup(UserNode* node);

    void transplant(UserNode* u, UserNode* v);

    void displayUserTree(UserNode* root, string indent, bool last);

    void deleteNode(string searchKey);

    void deleteFixup(UserNode* x);

    UserNode* searchUserByUsername(string searchKey);

    UserNode* minimum(UserNode* node);

    UserNode* getRoot();

    //UserNode* getNullNode();

    //void inorderHelper(UserNode* node);

    void inorder(UserNode* root);


    //UserNode* head = NULL;
    //UserNode* tail = NULL;

    //UserNode* createNewUserNode(string Username, string Email, string Password);

    //void insertIntoUserList(string Username, string Email, string Password);

    UserNode* login(string Username, string Password);

    //UserNode* getUserNode(string UserID);

    //void deleteUserNode(string UserID);

    void addFavouriteUniToUser(UserNode* User, string UniID);

    void showOwnFavoriteUni(UserNode* User);

    void addFeedbackToUser(UserNode* User, const string& Feedback);

    void showOwnFeedback(UserNode* User);

    void insertReplyIntoFeedbackNode(string FeedbackID, UserNode* User, const string& Reply);
};