#pragma once

#include <iostream>
#include <string>

using namespace std;

struct guestMenuUI
{
	static int mainMenu_UI() {
		cout << "  --------------------------------- " << endl;
		cout << " |               Guest             |" << endl;
		cout << " |  1 - View List of Universities  |" << endl;
		cout << " |  2 - Sort University            |" << endl;
		cout << " |  3 - Search University          |" << endl;
		cout << " |  4 - Register                   |" << endl;
		cout << " |  5 - Back                       |" << endl;
		cout << "  ---------------------------------" << endl;

		int input = 0;
		cout << "Select an Operation Number: ";
		cin >> input;

		return input;
	}

	static int uniSort_UI() {
		cout << "  --------------------------------- " << endl;
		cout << " |          Sorting Menu           |" << endl;
		cout << " |  1 - Merge Sort                 |" << endl;
		cout << " |  2 - Quick Sort                 |" << endl;
		cout << " |  3 - Comparison of Algorithm    |" << endl;
		cout << " |  4 - Back                       |" << endl;
		cout << "  ---------------------------------" << endl;

		cout << "Enter your choice: ";
		int input = 0;
		cin >> input;
		return input;
	}

	static int uniSearch_UI() {
		cout << "  --------------------------------- " << endl;
		cout << " |         Searching Menu          |" << endl;
		cout << " |  1 - Binary Search              |" << endl;
		cout << " |  2 - Linear Search              |" << endl;
		cout << " |  3 - Comparison of Algorithm    |" << endl;
		cout << " |  4 - Back                       |" << endl;
		cout << "  ---------------------------------" << endl;

		cout << "Enter your choice: ";
		int input = 0;
		cin >> input;
		return input;
	}

	static int searchCriteria_UI() {
		cout << "  --------------------------------- " << endl;
		cout << " |         Searching By            |" << endl;
		cout << " |  1 - Institution                |" << endl;
		cout << " |  2 - Location                   |" << endl;
		cout << " |  3 - Back                       |" << endl;
		cout << "  ---------------------------------" << endl;

		cout << "Enter your choice: ";
		int input = 0;
		cin >> input;
		return input;
	}
};