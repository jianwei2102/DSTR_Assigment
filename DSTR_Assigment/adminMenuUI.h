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
		cout << " |  2 - Sort Universitise (remove) |" << endl;
		cout << " |  3 - View Users                 |" << endl;
		cout << " |  4 - View Feedback              |" << endl;
		cout << " |  5 - Log Out                    |" << endl;
		cout << "  ---------------------------------" << endl;
		
		int input = 0;
		cout << "Select an Operation Number: ";
		cin >> input;

		return input;
	}

	

	static int userlist_UI() {
		cout << " 1 - Modify User         " << endl;
		cout << " 2 - Delete User         " << endl;
		cout << " 3 - Search              " << endl;
		cout << " 4 - Back                " << endl;
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

	static void invalidUser_UI() {
		cout << " Invalid username being entered!";
		cout << " Enter any key to return to main menu.";
		string input;
		cin.ignore();
		getline(cin, input);

		return;
	}

	static int modifyUserOption_UI() {
		cout << " Modify attributes" << endl;
		cout << " 1 - Username" << endl;
		cout << " 2 - Email" << endl;
		cout << "Select an attributes to be modified: ";
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
};