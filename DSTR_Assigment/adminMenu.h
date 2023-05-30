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
            bool loginStatus = Admin::login(); // Input username and password

            if (loginStatus) {
                // Delete inactive user after login
                // deleteInactiveUser();
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
                adminMenuUI::favReport_UI();
                r->FavUniCount.displaySortedUnis();
                adminMenuUI::favReportExit_UI();
                break;
            case 4:
                userMenu();
                break;
            case 5:
                viewUserFeedbackList();
                break;
            case 6:
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
         while (true) {
             Admin::displayUserList();
             int choice = adminMenuUI::userlist_UI();

             switch (choice)
             {
             case 1:
                 modifyUser();
                 break;
             case 2:
                 deleteUser();
                 break;
             case 3:
                 // search
                 break;
             case 4:
                 // delete inactive
                 deleteInactiveUser();
                 break;
             case 5:
                 return;
             default:
                 break;
             }
         }
     }


     // ----- Feedback -----
     static void viewUserFeedbackList() {
         // Obtain all feedbacklist from repo
         Repository* r = Repository::getInstance();
         FeedbackNode* currentFeedback = r->AllFeedbackLists->head;

         // If there is no feedback made by user
         if (currentFeedback == NULL) {
             cout << "There is no feedback from user yet." << endl;
             return;
         }

         // Display feedback one by one
         string input;
         system("cls");
         while (true)
         {
             // Display feedback details
             adminMenuUI::feedback_UI();

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
             cout << endl << " Navigate: (N)ext, (P)revious, (R)eply, (Q)uit : ";
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
                system("cls");
;               cout << "Invalid input. Please enter N for next, P for previous, R for reply, or Q to quit." << endl;

             }
         }
     }

     static void addReply(FeedbackNode* currentAllFeedback) {
         // Prompt for reply input
         string reply = adminMenuUI::addReply_UI();

         Repository* r = Repository::getInstance();

         // Update the feedbackNode's updatetime in allfeedbacklist and sort the list based on update time
         currentAllFeedback->UpdateTime = time(0);
         r->AllFeedbackLists->sortFeedbackList();

         // Update the feedbackNode's updatetime in userNode and sort the list based on update time
         Feedbacklist* currentUserFeedback = r->AllUserList->searchUser(currentAllFeedback->UserName)->FeedbackList;
         currentUserFeedback->getFeedbackNode(currentAllFeedback->FeedbackID)->UpdateTime = time(0);
         currentUserFeedback->sortFeedbackList();

         // Insert reply into feedbackNode
         currentAllFeedback->ReplyList->insertReplyIntoFeedback("Admin", reply);
         currentUserFeedback->getFeedbackNode(currentAllFeedback->FeedbackID)->ReplyList->insertReplyIntoFeedback("Admin", reply);
         return;
     }

     // ----- USER ------
     static void modifyUser() {
         system("cls");

         // Display all user list
         Repository* r = Repository::getInstance();
         r->AllUserList->displayUserList();

         // Prompt username and search for user node
         string username = adminMenuUI::modifyUser_UI();
         UserNode* currentUser = r->AllUserList->searchUser(username);

         // If the username input is not in userlist
         if (currentUser->Username != username) {
             adminMenuUI::invalidUser_UI();
             return;
         }

         // Prompt modify attributes
         int modifyOption = adminMenuUI::modifyUserOption_UI();
         string changes;
         switch (modifyOption)
         {
         case 1:
             // Username require to reinsert the node for it to be sorted
             changes = adminMenuUI::modifyUserChanges_UI();
             r->AllUserList->deleteNode(currentUser->Username);
             currentUser->Username = changes;
             r->AllUserList->insertIntoUserTree(currentUser);
             break;
         case 2:
             // Email direct change from the node
             changes = adminMenuUI::modifyUserChanges_UI();
             currentUser->Email = changes;
             break;
         default:
             modifyUser();
             break;
         }
     }

     static void deleteUser() {
         system("cls");

         // Display all user list
         Repository* r = Repository::getInstance();
         r->AllUserList->displayUserList();

         // Prompt username and search for user node
         string username = adminMenuUI::deleteUser_UI();
         UserNode* currentUser = r->AllUserList->searchUser(username);

         // If the username input is not in userlist
         if (currentUser->Username != username) {
             adminMenuUI::invalidUser_UI();
             return;
         }

         // Prompt modify attributes on deletion
         cout << " Are you sure you want to delete user " << username << "? (Y/N): ";
         string confirmation;
         getline(cin, confirmation);
         // Delete user node if Y being entered
         if (confirmation == "Y" || confirmation == "y") {
             r->AllUserList->deleteNode(username);
             delete currentUser;
         }
         else {
             return;
         }
     }

     static void deleteInactiveUser() {
         system("cls");

         // Display all user list
         Repository* r = Repository::getInstance();
         r->AllUserList->displayInactiveUserList();

         cout << " Are you sure you want to delete all inactive user ? (Y/N): ";
         string input;
         cin.ignore();
         getline(cin, input);

         if (input == "y" || input == "Y") {
             r->AllUserList->deleteInactiveUser();
         }
         else {
             return;
         }

     }
};

