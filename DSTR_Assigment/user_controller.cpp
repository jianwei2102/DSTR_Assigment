#include <iostream>
#include "user_controller.hpp"
//#include "MergeSort.h"
//#include "QuickSort.h"
//#include "SortingArScore.h"
//#include "SortingErScore.h"

using namespace std;

void UserController::loginHandler()
{
	while (true)
	{
		cout << "Leave 1 or more fields blank to exit" << endl << endl;

		string username = this->userUI->displayUsername();
		string password = this->userUI->displayPassword();

		if (username.empty() || password.empty())
		{
			return;
		}

		UserNode* user = this->userList->login(username, password);

		if (user == NULL) {
			cout << "Invalid credentials" << endl;
			continue;
		}
		else if (user->Username == username && user->Password == password) {
			this->loginUser = user;
			break;
		}
		else if(user->Username == username && user->Password != password) {
			cout << "Invalid credentials" << endl;
			continue;
		}
	}
			
	this->mainMenuHandler();

}

void UserController::mainMenuHandler()
{

	cout << endl << "Welcome " << this->loginUser->Username << this->loginUser->UserID << endl;

	while (true)
	{
		cout << endl;
		int input = this->userUI->displayMainMenu();
		cout << endl;

		if (input == 1) {
			cout << endl;
			this->universityHandler();
		}
		else if (input == 2)
		{
			cout << endl;
			this->inboxHandler();
		}
		else if (input == 4)
		{
			this->loginUser == nullptr;
			return;
		}
	}
}

void UserController::registerHandler()
{


	string username;
	string password;
	string email;

	while (true)
	{
		username = this->userUI->displayUsername();
		password = this->userUI->displayPassword();
		email = this->userUI->displayEmail();

		if (username.empty() || password.empty() || email.empty())
		{
			cout << "One or more fields is empty" << endl;
			continue;
		}

		UserNode* newUser = this->userList->searchUserByUsername(username);

		if (!newUser->Username.empty())
		{
			cout << "Username has been taken" << endl;
			continue;
		}
		break;
	}


	this->userList->insertIntoUserTree(username, email, password);
	this->loginUser = this->userList->login(username, password);

	cout << "Welcome " << this->loginUser->Username << endl;
	this->mainMenuHandler();
}

void UserController::universityHandler() 
{
	int input;

	while (true)
	{
		cout << endl;
		input = this->userUI->displayUniMenu();


		if (input == 3)
		{
			cin.ignore();
			string uniID;

			cout << "Please enter the University ID you would like to add:   ";
			getline(cin, uniID);

			this->userList->addFavouriteUniToUser(this->loginUser, uniID);

		}
		else if (input == 5)
		{
			this->userList->showOwnFavoriteUni(this->loginUser);
		}
		else if (input == 6)
		{

			cin.ignore();
			string uniID;

			cout << "Please enter the University ID you would like to remove:   ";
			getline(cin, uniID);

			this->userList->removeFavouriteUniFromUser(this->loginUser, uniID);
		}

	}
}

void UserController::inboxHandler()
{
	//int input;

	while (true)
	{
		//cin.ignore();

		int input;
		cout << endl;
		input = this->userUI->displayInboxMenu();
		cin.ignore(); // ignore any '\n' left in the input buffer


		if (input == 1)
		{
			this->userList->showOwnFeedback(this->loginUser);

		}
		else if (input == 2)	
		{
			string feedback;

			while (true)
			{
				cout << "Please enter your feedback message (Type 'q' to quit): " << endl;

				std::getline(std::cin, feedback);

				if (!feedback.empty() || feedback == "q" || feedback == "Q")
					break;

				cout << "Blank feedback aren't allowed" << endl;

			}
			
			cout << feedback << endl;
			
			if (feedback == "q" || feedback == "Q")
				continue;

			this->userList->addFeedbackToUser(this->loginUser, feedback);
		}
		else if (input == 3)
		{

			//cin.ignore();
			
		}

	}
}

