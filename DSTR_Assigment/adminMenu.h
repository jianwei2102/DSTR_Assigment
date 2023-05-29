#pragma once

#include <iostream>


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
                // feedback
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

