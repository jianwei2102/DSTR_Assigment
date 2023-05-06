#include <iostream>
#include "read_file.hpp"
#include "uni_class.hpp"
#include "admin_class.hpp"
#include "favouriteUni_class.hpp"
#include "feedback_class.hpp"
#include "reply_class.hpp"
#include "user_class.hpp"
using namespace std;

int main() {
    // Display uni
    UniList list = ReadUniFromFile();
    //list.displayUniList();

    // Create a UserList object
    UserList userList;

    // Insert some users into the list
    userList.insertIntoUserList("Alice", "alice@gmail.com","Alice123");
    userList.insertIntoUserList("Bob", "bob@gmail.com", "qwerty");
    userList.insertIntoUserList("C", "ac@gmail.com", "ac");
    // Get a user object from the list (in this case, Alice)
    UserNode* alice = userList.login("Alice", "Alice123");
    UserNode* bob = userList.login("Bob", "qwerty");
    UserNode* ac = userList.login("C", "ac");
    // Create some feedback from Alice
    //userList.addFeedbackToUser(alice, "This is my feedback");
    //userList.addFeedbackToUser(bob, "Test");
    //userList.addFeedbackToUser(alice, "This is my second feedback");
   
   
    //userList.addFeedbackToUser(bob, "Test 2");
    //userList.addFeedbackToUser(alice, "This is my third feedback");
    //userList.insertReplyIntoFeedbackNode("26500", alice, "This is my reply"); // 41, 6334
    //userList.insertReplyIntoFeedbackNode("26500", alice, "This is my second reply"); // 41, 6334
    //cout << endl << "Show alice" << endl;
    //userList.showOwnFeedback(alice);
    //cout << endl << "Show bob" << endl;
    //userList.showOwnFeedback(bob);


    // Create some uni fav from Alice
    userList.addFavouriteUniToUser(alice, "UNI05");
    userList.addFavouriteUniToUser(alice, "UNI031");
    userList.addFavouriteUniToUser(ac, "UNI03");
    userList.addFavouriteUniToUser(alice, "UNI03");
    userList.addFavouriteUniToUser(alice, "UNI03");
    userList.addFavouriteUniToUser(bob, "UNI031");
    userList.addFavouriteUniToUser(bob, "UNI021");
    userList.addFavouriteUniToUser(bob, "UNI021");
    cout << endl << "Show Alice" << endl;
    userList.showOwnFavoriteUni(alice);
    cout << endl << "Show Ac" << endl;
    userList.showOwnFavoriteUni(ac);
    cout << endl << "Show Bob" << endl;
    userList.showOwnFavoriteUni(bob);

    cout << endl << endl << "ADMIN HERE" << endl;
    Admin admin;
    /*admin.login("admin", "admin123");
    admin.viewUserFeedbackList();
    admin.insertReplyIntoFeedbackNode("26500", "Admin", "This is reply from admin");*/
    admin.generateReport();
    //admin.displayUserList();
    /*admin.modifyUserDetail("41", "Password", "test321");
    admin.displayUserList();
    
    admin.viewUserFeedbackList();*/
    //userList.showOwnFeedback(alice);
	return 0;
}