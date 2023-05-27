#include <iostream>
#include <chrono>
#include "read_file.hpp"
#include "uni_class.hpp"
#include "admin_class.hpp"
#include "favouriteUni_class.hpp"
#include "feedback_class.hpp"
#include "reply_class.hpp"
#include "user_class.hpp"
#include "MergeSort.h"
#include "QuickSort.h"
#include "BinarySearchTest.h"
#include "SortingArScore.h"
#include "SortingFsrScore.h"
#include "SortingErScore.h"

#include "user_ui.hpp"
#include "user_controller.hpp"
using namespace std;

/*
void sortingUserMenu() {
    int sortingChoiceInput = 0;

    UniList list = ReadUniFromFile();

    cout << "SORTING MENU - University Information" << endl;
    cout << "[1] Sort by Academic Reputation Score" << endl;
    cout << "[2] Sort by Faculty/Student Ratio Score" << endl;
    cout << "[3] Sort by Employer Reputation Score" << endl;
    cout << "[0] Back" << endl;
    cout << "Enter your choice: " << endl;
    cin >> sortingChoiceInput;

    if (sortingChoiceInput == 1) {
        mergeSortArScore(list.UniArray, 0, 1422 - 1);

        // print sorted list
        printArScoreByPagination(list.UniArray, 1422 - 1);
    }
    else if (sortingChoiceInput == 2) {
        mergeSortFsrScore(list.UniArray, 0, 1422 - 1);

        // print sorted list
        printFsrScoreByPagination(list.UniArray, 1422 - 1);
    }
    else if (sortingChoiceInput == 3) {
        mergeSortErScore(list.UniArray, 0, 1422 - 1);

        // print sorted list
        printErScoreByPagination(list.UniArray, 1422 - 1);
    }
    else if (sortingChoiceInput == 0) {
        sortingUserMenu();
    }

}

void sortingMenu() {
    int sortingChoiceInput = 0;
    auto start_time = chrono::high_resolution_clock::now();
    auto end_time = chrono::high_resolution_clock::now();

    UniList list = ReadUniFromFile();

    cout << "SORTING MENU" << endl;
    cout << "[1] Merge Sort" << endl;
    cout << "[2] Quick Sort" << endl;
    cout << "[3] Comparison of Algorithm" << endl;
    cout << "[0] Back" << endl;
    cout << "Enter your choice: " << endl;
    cin >> sortingChoiceInput;

    if (sortingChoiceInput == 1) {
        // time taken for merge sort
        start_time = chrono::high_resolution_clock::now();
        mergeSort(list.UniArray, 0, 1422 - 1);
        end_time = chrono::high_resolution_clock::now();
        cout << "Time consumption of merge sort: " << (end_time - start_time).count() << " ns" << endl;
        cout << endl;
        cout << "Instituitions (Ascending) " << endl;

        // print sorted list
        printByPagination(list.UniArray, 1422 - 1);
    }
    else if (sortingChoiceInput == 2) {
        // time taken for quick sort
        start_time = chrono::high_resolution_clock::now();
        quickSort(list.UniArray, 0, 1422 - 1);
        end_time = chrono::high_resolution_clock::now();
        cout << "Time consumption of quick sort: " << (end_time - start_time).count() << " ns" << endl;
        cout << "Instituitions (Ascending) " << endl;

        // print sorted list
        printByPagination(list.UniArray, 1422 - 1);
    }
    else if (sortingChoiceInput == 3) {
        // time taken for merge sort
        start_time = chrono::high_resolution_clock::now();
        mergeSort(list.UniArray, 0, 1422 - 1);
        end_time = chrono::high_resolution_clock::now();
        cout << "Time consumption of merge sort: " << (end_time - start_time).count() << " ns" << endl;
        cout << endl;

        // time taken for quick sort
        start_time = chrono::high_resolution_clock::now();
        quickSort(list.UniArray, 0, 1422 - 1);
        end_time = chrono::high_resolution_clock::now();
        cout << "Time consumption of quick sort: " << (end_time - start_time).count() << " ns" << endl;
    }
    else if (sortingChoiceInput == 0) {
        sortingMenu();
    }

}
*/


int main() {
    // Display uni
    UniList list = ReadUniFromFile();

    cout << sizeof(list.UniArray);

    //list.displayUniList();

    //sortingMenu();
    //sortingUserMenu();



    // Create a UserList object
    UserList* userList = new UserList();
    UserUI* userUI = new UserUI();
    UserController userController(userList, userUI);



    // Insert some users into the list
    userList->insertIntoUserTree("Alice", "alice@gmail.com","Alice123");
    userList->insertIntoUserTree("Bob", "bob@gmail.com", "qwerty");
    userList->insertIntoUserTree("C", "ac@gmail.com", "ac");


    // Get a user object from the list (in this case, Alice)
    UserNode* alice = userList->login("Alice", "Alice123");
    UserNode* bob = userList->login("Bob", "qwerty");
    UserNode* ac = userList->login("C", "ac");



    // Create some feedback from Alice
    //userList.addFeedbackToUser(alice, "This is my feedback");
    //userList.addFeedbackToUser(bob, "Test");
    //userList.addFeedbackToUser(alice, "This is my second feedback");
   
   
    //userList.addFeedbackToUser(bob, "Test 2");
    //userList.addFeedbackToUser(alice, "This is my third feedback");
    //userList.insertReplyIntoFeedbackNode("26500", alice, "This is my reply"); // 41, 6334
    //userList.insertReplyIntoFeedbackNode("26500", alice, "This is my second reply"); // 41, 6334
    //cout << endl << "Show alice" << endl;
    //userList.showOwnFeedback(alice);
    //cout << endl << "Show bob" << endl;
    //userList.showOwnFeedback(bob);


    // Create some uni fav from Alice
    userList->addFavouriteUniToUser(alice, "UNI05");
    userList->addFavouriteUniToUser(alice, "UNI031");
    userList->addFavouriteUniToUser(ac, "UNI03");
    userList->addFavouriteUniToUser(alice, "UNI03");
    //userList->removeFavouriteUniFromUser(alice, "UNI031");
    //userList->addFavouriteUniToUser(alice, "UNI03");

    userList->addFavouriteUniToUser(bob, "UNI031");
    userList->addFavouriteUniToUser(bob, "UNI021");
    //userList->addFavouriteUniToUser(bob, "UNI021");

    alice == nullptr;
    bob == nullptr;
    ac == nullptr;

    //cout << endl << "Show Alice" << endl;
    //userList->showOwnFavoriteUni(alice);
    //cout << endl << "Show Ac" << endl;
    //userList->showOwnFavoriteUni(ac);
    //cout << endl << "Show Bob" << endl;
    //userList.showOwnFavoriteUni(bob);
    //Admin admin;
    /*admin.login("admin", "admin123");
    admin.viewUserFeedbackList();
    admin.insertReplyIntoFeedbackNode("26500", "Admin", "This is reply from admin");*/
    //admin.generateReport();
    //admin.displayUserList();
    /*admin.modifyUserDetail("41", "Password", "test321");
    admin.displayUserList();
    
    admin.viewUserFeedbackList();*/
    //userList.showOwnFeedback(alice);


 
    string input;


    while (true)
    {
        cout << endl;
        cout << "1. Sign in as Admin" << endl << "2. Sign in as User" << endl << "3. Register Account" << endl << "4. Continue as Guest" << endl << "5. Exit" << endl;
        cout << "Your input:  ";
        cin >> input;
        cout << endl;
        cin.ignore();

        if (input == "2")
        {       
            userController.loginHandler();
        }
        else if (input == "3")
        {
            userController.registerHandler();
        }

   }

	return 0;
}