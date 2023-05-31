#pragma once

#include <iostream>
#include <string>

using namespace std;

struct adminMenuUI {
	static void loginMenu_UI() {
		cout << "  ------------------------------------------- " << endl;
		cout << " |              Admin Login                  |" << endl;
		cout << "  ------------------------------------------- " << endl;
	}

	static int mainMenu_UI() {
		cout << "  --------------------------------- " << endl;
		cout << " |              Admin              |" << endl;
		cout << " |  1 - View List of Universities  |" << endl;
		cout << " |  2 - Sort Universitise          |" << endl;
		cout << " |  3 - Generate Fav Uni Report    |" << endl;
		cout << " |  4 - View Users                 |" << endl;
		cout << " |  5 - View Feedback              |" << endl;
		cout << " |  6 - Log Out                    |" << endl;
		cout << "  ---------------------------------" << endl;
		
		int input = 0;
		cout << "Select an Operation Number: ";
		cin >> input;

		return input;
	}

	static int uniSort_UI() {
		cout << "SORTING MENU" << endl;
		cout << "[1] Merge Sort" << endl;
		cout << "[2] Quick Sort" << endl;
		cout << "[3] Comparison of Algorithm" << endl;
		cout << "[0] Back" << endl;
		cout << "Enter your choice: ";
		int input = 0;
		cin >> input;
		return input;
	}

	static int userlist_UI() {
		cout << "USER MENU" << endl;
		cout << " [1] Modify User           " << endl;
		cout << " [2] Delete User           " << endl;
		cout << " [3] Search User           " << endl;
		cout << " [4] Delete Inactive User  " << endl;
		cout << " [5] Back                  " << endl;
		int input = 0;
		cout << "Select an Operation Number: ";
		cin >> input;
		return input;
	}

	static string modifyUser_UI() {
		cout << " Enter the user's username to modify: ";
		string input;
		cin.ignore();
		getline(cin, input);
		
		return input;
	}

	static string searchUser_UI() {
		cout << " Enter the user's username to search: ";
		string input;
		cin.ignore();
		getline(cin, input);

		return input;
	}

	static void invalidUser_UI() {
		cout << " Invalid username being entered!";
		cout << " Enter any key to return to main menu.";
		string input;
		cin.ignore();
		getline(cin, input);

		return;
	}

	static int modifyUserOption_UI() {
		cout << " USER MENU - Modify attributes" << endl;
		cout << " [1] Username" << endl;
		cout << " [2] Email" << endl;
		cout << "---------------------------------------------------------------------------------------------" << endl;
		cout << " Select an attributes to be modified: ";
		int input = 0;
		cin >> input;

		return input;
	}

	static string modifyUserChanges_UI() {
		cout << " Enter the new value: ";
		string input;
		cin.ignore();
		getline(cin, input);

		return input;
	}

	static string deleteUser_UI() {
		cout << " Enter the user's username to delete: ";
		string input;
		cin.ignore();
		getline(cin, input);

		return input;
	}

	static void feedback_UI() {
		cout << "  --------------------------------------------------------------- " << endl;
		cout << " |                        User feedback                          |" << endl;
		cout << "  --------------------------------------------------------------- " << endl;
	}

	static string addReply_UI() {
		string reply;
		cout << "   Enter your new reply: ";
		cin.ignore();
		getline(cin, reply);

		return reply;
	}

	static void favReport_UI() {
		// Display table header
		system("cls");
		cout << "  ---------------------------------------------- " << endl;
		cout << " |          Top 10 Favourite Uni Report         |" << endl;
		cout << "  ---------------------------------------------- " << endl;
		cout << left << setw(17) << " | UniID";
		cout << left << setw(31) << "Favourite Count" << right << "|" << endl;
		return;
	}

	static void favReportExit_UI() {
		cout << " Enter any key to return to main menu.";
		string input;
		cin.ignore();
		getline(cin, input);
		return;
	}
};