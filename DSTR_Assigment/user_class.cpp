#include "user_class.hpp"

UserList* AllUserList = NULL;

// Task 1.1
UserNode* UserList::createNewUserNode(string Username, string Email, string Password) {
    // Create a new UserNode
    string userID = "0";

    if (head != NULL) {
        cout << "HERE";
        string userID = to_string(stoi(tail->UserID) + 1);
    };

    UserNode* newUser = new UserNode();

    newUser->UserID = to_string(rand()); // to_string(rand()); // just for demonstration purposes
    newUser->Username = Username;
    newUser->Email = Email;
    newUser->Password = Password;
    newUser->LastLogin = time(0);
    newUser->FavouriteUniList = new FavouriteUnilist();
    newUser->FeedbackList = new Feedbacklist();
    newUser->NextUser = NULL;

    return newUser;
}

// Task 1.2
// Check duplicate username if same then do again
void UserList::insertIntoUserList(string Username, string Email, string Password) {

    // Create a new UserNode
    UserNode* newUser = createNewUserNode(Username, Email, Password);

    if (AllUserList == NULL) {
        AllUserList = new UserList;
    }
    // If the list is empty, set the new node as the head and tail
    if (AllUserList->head == NULL) {
        AllUserList->head = newUser;
        AllUserList->tail = newUser;
    }
    // Otherwise, insert the new node at the end of the list
    else {
        AllUserList->tail->NextUser = newUser;
        AllUserList->tail = newUser;
    }
}

UserNode* UserList::login(string Username, string Password) {
    //Traverse the list to find a matching user
    UserNode* currentUser = AllUserList->head;
    while (currentUser != NULL) {
        if (currentUser->Username == Username && currentUser->Password == Password) {
            currentUser->LastLogin = time(0); // update last login time
            return currentUser;
        }
        currentUser = currentUser->NextUser;
    }

    // If no matching user is found, return NULL
    return NULL;
}

UserNode* UserList::getUserNode(string UserID) {
    // Traverse the list to find a matching user
    UserNode* currentUser = AllUserList->head;
    while (currentUser != NULL) {
        if (currentUser->UserID == UserID) {
            return currentUser;
        }
        currentUser = currentUser->NextUser;
    }

    // If no matching user is found, return NULL
    return NULL;
}

// Admin task
void UserList::deleteUserNode(string UserID) {}

// Task 2 
void UserList::addFavouriteUniToUser(UserNode* User, string UniID) {
    if (!User) {
        cout << "Error: User node is null." << endl;
        return;
    }

    User->FavouriteUniList->insertIntoFavouriteUni(User->UserID, UniID, false);
}

// Add on show uni details
void UserList::showOwnFavoriteUni(UserNode* User) {
    if (User == NULL) {
        cout << "User not found" << endl;
        return;
    }

    UserFavouriteUni* currentUni = User->FavouriteUniList->head;
    int count = 0;
    while (currentUni != NULL) {
        cout << "User ID: " << currentUni->UserID << endl;
        cout << "Uni ID: " << currentUni->UniID << endl;
        count++;
        currentUni = currentUni->NextUni;
    }
    if (count == 0) {
        cout << "No favourite uni found for the user" << endl;
    }
}

void UserList::addFeedbackToUser(UserNode* User, const string& Feedback) {
    if (!User) {
        cout << "Error: User node is null." << endl;
        return;
    }

    User->FeedbackList->insertIntoFeedbackList(User, Feedback);
}

void UserList::showOwnFeedback(UserNode* User) {
    if (User == NULL) {
        cout << "User not found" << endl;
        return;
    }

    UserNode* currentUser = AllUserList->head;
    while (currentUser != NULL) {
        if (currentUser->UserID == User->UserID) {
            FeedbackNode* currentFeedback = currentUser->FeedbackList->head;
            int count = 0;
            while (currentFeedback != NULL) {
                if (currentFeedback->UserID == User->UserID) {
                    cout << "Feedback ID: " << currentFeedback->FeedbackID << endl;
                    cout << "Feedback: " << currentFeedback->Feedback << endl;
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


                    //cout << "Create Time: " << ctime(&currentFeedback->CreateTime);
                    count++;
                }
                currentFeedback = currentFeedback->NextFeedback;
            }
            if (count == 0) {
                cout << "No feedback found for the user" << endl;
            }
            break;
        }
        currentUser = currentUser->NextUser;
    }
    if (currentUser == NULL) {
        cout << "User not found" << endl;
    }
}

void UserList::insertReplyIntoFeedbackNode(string FeedbackID, UserNode* User, const string& Reply) {
    // Get feedback node for both all feedback list and user feedback list
    FeedbackNode* currentAllFeedback = AllFeedbackLists->getFeedbackNode(FeedbackID);
    FeedbackNode* currentFeedback = User->FeedbackList->getFeedbackNode(FeedbackID);
    // Validation on the feedback node
    if (currentFeedback == NULL || currentAllFeedback == NULL) {
        cout << "Error: Feedback not found" << endl;
        return;
    }
    // Insert to both feedback node
    currentAllFeedback->ReplyList->insertReplyIntoFeedback(User->Username, Reply);
    currentFeedback->ReplyList->insertReplyIntoFeedback(User->Username, Reply);
}