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
            // Take Note !!!
            if (currentUser->Username == username && currentUser->Password == password) {
                r->loginUser = currentUser;
                r->loginUser->LastLogin = time(0);

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
                        //userLogin();
                        break;
                    case 2:
                        return;
                    default:
                        //userLogin();
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
                r->AllUserList->displayUserList();
            case 3:
                userProfile();
                break;
            case 4:
                return;
            case 5:
                // return sorting menu for ar, fsr and er
                scoreSortingMenu();
                break;
            default:
                mainMenu();
                break;
            }
        }
    }


    //sorting
    static void scoreSortingMenu() {
        Repository* r = Repository::getInstance();

        system("cls");
        int choice = userMenuUI::uniSortValue_UI();

        switch (choice)
        {
        case 1:
            QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Ar");
            QuickSort::printByPagination(r->AllUniList->UniArray, "Ar");
            return;
        case 2:
            QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Fsr");
            QuickSort::printByPagination(r->AllUniList->UniArray, "Fsr");
            return;
        case 3:
            QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Er");
            QuickSort::printByPagination(r->AllUniList->UniArray, "Er");
            return;
        case 4:
            return;
        default:
            return;
        }
    }


    static void userProfile() {

        while (true)
        {
            Repository* r = Repository::getInstance();  
            system("cls");
            r->AllUserList->displayLoginUser(r->loginUser);

            int choice = userMenuUI::profileMenu_UI();

            switch (choice) {
                case 1:
                    modifyProfile();
                    break;
                case 2:
                    return; // Return to previous menu, auto break out of the loop
                default:
                    break; // Loop again
            }
        }
    }

    static void modifyProfile() {
        Repository* r = Repository::getInstance();
        UserNode* loginUser = r->loginUser;
        while (true)
        {
            system("cls");
            string changes;
            UserNode* check;
            int choice = userMenuUI::modifyProfileMenu_UI();

            switch (choice) {
                case 1: // Username
                    modifyUsername();
                    break;

                case 2: // Email
                    modifyEmail();
                    break;

                case 3: // Password
                {
                    modifyPassword();
                    break;
                }

                case 4: // Return to previous menu
                    return;

                default: // Invalid input, loop again (breaks out of switch)
                    break;
                }
        }
        
    }

    static void modifyUsername() {

        string changes;
        UserNode* check;
        Repository* r = Repository::getInstance();
        UserNode* loginUser = r->loginUser;

        while (true)
        {
            changes = userMenuUI::modifyChanges_UI();

            check = r->AllUserList->searchUser(changes);

            if (changes.empty())
                return;

            if (check->Username.empty() || loginUser->Username == changes) // Check username has not been taken
            {
                r->AllUserList->deleteNode(loginUser->Username);
                loginUser->Username = changes;
                r->AllUserList->insertIntoUserTree(loginUser);
                userMenuUI::userSuccess_UI();
                return;
            } 


            cout << "Username has been taken" << endl << endl;
            int choice = userMenuUI::retry_UI();

            if(choice == 1)
                continue;
            
            return;
        }
    }

    static void modifyEmail() {
        string changes;
        UserNode* check;
        Repository* r = Repository::getInstance();
        UserNode* loginUser = r->loginUser;
        
        while (true)
        {
            changes = userMenuUI::modifyChanges_UI();

            if (changes.empty())
                return;

            check = r->AllUserList->searchUserByEmail(changes);

            if (check->Username.empty() || loginUser->Email == changes) // Check email has not been taken
            {
                r->AllUserList->deleteNode(loginUser->Username); // Remove node from tree, object is not deleted
                loginUser->Email = changes; // Update email
                r->AllUserList->insertIntoUserTree(loginUser); // Reinsert node
                userMenuUI::userSuccess_UI();
                return;
            }

            cout << "Email has been taken" << endl << endl;
            int choice = userMenuUI::retry_UI();

            if (choice == 1)
                continue;

            return;
        }

    }

    static void modifyPassword()
    {
        string changes;
        UserNode* check;
        Repository* r = Repository::getInstance();
        UserNode* loginUser = r->loginUser;
        string oldPassword;
        int choice;

        while (true)
        {
            cout << "Enter your old password: "; // Get new password
            cin.ignore();
            getline(cin, oldPassword);

            if (oldPassword.empty())
                return;

            else if (oldPassword == loginUser->Password)
                break;

            cout << "Invalid Password" << endl << endl; // Not equal, display error, loop again
            choice = userMenuUI::retry_UI();

            if (choice == 1)
                continue;

            return;
        }

        while (true)
        {
            cout << "Enter the new password (more than 8 characters): "; // Get new password
            cin.ignore();
            getline(cin, changes);

            if (changes.empty())
                return;

            else if (changes.length() > 8)
                break;
 
            cout << "Invalid Password" << endl << endl;
            choice = userMenuUI::retry_UI();

            if (choice == 1)
                continue;

            return;
        }

        r->AllUserList->deleteNode(loginUser->Username);
        loginUser->Password = changes;
        r->AllUserList->insertIntoUserTree(loginUser);
        userMenuUI::userSuccess_UI(); // Display success
        return; // Go back
    }
};

