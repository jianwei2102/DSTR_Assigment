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

            // Input username and password
            string username, password;
            cout << "Please enter user's username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Please enter user's password: ";
            getline(cin, password);

            // Search for user
            Repository* r = Repository::getInstance();
            UserNode* currentUser = r->AllUserList->searchUser(username);
            // If correct credentail
            if (currentUser->Username == username && currentUser->Password == password) {
                r->loginUser = currentUser;
                mainMenu();
                return;
            }
            // If invalid credential
            else {
                int choice = userMenuUI::invalidLogin_UI(); // input choice

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
                favUniManage();
                break;
            case 3:
                showOwnFeedback();
                break;
            case 4:
                // profile
                
                break;
            case 5:
                // Log out
                r->loginUser = NULL;
                return;
            default:
                mainMenu();
                break;
            }
        }
    }


    // ----- Fav Uni -----
    static void favUniManage() {

        Repository* r = Repository::getInstance();        
        string input;

        while (true)
        {
            userMenuUI::favUniList_UI();
            r->AllUserList->showOwnFavoriteUni(r->loginUser);
            cout << " Navigate: (A)dd, (R)emove, (V)iew, (Q)uit : ";

            cin >> input;

            if (input == "a" || input == "A")
            {
                addFavUni();
            }
            else if (input == "r" || input == "R")
            {
                removeFavUni();
            }
            else if (input == "v" || input == "V")
            {
                viewFavUni();
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

    static void addFavUni(){}

    static void removeFavUni(){}

    static void viewFavUni(){
        // Prompt uni ID input
        string id;
        cout << " Enter the uni ID: ";
        cin.ignore();
        getline(cin, id);

        // From id get index
        Repository* r = Repository::getInstance();
        UniNode** UniArray = r->AllUniList->UniArray;
        string uniID_s = id.substr(3, 4);
        int uniID_i = stoi(uniID_s) - 1;

        system("cls");
        cout << "  ------------------------------------------------- " << endl;
        cout << " |               University's Detail               |" << endl;
        cout << "  ------------------------------------------------- " << endl;
        cout << " Rank          : " << UniArray[uniID_i]->Rank << endl;
        cout << " University ID : " << UniArray[uniID_i]->UniID << endl;
        cout << " Institution   : " << UniArray[uniID_i]->Insitution << endl;
        cout << " Location Code : " << UniArray[uniID_i]->LocationCode << endl;
        cout << " Location      : " << UniArray[uniID_i]->Location << endl;
        cout << " Ar Score      : " << UniArray[uniID_i]->ArScore << endl;
        cout << " Ar Rank       : " << UniArray[uniID_i]->ArRank << endl;
        cout << " Er Score      : " << UniArray[uniID_i]->ErScore << endl;
        cout << " Er Rank       : " << UniArray[uniID_i]->ErRank << endl;
        cout << " Fsr Score     : " << UniArray[uniID_i]->FsrScore << endl;
        cout << " Fsr Rank      : " << UniArray[uniID_i]->FsrRank << endl;
        cout << " Cpf Score     : " << UniArray[uniID_i]->CpfScore << endl;
        cout << " Cpf Rank      : " << UniArray[uniID_i]->CpfRank << endl;
        cout << " Ifr Score     : " << UniArray[uniID_i]->IfrScore << endl;
        cout << " Ifr Rank      : " << UniArray[uniID_i]->IfrRank << endl;
        cout << " Isr Score     : " << UniArray[uniID_i]->IsrScore << endl;
        cout << " Isr Rank      : " << UniArray[uniID_i]->IsrRank << endl;
        cout << " Irn Score     : " << UniArray[uniID_i]->IrnScore << endl;
        cout << " Irn Rank      : " << UniArray[uniID_i]->IrnRank << endl;
        cout << " Ger Score     : " << UniArray[uniID_i]->GerScore << endl;
        cout << " Ger Rank      : " << UniArray[uniID_i]->GerRank << endl;
        cout << " Score Scaled  : " << UniArray[uniID_i]->ScoreScaled << endl;


        string input;
        cout << "Enter any other key to exit: ";
        getline(cin, input);
    }

    // ----- Feedback -----
    static void showOwnFeedback() {
        // Obtain all feedbacklist from repo
        Repository* r = Repository::getInstance();
        FeedbackNode* currentFeedback = r->loginUser->FeedbackList->head;

        // If there is no feedback made by user yet
        if (currentFeedback == NULL)
        {
            cout << "There is no feedback from the user yet. Enter (A) to add new feedback." << endl << endl;;
            string choice;
            cout << "Navigate: (A)dd, (Q)uit : ";
            cin >> choice;

            if (choice == "A" || choice == "a") {
                addFeedback(); // add new feedback
            }
            return;
        }

        // Display feedback one by one
        string input;
        system("cls");
        while (true)
        {
            // Display feedback details
            userMenuUI::feedback_UI();

            cout << "   FeedbackID      : " << currentFeedback->FeedbackID << endl;
            cout << "   Created by      : " << currentFeedback->UserName << endl;

            // Display update time
            time_t lastUpdateTime = currentFeedback->UpdateTime;
            char buffer[26];
            ctime_s(buffer, sizeof(buffer), &lastUpdateTime);
            buffer[24] = '\0';  // Remove the newline character from the output
            cout << "   Updated Time    : " << buffer << endl;

            // Display create time
            time_t createTime = currentFeedback->CreateTime;
            char buffer1[26];
            ctime_s(buffer1, sizeof(buffer1), &createTime);
            buffer1[24] = '\0';
            cout << "   Created Time    : " << buffer1 << endl;

            cout << "   Description     : " << currentFeedback->Feedback << endl;

            // Display reply details
            ReplyNode* currentReply = currentFeedback->ReplyList->head;
            // If there is no reply yet
            if (currentReply == NULL) {
                cout << "   There is no reply yet. Enter (R) to add reply to this feedback." << endl;
            }
            // Travesal all reply details
            else {
                while (currentReply != NULL) {
                    cout << "   Replied by " << currentReply->Username << ": " << currentReply->Reply << endl;
                    currentReply = currentReply->NextReply;
                }
            }

            // Prompt navigation
            cout << endl << "Navigate: (N)ext, (P)revious, (A)dd, (R)eply, (Q)uit : ";
            cin >> input;

            // Move to next feedback
            if (input == "n" || input == "N")
            {
                system("cls");
                if (currentFeedback->NextFeedback != NULL) {
                    currentFeedback = currentFeedback->NextFeedback;
                }
                else {
                    cout << "This is the last feedback." << endl;
                }
            }
            // Move to previous feedback
            else if (input == "p" || input == "P")
            {
                system("cls");
                if (currentFeedback->PrevFeedback != NULL) {
                    currentFeedback = currentFeedback->PrevFeedback;
                }
                else {
                    cout << "This is the first feedback." << endl;
                }
            } 
            // Add new feedback
            else if (input == "A" || input == "a") {
                addFeedback();

            }
            // Add reply to current feedback
            else if (input == "R" || input == "r") {
                addReply(currentFeedback);
                system("cls");
            }
            // Quit feedback page
            else if (input == "q" || input == "Q")
            {
                return;
            }
            // Invalid input
            else
            {
                cout << "Invalid input. Please enter N for next, P for previous, A for add, R for reply, or Q to quit." << endl;

            }
        }
    }

    static void addFeedback() {
        // Display feedback details
        system("cls");
        userMenuUI::feedback_UI();

        // Prompt for feedback input
        string feedback = userMenuUI::addFeedback_UI();

        // Insert new feedback to the feedback list
        Repository* r = Repository::getInstance();
        r->AllUserList->addFeedbackToUser(r->loginUser, feedback);
        return;
    }

    static void addReply(FeedbackNode* feedback) {
        // Prompt for reply input
        string reply = userMenuUI::addReply_UI();

        Repository* r = Repository::getInstance();
        
        // Update the feedbackNode's updatetime in userNode and sort the list based on update time
        feedback->UpdateTime = time(0);
        r->loginUser->FeedbackList->sortFeedbackList();

        // Update the feedbackNode's updatetime in allfeedbacklist and sort the list based on update time
        FeedbackNode* currentAllFeedback = r->AllFeedbackLists->getFeedbackNode(feedback->FeedbackID);
        currentAllFeedback->UpdateTime = time(0);
        r->AllFeedbackLists->sortFeedbackList();

        // Insert reply into feedbackNode in userNode and allfeedbacklist
        feedback->ReplyList->insertReplyIntoFeedback(r->loginUser->Username, reply);
        currentAllFeedback->ReplyList->insertReplyIntoFeedback(r->loginUser->Username, reply);
        return;
    }

};