#pragma once

#include <string>

#include "user.hpp"

using namespace std;

struct addPredefinedUser {
	static UserList* addUser() {
		UserList* list = new UserList();

		list->insertIntoUserTree("Jian", "jianwei@gmail.com", "jw1234");
		list->insertIntoUserTree("Alice", "alice@gmail.com", "Alice123");
		list->insertIntoUserTree("Bob", "bob@gmail.com", "qwerty");
		list->insertIntoUserTree("C", "ac@gmail.com", "ac");

		UserNode* alice = list->login("Alice", "Alice123");
		
		// Create some feedback from Alice
		list->addFeedbackToUser(alice, "This is my feedback");
		
		list->addFeedbackToUser(alice, "This is my second feedback");

		// Favourite uni
		list->addFavouriteUniToUser(alice, "UNI0008");
		list->addFavouriteUniToUser(alice, "UNI0016");
		list->removeFavouriteUniFromUser(alice, "UNI0008");
		// LOGOUT

		//UserNode* bob = list->login("Bob", "qwerty");
		//list->addFeedbackToUser(bob, "Test");
		return list;
	}
};