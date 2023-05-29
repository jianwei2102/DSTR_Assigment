#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct UserNode {
    string UserID, Username, Email, Password;
    time_t LastLogin;
    UserNode* leftUser;
    UserNode* rightUser;
    UserNode* parent;
    char color;
};

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
    void insertIntoUserTree(UserNode* newUser);
    void insertFixup(UserNode* node);
    void transplant(UserNode* u, UserNode* v);
    void displayUserTree(UserNode* root, string indent, bool last);
    void deleteNode(string searchKey);
    void deleteFixup(UserNode* x);

    UserNode* searchUser(string searchKey);
    UserNode* minimum(UserNode* node);
    UserNode* getRoot();

    void inorder(UserNode* root);


    UserNode* login(string Username, string Password);

    void addFavouriteUniToUser(UserNode* User, string UniID);
    void showOwnFavoriteUni(UserNode* User);

    void addFeedbackToUser(UserNode* User, const string& Feedback);
    void showOwnFeedback(UserNode* User);

    void insertReplyIntoFeedbackNode(string FeedbackID, UserNode* User, const string& Reply);

    void displayUserList();
    void displayUser(UserNode* root, std::string indent);

};