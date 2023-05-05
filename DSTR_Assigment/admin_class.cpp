#include "admin_class.hpp"

void Admin::deleteInactiveUser() {
    time_t now = time(0);
    UserNode* current = AllUserList->head;
    while (current != nullptr) {
        time_t lastLoginTime = current->LastLogin;
        double secondsSinceLastLogin = difftime(now, lastLoginTime);
        if (secondsSinceLastLogin > 2592000) {
            // delete the user
            // AllUserList->deleteInactiveUserNode(current->UserID);
        }
        current = current->NextUser;
    }
}

bool Admin::login(string Username, string Password) {
    // Check if username and password are correct
    if (Username == "admin" && Password == "admin123") {
        deleteInactiveUser();
        return true;
    }
    else {
        return false;
    }
}

void Admin::displayUserList() {
    UserNode* current = AllUserList->head;
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
        current = current->NextUser;
    }
}

void Admin::modifyUserDetail(string UserID, string UpdateType, string UpdateData) {
    UserNode* User = AllUserList->getUserNode(UserID);
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

// View all feedback from all users
void Admin::viewUserFeedbackList() {
    if (AllFeedbackLists == NULL) {
        return;
    }
    FeedbackNode* currentFeedback = AllFeedbackLists->head;
    while (currentFeedback != NULL) {
        UserList t;

        cout << t.getUserNode(currentFeedback->UserID)->Username << ": " << currentFeedback->Feedback << endl;
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
}

void Admin::insertReplyIntoFeedbackNode(string FeedbackID, string Username, string Reply) {
    FeedbackNode* currentFeedback = AllFeedbackLists->getFeedbackNode(FeedbackID);
    if (currentFeedback == NULL) {
        cout << "Error: Feedback not found" << endl;
        return;
    }
    currentFeedback->ReplyList->insertReplyIntoFeedback(Username, Reply);
}

void Admin::generateReport() {
    FavouriteUnilist* TopFavouriteList = AllFavouriteUnilist->generateFavouriteUniRecord();
    UserFavouriteUni* currentUni = TopFavouriteList->head;
    while (currentUni != NULL) {

        cout << "Uni ID: " << currentUni->UniID << endl << endl;
        cout << "Uni Count: " << currentUni->favoriteCount << endl << endl;
        currentUni = currentUni->NextUni;
    }
}