#pragma once

#include <iostream>
#include <string>

using namespace std;

struct userMenuUI {
	static void loginMenu_UI() {
		cout << "  ------------------------------------------- " << endl;
		cout << " |               User Login                  |" << endl;
		cout << "  ------------------------------------------- " << endl;
	}

	static int invalidLogin_UI() {
		cout << endl << " Invalid username or password!" << endl;
		cout << " [1] Retry login" << endl;
		cout << " [2] Return to Main Menu" << endl;
		cout << " Select an Operation Number: ";
		int choice = 0;
		cin >> choice;

		return choice;
	}

	static int mainMenu_UI() {
		cout << "  --------------------------------- " << endl;
		cout << " |               User              |" << endl;
		cout << " |  1 - View List of Universities  |" << endl;
		cout << " |  2 - Sort University            |" << endl;
		cout << " |  3 - View Fav Uni               |" << endl;
		cout << " |  4 - View Inbox                 |" << endl;
		cout << " |  5 - View Profile               |" << endl;
		cout << " |  6 - Log Out                    |" << endl;
		cout << "  ---------------------------------" << endl;

		int input = 0;
		cout << "Select an Operation Number: ";
		cin >> input;

		return input;
	}

	static int uniSortValue_UI() {
		cout << "  -------------------------------------------" << endl;
		cout << " |                Sorting                    |" << endl;
		cout << " |  1 - Sort by Academic Reputation Score    |" << endl;
		cout << " |  2 - Sort by Faculty/Student Ratio Score  |" << endl;
		cout << " |  3 - Sort by Employer Reputation Score    |" << endl;
		cout << " |  4 - Back                                 |" << endl;
		cout << "  -------------------------------------------" << endl;

		cout << "Enter your choice: ";
		int input = 0;
		cin >> input;
		return input;
	}


	static int profileMenu_UI() {
		cout << "  --------------------------------- " << endl;
		cout << " |               User              |" << endl;
		cout << " |  1 - Modify Profile             |" << endl;
		cout << " |  2 - Back                       |" << endl;
		cout << "  ---------------------------------" << endl;

		int input = 0;
		cout << "Select an Operation Number: ";
		cin >> input;
		return input;
	}

	static int modifyProfileMenu_UI() {
		cout << "  --------------------------------- " << endl;
		cout << " |               User              |" << endl;
		cout << " |  1 - Username                   |" << endl;
		cout << " |  2 - Email                      |" << endl;
		cout << " |  3 - Password                   |" << endl;
		cout << " |  4 - Go Back                    |" << endl;
		cout << "  ---------------------------------" << endl;

		int input = 0;
		cout << "Select an Operation Number: ";
		cin >> input;
		return input;
	}

	static string modifyChanges_UI() {
		cout << "Enter the new value: ";
		string input;
		cin.ignore();
		getline(cin, input);

		return input;
	}

	static void userSuccess_UI() {
		cout << "Your information has been updated successfully" << endl;
		cout << "Enter any key to return." << endl;
		string input;
		cin.ignore();
		getline(cin, input);

		return;
	}

	static int retry_UI() {
		cout << "1 - Retry" << endl;
		cout << "2 - Return to Previous Menu" << endl;

		int choice = 0;
		cout << "Select an Operation Number: ";
		cin >> choice;
		cout << endl;
		return choice;
	}


	static void feedback_UI() {
		cout << "  ------------------------------------------- " << endl;
		cout << " |              User feedback                |" << endl;
		cout << "  ------------------------------------------- " << endl;
	}

	static string addReply_UI() {
		string reply;
		cout << "   Enter your new reply: ";
		cin.ignore();
		getline(cin, reply);

		return reply;
	}

	static string addFeedback_UI() {
		string feedback;
		cout << "   Enter your new feedback: ";
		cin.ignore();
		getline(cin, feedback);
		
		return feedback;
	}

	static void favUniList_UI() {
		// Display table header
		cout << "  -------------------------------------------------------- " << endl;
		cout << " |                   Favourite Uni List                   |" << endl;
		cout << "  -------------------------------------------------------- " << endl;
		cout << left << setw(12) << " | UniID";
		cout << left << setw(46) << "Insitution" << right << "|" << endl;
		return;
	}
};