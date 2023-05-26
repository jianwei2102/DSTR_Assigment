#include <iostream>
#ifdef _WIN32
	#define CLEAR_COMMAND "cls"
#else
	#define CLEAR_COMMAND "clear"
#endif
using namespace std;

void mainMenu();

void guestMenu();

void displayUniList() {  // function to display uni list for guest
	cout << endl << "1 - Search Universities" << endl;
	cout << "2 - Sort Universities" << endl;
	cout << "3 - View List of Universities by Default Order" << endl;
	cout << "4 - Return to Guest Menu" << endl;

	int anInput = 0;
	cout << endl << "Select an Operation Number: ";
	cin >> anInput;
	bool validInput = false;

	while (!validInput) {
		if (anInput >= 1 && anInput <= 4) {
			validInput = true;
			system(CLEAR_COMMAND);
		}
		else {
			cout << "Invalid Input. Please Enter Again: ";
			cin >> anInput;
		}
	}
	if (validInput == true) {
		switch (anInput) {
		case 1:
			//searchUni();
			break;
		case 2:
			//sortUni();
			break;
		case 3:
			//mergeSort();
		case 4:
			guestMenu();
			break;
		}
	}
}

void adminMenu() { // for admin menu after login
	cout << "  ---------------------------------" << endl;
	cout << " |              Admin              |" << endl;
	cout << " |  1 - View List of Universities  |" << endl;
	cout << " |  2 - View Users                 |" << endl;
	cout << " |  3 - View Feedback              |" << endl;
	cout << " |  4 - Log Out                    |" << endl;
	cout << "  ---------------------------------" << endl;

	int anInput = 0;
	cout << "Select an Operation Number: ";
	cin >> anInput;
	bool validInput = false;

	while (!validInput) {
		if (anInput >= 1 && anInput <= 4) {
			validInput = true;
			system(CLEAR_COMMAND);
		}
		else {
			cout << "Invalid Input. Please Enter Again: ";
			cin >> anInput;
		}
	}
	if (validInput == true) {
		switch (anInput) {
		case 1:
			//displayUniList(); for admin
			break;
		case 2:
			//displayUsers();
			break;
		case 3:
			//displayFeedback();
		case 4:
			//logOut();
			break;
		}
	}
}

void userMenu() { // for user menu after login
	cout << "  ---------------------------------" << endl;
	cout << " |              User               |" << endl;
	cout << " |  1 - View List of Universities  |" << endl;
	cout << " |  2 - View Inbox                 |" << endl;
	cout << " |  3 - View Profile               |" << endl;
	cout << " |  4 - Log Out                    |" << endl;
	cout << "  ---------------------------------" << endl;

	int anInput = 0;
	cout << "Select an Operation Number: ";
	cin >> anInput;
	bool validInput = false;

	while (!validInput) {
		if (anInput >= 1 && anInput <= 4) {
			validInput = true;
			system(CLEAR_COMMAND);
		}
		else {
			cout << "Invalid Input. Please Enter Again: ";
			cin >> anInput;
		}
	}
	if (validInput == true) {
		switch (anInput) {
		case 1:
			//displayUniList(); for registered users
			break;
		case 2:
			//displayFeedback();
			break;
		case 3:
			//displayProfile();
			break;
		case 4:
			//logOut();
			break;
		}
	}
}

void registerMenu() {  // registration funciton
	// --function for registering users--
}

void guestMenu() {
	cout << "  ---------------------------------" << endl;
	cout << " |  1 - View List of Universities  |" << endl;
	cout << " |  2 - Return to Main Menu        |" << endl;
	cout << "  ---------------------------------" << endl;

	int anInput = 0;
	cout << "Select an Operation Number: ";
	cin >> anInput;
	bool validInput = false;

	while (!validInput) {
		if (anInput == 1 || anInput == 2) {
			validInput = true;
			system(CLEAR_COMMAND);
		}
		else {
			cout << "Invalid Input. Please Enter Again: ";
			cin >> anInput;
		}
	}
	if (validInput == true) {
		switch (anInput) {
		case 1:
			displayUniList();
			break;
		case 2:
			mainMenu();
			break;
		}
	}
}

void mainMenu() {
	cout << endl;
	cout << " *****************************************************" << endl;
	cout << " *                                                   *" << endl;
	cout << " *         2023 QS World University Rankings         *" << endl;
	cout << " *         ---------------------------------         *" << endl;
	cout << " *                                                   *" << endl;
	cout << " *              1 - Sign In as Admin                 *" << endl;
	cout << " *              2 - Sign In as User                  *" << endl;
	cout << " *              3 - Account Registration             *" << endl;
	cout << " *              4 - Continue as Guest                *" << endl;
	cout << " *              5 - Exit System                      *" << endl;
	cout << " *                                                   *" << endl;
	cout << " *****************************************************" << endl;
	cout << endl;

	int anInput = 0;
	cout << "Select an Operation Number: ";
	cin >> anInput;
	bool validInput = false;
	
	//checking for input validation
	while (!validInput) {
		if (anInput >= 1 && anInput <= 5) {
			validInput = true;
			system(CLEAR_COMMAND);
		}
		else {
			cout << "Invalid Input. Please Enter Again: ";
			cin >> anInput;
		}
	}

	// switch case after verify input
	if (validInput == true) {
		switch (anInput) {
			case 1:
				adminMenu();
				break;
			case 2:
				userMenu();
				break;
			case 3:
				registerMenu();
				break;
			case 4:
				guestMenu();
				break;
			case 5:
				cout << "Exiting..." << endl;
				break;
		}
	}
}

int main() {
	mainMenu();
	return 0;
}