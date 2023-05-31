#pragma once

#include <iostream>

#include "guestMenuUI.h"
#include "repository.h"

struct guestMenu
{
    static void mainMenu() {
        Repository* r = Repository::getInstance();

        while (true) {
            system("cls");
            int choice = guestMenuUI::mainMenu_UI();

            switch (choice) {
            case 1:
                r->AllUniList->displayUniList();
                break;;
            case 2:
                uniSortMenu();
                break;
            case 3:
                uniSearchMenu();
                break;
            case 4:
                registerMenu();
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
        system("cls");
        int choice = guestMenuUI::uniSort_UI();

        switch (choice)
        {
        case 1:
            mergeSortMenu();
            break;
        case 2:
            quickSortMenu();
            break;
        case 3:
            sortingComparision();
            break;
        case 4:
            return;
        default:
            return;
        }
    }

    static void uniSearchMenu() {
        system("cls");
        int choice = guestMenuUI::uniSearch_UI();

        switch (choice)
        {
        case 1:
            binarySearchMenu();
            break;
        case 2:
            break;
        case 3:
            // change to search
            sortingComparision();
            break;
        case 4:
            return;
        default:
            return;
        }
    }

    static void binarySearchMenu() {

    }

    static void quickSortMenu() {
        Repository* r = Repository::getInstance();

        while (true) {
            cout << endl;
            QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Institution");
            QuickSort::printByPagination(r->AllUniList->UniArray, "Institution");
            cout << endl;

            string input;
            cout << "Enter any other key to exit: ";
            cin >> input;

            break;
        }
        return;
    }

    static void mergeSortMenu() {
        Repository* r = Repository::getInstance();

        while (true) {
            cout << endl;
            MergeSort::mergeSort(r->AllUniList->UniArray, 0, 1421);
            MergeSort::printByPagination(r->AllUniList->UniArray);
            cout << endl;

            string input;
            cout << "Enter any other key to exit: ";
            cin >> input;

            break;
        }
        return;
    }

    static void sortingComparision() {
        Repository* r = Repository::getInstance();

        //quick sort
        auto startQuickSortTimer = chrono::high_resolution_clock::now();
        QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Ar");
        auto stopQuickSortTimer = chrono::high_resolution_clock::now();

        //TODO:: merge sort
        auto startMergeSortTimer = chrono::high_resolution_clock::now();
        MergeSort::mergeSort(r->AllUniList->UniArray, 0, 1421);
        auto stopMergeSortTimer = chrono::high_resolution_clock::now();

        //calculate quick sort duration
        auto quickSortDuration = chrono::duration_cast<chrono::microseconds>(stopQuickSortTimer - startQuickSortTimer);

        //calculate merge sort duration
        auto mergeSortDuration = chrono::duration_cast<chrono::microseconds>(stopMergeSortTimer - startMergeSortTimer);

        while (true) {
            cout << endl;
            cout << "Time consumption of quick sort: " << quickSortDuration.count() << " ms" << endl;
            cout << "Time consumption of merge sort: " << mergeSortDuration.count() << " ms" << endl;
            cout << endl;

            string input;
            cout << "Enter any other key to exit: ";
            cin >> input;

            break;
        }
        return;


    }

    static void registerMenu() {
        cin.ignore();
        system("cls");
        Repository* r = Repository::getInstance();
        string username;
        string password;
        string email;
        cout << "Leave fields blank to exit anytime" << endl;

        // Get username
        while (true)
        {
            cout << "Enter username: ";
            getline(cin, username);

            // This part might be kind of hacky, since this if statement must be before the searchUser
            // as they 1 will cancel the other out
            if (username.empty())
                return;

            if (r->AllUserList->searchUser(username)->Username.empty())
                break;
            else if (!r->AllUserList->searchUser(username)->Username.empty())
                cout << "Username has been taken" << endl;
        }


        // Get email
        while (true)
        {
            cout << "Enter email: ";
            getline(cin, email);

            if (email.empty())
                return;

            break;
        }


        // Get password
        while (true)
        {
            cout << "Enter password: ";
            getline(cin, password);

            if (password.length() == 0)
                return;

            if (password.length() > 8)
                break;

            cout << "Password must be 8 or more characters" << endl;
        }

        r->AllUserList->insertIntoUserTree(username, email, password);
        cout << "Your account has been successfully created" << endl;
        string input;
        getline(cin, input);
        return;
    }

};