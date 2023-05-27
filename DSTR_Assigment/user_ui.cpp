#include "user_ui.hpp"
#include "user_class.hpp"
#include <conio.h>
#include <iostream>
using namespace std;

int UserUI::displayMainMenu()
{
	int input;
	cout << endl << "1. View Universities" << endl << "2. View Inbox" << endl << "3. View Profile" << endl << "4. Log Out" << endl;
	cout << "Please enter your choice: ";
	cin >> input;
	
	return input;
}

string UserUI::displayUsername()
{
	string username;
	
	cout << "Please enter your username: ";
	getline(cin, username);

	return username;
}

string UserUI::displayPassword()
{
	string password;

	cout << "Please enter your password: ";
	getline(cin, password);

	return password;
}

string UserUI::displayEmail()
{
	string email;

	cout << "Please enter your email: ";
	getline(cin, email);

	cout << endl;
	return email;
}

int UserUI::displayUniMenu() {

	int input;

	cout << "1. Search Universities" << endl << "2. Sort Universities" << endl << "3. Save Favorite" << endl;
	cout << "4. Default Order" << endl << "5. Show Favorite" << endl << "Remove Favorite" << endl;

	cout << "Please enter your choice: ";
	cin >> input;

	return input;
}