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
                changes = userMenuUI::modifyChanges_UI();
                check = r->AllUserList->searchUser(changes);
                if (check->Username.empty() || loginUser->Username == changes) // Check username has not been taken
                {
                    r->AllUserList->deleteNode(loginUser->Username);
                    loginUser->Username = changes;
                    r->AllUserList->insertIntoUserTree(loginUser);
                    userMenuUI::userSuccess_UI();
                }
                else 
                {
                    userMenuUI::userExist_UI();
                    break;
                }
                return;

            case 2: // Email
                changes = userMenuUI::modifyChanges_UI();
                check = r->AllUserList->searchUserByEmail(changes);
                if (check->Username.empty() || loginUser->Email == changes) // Check email has not been taken
                {
                    r->AllUserList->deleteNode(loginUser->Username); // Remove node from tree, object is not deleted
                    loginUser->Email = changes; // Update email
                    r->AllUserList->insertIntoUserTree(loginUser); // Reinsert node
                    userMenuUI::userSuccess_UI();
                }
                else
                {
                    userMenuUI::userExist_UI();
                    break;
                }
                return;

            case 3: // Password
            {
                    string oldPassword = userMenuUI::userPassword_UI(); // Check input = old password
                    if (oldPassword != loginUser->Password) // Not equal, display error, loop again
                    {
                        userMenuUI::invalidPassword_UI();
                        break;
                    }
                    cout << "Enter the new value: "; // Get new password
                    getline(cin, changes);
                    r->AllUserList->deleteNode(loginUser->Username);
                    cout << loginUser->Password << endl;
                    loginUser->Password = changes;
                    r->AllUserList->insertIntoUserTree(loginUser);
                    userMenuUI::userSuccess_UI(); // Display success
                    return; // Go back
            }
            case 4: // Return to previous menu
                return;

            default: // Invalid input, loop again
                break;
            }
        }
        
    }
};

