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
		cout << " |  2 - View Fav Uni               |" << endl;
		cout << " |  3 - View Inbox                 |" << endl;
		cout << " |  4 - View Profile               |" << endl;
		cout << " |  5 - Log Out                    |" << endl;
		cout << "  ---------------------------------" << endl;

		int input = 0;
		cout << "Select an Operation Number: ";
		cin >> input;

		return input;
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