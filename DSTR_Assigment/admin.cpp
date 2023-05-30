#include "admin.hpp"

// Unused yet
void Admin::deleteInactiveUser() {
    // Get current time
    time_t now = time(0);
    //UserNode* current = AllUserList->head;
    UserNode* current = nullptr; //***
    while (current != nullptr) {
        // Get user last login time
        time_t lastLoginTime = current->LastLogin;
        double secondsSinceLastLogin = difftime(now, lastLoginTime);
        // A month
        if (secondsSinceLastLogin > 2592000) {
            cout << current->Username << endl;
            // delete the user
            // AllUserList->displayUserTree;
        }
        //current = current->NextUser;
    }
}

// DeleteInactive no yet
bool Admin::login() {
    // Obtain username and password input
    string username, password;
    cout << "Please enter admin username: ";
    cin.ignore();
    getline(cin, username);
    cout << "Please enter admin password: ";
    getline(cin, password);

    // Check if username and password are correct
    if (username == "a" && password == "q") {
        // Delete inactive user after login
        // deleteInactiveUser();
        return true;
    }
    else {
        return false;
    }
}

void Admin::displayUserList() {
    UserList::displayUserList(); // Call displayUserList from userlist
}
