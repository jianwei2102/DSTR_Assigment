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

	static int mainMenu_UI() {
		cout << "  --------------------------------- " << endl;
		cout << " |               User              |" << endl;
		cout << " |  1 - View List of Universities  |" << endl;
		cout << " |  2 - View Inbox                 |" << endl;
		cout << " |  3 - View Profile               |" << endl;
		cout << " |  4 - Log Out                    |" << endl;
		cout << " |  5 - Sort University            |" << endl;
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
};