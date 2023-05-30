#pragma once

#include <string>

#include "user.hpp"
#include "repository.h"

using namespace std;

struct addPredefinedUser {
	static UserList* addUser() {
		Repository* r = Repository::getInstance();
		UserList* list = new UserList();

		// Insert user to user list
		list->insertIntoUserTree("Jian", "jianwei@gmail.com", "jw1234");
		list->insertIntoUserTree("Alice", "alice@gmail.com", "Alice123");
		list->insertIntoUserTree("Bob", "bob@gmail.com", "qwerty");
		list->insertIntoUserTree("C", "ac@gmail.com", "ac");

		// Login alice
		UserNode* alice = list->login("Alice", "Alice123");
		
		// Create some feedback for Alice
		list->addFeedbackToUser(alice, "This is my feedback");
		list->addFeedbackToUser(alice, "This is my second feedback");

		// Add some favourite uni for Alice
		list->addFavouriteUniToUser(alice, "UNI0008");
		list->addFavouriteUniToUser(alice, "UNI0016");
		list->addFavouriteUniToUser(alice, "UNI0212");
		list->removeFavouriteUniFromUser(alice, "UNI0008");

		// Logout alice
		r->loginUser = NULL;

		// Login alice
		UserNode* bob = list->login("Bob", "qwerty");

		// Create some feedback for bob
		list->addFeedbackToUser(bob, "Test");
		list->addFeedbackToUser(bob, "Test2");

		// Add some favourite uni for bob
		list->addFavouriteUniToUser(bob, "UNI0918");
		list->addFavouriteUniToUser(bob, "UNI0212");

		// Logout bob
		r->loginUser = NULL;

		return list;
	}
};