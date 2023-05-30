#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "feedback.hpp"
#include "favUni.hpp"

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

class UserList {

private:
    static UserNode* root;
    static UserNode* nullNode;
    static int size;

public:
    UserList()
    {
        nullNode->color = 'B';
        nullNode->leftUser = nullptr;
        nullNode->rightUser = nullptr;
        root = nullNode;
    }

    UserNode* createNewUserNode(string Username, string Email, string Password, int id);

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
    void removeFavouriteUniFromUser(UserNode* User, string UniID);
    void showOwnFavoriteUni(UserNode* User);

    void addFeedbackToUser(UserNode* User, const string& Feedback);
    
    static void displayUserList();
    static void displayUser(UserNode* root, string indent);

    /*void showOwnFeedback(UserNode* User);
    * void insertReplyIntoFeedbackNode(string FeedbackID, UserNode* User, const string& Reply);
    */

};
