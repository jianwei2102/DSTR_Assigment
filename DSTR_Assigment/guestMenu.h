#pragma once

#include <iostream>

#include "guestMenuUI.h"
#include "repository.h"
#include "binarySearch.h"
#include "linearSearch.h"

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
            linearSearchMenu();
            break;
        case 3:
            searchingComparision();
            break;
        case 4:
            return;
        default:
            return;
        }
    }

    static void binarySearchMenu() {
        system("cls");

        int choice = guestMenuUI::searchCriteria_UI();

        switch (choice)
        {
        case 1:
        {
            Repository* r = Repository::getInstance();

            //get search input value
            string searchValue;

            while (true) {
                cout << "Enter a university's full name to search: ";
                cin.ignore();

                getline(cin, searchValue);

                //sort first 
                MergeSort::mergeSort(r->AllUniList->UniArray, 0, 1421, "Institution");

                //perform binary search
                BinarySearch::binarySearch(r->AllUniList->UniArray, 0, 1421, "name", searchValue);

                cout << endl;
                string input;
                cout << "Enter any other key to exit: ";
                cin >> input;

                break; 
            }

            
            break;
        }
            
        case 2:
        {
            Repository* r = Repository::getInstance();

            //get search input value
            string searchValue;

            while (true) {
                cout << "Enter a university's location to search: ";
                cin.ignore();

                getline(cin, searchValue);

                //sort first 
                MergeSort::mergeSort(r->AllUniList->UniArray, 0, 1421, "Location");

                //perform binary search
                BinarySearch::binarySearch(r->AllUniList->UniArray, 0, 1421, "location", searchValue);

                cout << endl;
                string input;
                cout << "Enter any other key to exit: ";
                cin >> input;

                break;
            }
            break;
        }
        case 3:
            return;
        default:
            return;
        }
    }

    static void linearSearchMenu() {
        system("cls");

        int choice = guestMenuUI::searchCriteria_UI();

        switch (choice)
        {
        case 1:
        {
            Repository* r = Repository::getInstance();

            //get search input value
            string searchValue;

            while (true) {
                cout << "Enter a university's full name to search: ";
                cin.ignore();

                getline(cin, searchValue);

                //perform binary search
                LinearSearch::linearSearch(r->AllUniList->UniArray, 1422, "name", searchValue);
               
                cout << endl;
                string input;
                cout << "Enter any other key to exit: ";
                cin >> input;

                break;
            }
            break;
        }

        case 2:
        {
            Repository* r = Repository::getInstance();

            //get search input value
            string searchValue;

            while (true) {
                cout << "Enter a university's location to search: ";
                cin.ignore();

                getline(cin, searchValue);

                //perform binary search
                LinearSearch::linearSearch(r->AllUniList->UniArray, 1422, "location", searchValue);

                cout << endl;
                string input;
                cout << "Enter any other key to exit: ";
                cin >> input;

                break;
            }
            break;
        }
        case 3:
            return;
        default:
            return;
        }
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
            MergeSort::mergeSort(r->AllUniList->UniArray, 0, 1421, "Institution");
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

        //reset sorting
        QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Rank");

        //quick sort
        auto startQuickSortTimer = chrono::high_resolution_clock::now();
        QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Institution");
        auto stopQuickSortTimer = chrono::high_resolution_clock::now();

        //reset sorting
        QuickSort::quickSort(r->AllUniList->UniArray, 0, 1421, "Rank");

        //merge sort
        auto startMergeSortTimer = chrono::high_resolution_clock::now();
        MergeSort::mergeSort(r->AllUniList->UniArray, 0, 1421, "Institution");
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

    static void searchingComparision() {
        Repository* r = Repository::getInstance();

        //binary search
        auto startBinarySearchTimer = chrono::high_resolution_clock::now();
        BinarySearch::binarySearch(r->AllUniList->UniArray, 0, 1421, "name", "Sunway University");
        auto stopBinarySearchTimer = chrono::high_resolution_clock::now();

        //linear search
        auto startLinearSearchTimer = chrono::high_resolution_clock::now();
        LinearSearch::linearSearch(r->AllUniList->UniArray, 1421, "name", "Sunway University");
        auto stopLinearSearchTimer = chrono::high_resolution_clock::now();

        //calculate quick sort duration
        auto binarySearchDuration = chrono::duration_cast<chrono::microseconds>(stopBinarySearchTimer - startBinarySearchTimer);

        //calculate merge sort duration
        auto linearSearchDuration = chrono::duration_cast<chrono::microseconds>(stopLinearSearchTimer - startLinearSearchTimer);

        while (true) {
            cout << endl;
            cout << "Time consumption of binary search: " << binarySearchDuration.count() << " ms" << endl;
            cout << "Time consumption of linear search: " << linearSearchDuration.count() << " ms" << endl;
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