#pragma once


#include <iostream>
#include "user_ui.hpp"
#include "user_class.hpp"
#include <string>
using namespace std;


class UserController {

private:
	UserList* userList;
	UserUI* userUI;
	UserNode* loginUser;

public:

	UserController(UserList* userList, UserUI* userUI)
	{
		this->userList = userList;
		this->userUI = userUI;
		this->loginUser = nullptr;
	}
	
	void loginHandler();

	void mainMenuHandler();

	void registerHandler();

	void universityHandler();
};