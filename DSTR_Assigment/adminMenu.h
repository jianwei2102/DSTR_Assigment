#pragma once

#include <iostream>

#include "admin.hpp"
#include "adminMenuUI.h"
#include "repository.h"
#include "quickSort.h"

struct adminMenu {
    static void adminLogin() {
        
        while (true)
        {
            system("cls");
            adminMenuUI::loginMenu_UI();

            string username, password;
            cout << "Please enter admin username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Please enter admin password: ";
            getline(cin, password);
            

            if (username == "a" && password == "q") {
                mainMenu();
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
                    adminLogin();
                    break;
                case 2:
                    return;
                default:
                    adminLogin();
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
            int choice = adminMenuUI::mainMenu_UI();

            switch (choice)
            {
            case 1:
                
                r->AllUniList->displayUniList();
                break;
            case 2:
                uniSortMenu();
                break;
                
            case 3:
                r->AllUserList->displayUserList();
                userMenu();
            case 4:
                viewUserFeedbackList();
                break;
            case 5:
                return;
            default:
                mainMenu();
                break;
            }
        }
	 }
     
     static void uniSortMenu() {
         
         int choice = adminMenuUI::uniSort_UI();

         switch (choice)
         {
         case 1:
             break;
         case 2:
             quickSortMenu();
             break;
         case 3:
             break;
         case 0:
             return;
         default:
             return;
         }
     }


     static void quickSortMenu() {
         Repository* r = Repository::getInstance();
         int choice = adminMenuUI::uniSortValue_UI();

         switch (choice)
         {
         case 1:
             QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Ar");
             return;
         case 2:
             QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Fsr");
             return;
         case 3:
             QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Er");
             return;
         case 0:
             return;
         default:
             return;
         }
     }
 

     static void userMenu() {
         
         int choice = adminMenuUI::userlist_UI();

         switch (choice)
         {
         case 1:
             system("cls");
             modifyUser();
             break;
         case 2:
             system("cls");
             deleteUser();
             break;
         case 3:

             break;
         case 4:
             break;
         default:
             mainMenu();
             break;
         }
     }


     // ----- Feedback -----
     static void viewUserFeedbackList() {
         Repository* r = Repository::getInstance();
         Feedbacklist* AllFeedbackLists = r->AllFeedbackLists;
         if (AllFeedbackLists == NULL) {
             cout << "There is no feedback yet" << endl;
             return;
         }

         FeedbackNode* currentFeedback = r->AllFeedbackLists->head;
         string input;
         system("cls");
         while (true)
         {
             adminMenuUI::feedback_UI();

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

             cout << "Navigate: (N)ext, (P)revious, (R)eply, (Q)uit : ";

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

     static void addReply(FeedbackNode* feedback) {
         Repository* r = Repository::getInstance();
         string reply;
         cout << "Enter your new reply: ";
         cin.ignore();
         getline(cin, reply);
         feedback->UpdateTime = time(0);
         r->AllFeedbackLists->sortFeedbackList();
         r->AllUserList->searchUser(feedback->UserName)->FeedbackList->getFeedbackNode(feedback->FeedbackID)->UpdateTime = time(0);
         r->AllUserList->searchUser(feedback->UserName)->FeedbackList->sortFeedbackList();
         Admin::insertReplyIntoFeedbackNode(feedback->FeedbackID, "Admin", reply);
         return;
     }

     // ----- USER ------
     static void modifyUser() {
         Repository* r = Repository::getInstance();
         r->AllUserList->displayUserList();

         string username = adminMenuUI::modifyUser_UI();
         UserNode* currentUser = r->AllUserList->searchUser(username);

         if (currentUser->Username != username) {
             adminMenuUI::invalidUser_UI();
             return;
         }
         int modifyOption = adminMenuUI::modifyUserOption_UI();
         string changes;

         switch (modifyOption)
         {
         case 1:
             changes = adminMenuUI::modifyUserChanges_UI();
             r->AllUserList->deleteNode(currentUser->Username);
             currentUser->Username = changes;
             r->AllUserList->insertIntoUserTree(currentUser);

             break;
         case 2:
             changes = adminMenuUI::modifyUserChanges_UI();
             currentUser->Email = changes;
             break;
         default:
             modifyUser();
             break;
         }
     }

     static void deleteUser() {
         Repository* r = Repository::getInstance();
         r->AllUserList->displayUserList();

         string username = adminMenuUI::deleteUser_UI();
         UserNode* currentUser = r->AllUserList->searchUser(username);
         if (currentUser->Username != username) {
             adminMenuUI::invalidUser_UI();
             return;
         }

         cout << " Are you sure you want to delete user " << username << "? (Y/N): ";
         string confirmation;
         getline(cin, confirmation);
         if (confirmation == "Y" || confirmation == "y") {
             r->AllUserList->deleteNode(username);
         }
         else {
             return;
         }
         

     }
};

