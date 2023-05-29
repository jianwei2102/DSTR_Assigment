#pragma once

#include <string>

#include "user.hpp"

using namespace std;

struct addPredefinedUser {
	static UserList* addUser() {
		UserList* list = new UserList();

		list->insertIntoUserTree("JianWei", "jianwei@gmail.com", "jw1234");
		list->insertIntoUserTree("Alice", "alice@gmail.com", "Alice123");
		list->insertIntoUserTree("Bob", "bob@gmail.com", "qwerty");
		list->insertIntoUserTree("C", "ac@gmail.com", "ac");

		return list;
	}
};