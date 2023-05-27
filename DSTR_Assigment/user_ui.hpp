#pragma once

#include "feedback_class.hpp"
#include <iostream>
#include <string>
using namespace std;


class UserUI {

public:
	int displayMainMenu();

	string displayUsername();

	string displayPassword();

	string displayEmail();

	int displayUniMenu();
};