#include "user_controller.hpp"
#include <iostream>
using namespace std;

void UserController::loginHandler()
{

	while (true)
	{
		string username = this->userUI->displayUsername();
		string password = this->userUI->displayPassword();

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
		int input = this->userUI->displayMainMenu();

		if (input == 1) {
			this->universityHandler();
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
		input = this->userUI->displayUniMenu();

		if (input == 5)
		{
			this->userList->showOwnFavoriteUni(this->loginUser);
		}

	}


}


