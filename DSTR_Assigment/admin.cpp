#include "admin.hpp"
#include "user.hpp"
#include "repository.h"

void Admin::deleteInactiveUser() {
    // Get current time
    time_t now = time(0);
    //UserNode* current = AllUserList->head;
    UserNode* current = nullptr; //***
    while (current != nullptr) {
        // Get user last login time
        time_t lastLoginTime = current->LastLogin;
        double secondsSinceLastLogin = difftime(now, lastLoginTime);
        // A month
        if (secondsSinceLastLogin > 2592000) {
            cout << current->Username << endl;
            // delete the user
            // AllUserList->displayUserTree;
        }
        //current = current->NextUser;
    }
}

bool Admin::login(string Username, string Password) {
    // Check if username and password are correct
    if (Username == "admin" && Password == "admin123") {
        cout << "logged in" << endl;
        // Delete inactive user after login
        deleteInactiveUser();
        return true;
    }
    else {
        return false;
    }
}

void Admin::displayUserList() {

    //AllUserList->inorder(AllUserList->getRoot());


    //UserNode* current = AllUserList->head;
    UserNode* current = nullptr; //***
    cout << left << setw(15) << "User ID"
        << left << setw(20) << "Username"
        << left << setw(20) << "Password"
        << left << setw(25) << "Last Login Time" << endl;
    while (current != NULL) {
        cout << left << setw(15) << current->UserID
            << left << setw(20) << current->Username
            << left << setw(20) << current->Password
            << left << setw(25) << endl;
        //<< ctime(&current->LastLogin) << endl;
        //current = current->NextUser;
        current = nullptr; //***
    }

}

void Admin::modifyUserDetail(string UserID, string UpdateType, string UpdateData) {
    //UserNode* User = AllUserList->getUserNode(UserID);
    UserNode* User = nullptr; //***
    if (UpdateType == "Username") {
        User->Username = UpdateData;
    }
    else if (UpdateType == "Email") {
        User->Email = UpdateData;
    }
    else if (UpdateType == "Password") {
        User->Password = UpdateData;
    }
}


// Task 3
void Admin::viewUserFeedbackList() {
    Repository* r = Repository::getInstance();
    Feedbacklist* AllFeedbackLists = r->AllFeedbackLists;
    if (AllFeedbackLists == NULL) {
        cout << "There is no feedback yet" << endl;
        return;
    }


    FeedbackNode* currentFeedback = AllFeedbackLists->head;
    while (currentFeedback != NULL) {
        //cout << r->AllFeedbackLists->getUserNode(currentFeedback->UserID)->Username << ": " << currentFeedback->Feedback << endl;
        cout << currentFeedback->UserID << ": " << currentFeedback->Feedback << endl;
        ReplyNode* currentReply = currentFeedback->ReplyList->head;
        if (currentReply == NULL) {
            cout << "There is no reply yet" << endl;
        }
        else {
            while (currentReply != NULL) {
                cout << "Replied by " << currentReply->Username << ": " << currentReply->Reply << endl;
                currentReply = currentReply->NextReply;
            }
        }
        currentFeedback = currentFeedback->NextFeedback;
    }
    string test;
    cin >> test;
}



void Admin::insertReplyIntoFeedbackNode(string FeedbackID, string Username, string Reply) {
    // Get feedback node for both all feedback list and user feedback list
    Repository* r = Repository::getInstance();
    Feedbacklist* AllFeedbackLists = r->AllFeedbackLists;
    FeedbackNode* currentAllFeedback = AllFeedbackLists->getFeedbackNode(FeedbackID);
    FeedbackNode* currentFeedback = r->AllUserList->searchUser(currentAllFeedback->UserName)->FeedbackList->getFeedbackNode(FeedbackID);
    // Validation on the feedback node
    if (currentFeedback == NULL || currentAllFeedback == NULL ) {
        cout << "Error: Feedback not found" << endl;
        return;
    }
    // Insert to both feedback node
    currentAllFeedback->ReplyList->insertReplyIntoFeedback(Username, Reply);
    currentFeedback->ReplyList->insertReplyIntoFeedback(Username, Reply);
}
/*
// Task 4
void Admin::generateReport() {
    FavouriteUnilist* TopFavouriteList = AllFavouriteUnilist->generateFavouriteUniRecord();
    UserFavouriteUni* currentUni = TopFavouriteList->head;
    while (currentUni != NULL) {
        cout << "Uni ID: " << currentUni->UniID << endl << endl;
        cout << "Uni Count: " << currentUni->favoriteCount << endl << endl;
        currentUni = currentUni->NextUni;
    }
}

*/