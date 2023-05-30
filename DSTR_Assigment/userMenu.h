#pragma once

#include <iostream>

#include "userMenuUI.h"
#include "repository.h"

struct userMenu {
    static void userLogin() {
        while (true)
        {
            system("cls");
            userMenuUI::loginMenu_UI();
            
            string username, password;
            cout << "Please enter user's username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Please enter user's password: ";
            getline(cin, password);

            Repository* r = Repository::getInstance();

            UserNode* currentUser = r->AllUserList->searchUser(username);
            if (currentUser->Username == username && currentUser->Password == password) {
                r->loginUser = currentUser;
                mainMenu();
                return;
            }
            else {
                cout << endl << "Invalid username and password!" << endl;
                cout << "1 - Retry login" << endl;
                cout << "2 - Return to Main Menu" << endl;

                int choice = 0;
                cout << "Select an Operation Number: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    userLogin();
                    break;
                case 2:
                    return;
                default:
                    userLogin();
                    break;
                }
            }
        }
    }

    static void mainMenu() {
        Repository* r = Repository::getInstance();

        while (true)
        {
            system("cls");
            int choice = userMenuUI::mainMenu_UI();

            switch (choice)
            {
            case 1:
                r->AllUniList->displayUniList();
                break;
            case 2:
                showOwnFeedback();
                break;
            case 3:
                // feedback
                
                break;
            case 4:
                return;
            default:
                mainMenu();
                break;
            }
        }
    }






    // ----- Feedback -----
    static void showOwnFeedback() {
        Repository* r = Repository::getInstance();

        FeedbackNode* currentFeedback = r->loginUser->FeedbackList->head;

        if (!currentFeedback)
        {
            cout << "No feedback found for the user" << endl << endl;;
            string choice;
            cout << "Navigate: (A)dd, (Q)uit : ";
            cin >> choice;

            if (choice == "A" || choice == "a") {
                addFeedback();
            }
            return;
        }

        string input;
        system("cls");
        while (true)
        {
            userMenuUI::feedback_UI();
            time_t lastUpdateTime = currentFeedback->UpdateTime;
            char buffer[26];
            ctime_s(buffer, sizeof(buffer), &lastUpdateTime);
            buffer[24] = '\0';  // Remove the newline character from the output
            cout << "   Update Time: " << buffer << endl;

            time_t createTime = currentFeedback->CreateTime;
            char buffer1[26];
            ctime_s(buffer, sizeof(buffer), &createTime);
            buffer[24] = '\0';  // Remove the newline character from the output
            cout << "   Create Time: " << buffer << endl;
            cout << "   FeedbackID:  " << currentFeedback->FeedbackID << endl;
            cout << "   Description: " << currentFeedback->Feedback << endl;

            ReplyNode* currentReply = currentFeedback->ReplyList->head;
            if (currentReply == NULL) {
                cout << "   There is no reply yet" << endl;
            }
            else {
                while (currentReply != NULL) {
                    cout << "   Replied by " << currentReply->Username << ": " << currentReply->Reply << endl;
                    currentReply = currentReply->NextReply;
                }
            }

            cout << "Navigate: (N)ext, (P)revious, (A)dd, (R)eply, (Q)uit : ";

            cin >> input;

            if (input == "n" || input == "N")
            {
                if (currentFeedback->NextFeedback != NULL) {
                    currentFeedback = currentFeedback->NextFeedback;
                    system("cls");
                }
                else {
                    system("cls");
                    cout << "This is the last feedback." << endl;
                }
            }
            else if (input == "p" || input == "P")
            {
                if (currentFeedback->PrevFeedback != NULL) {
                    currentFeedback = currentFeedback->PrevFeedback;
                    system("cls");
                }
                else {
                    system("cls");
                    cout << "This is the first feedback." << endl;
                }
            } else if (input == "A" || input == "a") {
                addFeedback();
            }
            else if (input == "R" || input == "r") {
                addReply(currentFeedback);
            }
            else if (input == "q" || input == "Q")
            {
                return;
            }
            else
            {
                cout << "Invalid input. Please enter N for next, P for previous, or Q to quit." << endl;

            }
        }
    }

    static void addFeedback() {
        Repository* r = Repository::getInstance();
        string feedback;
        cout << "Enter your new feedback: ";
        cin.ignore();
        getline(cin, feedback);
        r->AllUserList->addFeedbackToUser(r->loginUser, feedback);
        return;
    }

    static void addReply(FeedbackNode* feedback) {
        Repository* r = Repository::getInstance();
        string reply;
        cout << "Enter your new reply: ";
        cin.ignore();
        getline(cin,reply);
        feedback->UpdateTime = time(0);
        r->AllFeedbackLists->getFeedbackNode(feedback->FeedbackID)->UpdateTime = time(0);
        r->AllFeedbackLists->sortFeedbackList();
        r->AllUserList->searchUser(feedback->UserName)->FeedbackList->sortFeedbackList();
        r->AllUserList->insertReplyIntoFeedbackNode(feedback->FeedbackID, r->loginUser, reply);
        return;
    }
};