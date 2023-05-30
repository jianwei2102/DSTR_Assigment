#include "user.hpp"


UserNode* UserList::createNewUserNode(string Username, string Email, string Password)
{
    UserNode* newUser = new UserNode();

    newUser->leftUser = nullptr;
    newUser->rightUser = nullptr;
    newUser->parent = nullptr;
    newUser->Username = Username;
    newUser->Email = Email;
    newUser->Password = Password;
    newUser->color = 'R';
    newUser->LastLogin = time(0);
    /*newUser->FavouriteUniList = new FavouriteUnilist();
    newUser->FeedbackList = new Feedbacklist();*/
    newUser->UserID = to_string(rand());

    return newUser;
}

void UserList::leftRotate(UserNode* node)
{
    UserNode* y = node->rightUser; // Set y
    node->rightUser = y->leftUser; // Turn y's left subtree into node's right subtree

    if (y->leftUser != this->nullNode)
    {
        y->leftUser->parent = node;
    }

    y->parent = node->parent;

    if (node->parent == nullptr)
    {
        this->root = y;
    }
    else if (node == node->parent->leftUser)
    {
        node->parent->leftUser = y;
    }
    else
        node->parent->rightUser = y;

    y->leftUser = node;
    node->parent = y;
}

void UserList::rightRotate(UserNode* node) {
    UserNode* y = node->leftUser;
    node->leftUser = y->rightUser;
    if (y->rightUser != this->nullNode) {
        y->rightUser->parent = node;
    }
    y->parent = node->parent;
    if (node->parent == nullptr) {
        this->root = y;
    }
    else if (node == node->parent->rightUser) {
        node->parent->rightUser = y;
    }
    else {
        node->parent->leftUser = y;
    }
    y->rightUser = node;
    node->parent = y;
}

void UserList::inorder(UserNode* root) {
    if (root != this->nullNode) {
        inorder(root->leftUser);
        cout << root->Username << " " << endl;
        inorder(root->rightUser);
    }
}

void UserList::insertIntoUserTree(string Username, string Email, string Password)
{

    //if (AllUserList == NULL) {
    //    AllUserList = new UserList;
    //}

    UserNode* newUser = createNewUserNode(Username, Email, Password);
    newUser->leftUser = this->nullNode;
    newUser->rightUser = this->nullNode;

    UserNode* y = nullptr;
    UserNode* x = this->root;

    while (x != this->nullNode)
    {
        y = x;

        if (newUser->Username.compare(x->Username) < 0)
        {
            x = x->leftUser;
        }
        else
            x = x->rightUser;
    }

    newUser->parent = y;

    if (y == nullptr)
    {
        this->root = newUser;
    }
    else if (newUser->Username.compare(y->Username) < 0)
        y->leftUser = newUser;
    else
        y->rightUser = newUser;


    if (newUser->parent == nullptr) {
        newUser->color = 'B';
        return;
    }

    // if the grandparent is null, simply return
    if (newUser->parent->parent == nullptr) {
        return;
    }

    //newUser->leftUser = this->nullNode;
    //newUser->rightUser = this->nullNode;
    //newUser->color = 'R';
    //newUser->color = 'R';
    insertFixup(newUser);
}


void UserList::insertIntoUserTree(UserNode* newUser) {
    newUser->leftUser = this->nullNode;
    newUser->rightUser = this->nullNode;
    newUser->parent = nullptr;
    newUser->color = 'R';

    UserNode* y = nullptr;
    UserNode* x = this->root;

    while (x != this->nullNode)
    {
        y = x;

        if (newUser->Username.compare(x->Username) < 0)
        {
            x = x->leftUser;
        }
        else
            x = x->rightUser;
    }

    newUser->parent = y;

    if (y == nullptr)
    {
        this->root = newUser;
    }
    else if (newUser->Username.compare(y->Username) < 0)
        y->leftUser = newUser;
    else
        y->rightUser = newUser;


    if (newUser->parent == nullptr) {
        newUser->color = 'B';
        return;
    }

    // if the grandparent is null, simply return
    if (newUser->parent->parent == nullptr) {
        return;
    }

    //newUser->leftUser = this->nullNode;
    //newUser->rightUser = this->nullNode;
    //newUser->color = 'R';

    insertFixup(newUser);
}


void UserList::insertFixup(UserNode* node)
{
    UserNode* y;


    while (node->parent && node->parent->color == 'R')
    {
        if (node->parent == node->parent->parent->leftUser)
        {
            y = node->parent->parent->rightUser;

            if (y->color == 'R')
            {
                node->parent->color = 'B';
                y->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            }

            else
            {
                if (node == node->parent->rightUser)
                {
                    node = node->parent;
                    leftRotate(node);
                }

                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                rightRotate(node->parent->parent);
            }

        }

        else {
            y = node->parent->parent->leftUser;

            if (y->color == 'R')
            {
                node->parent->color = 'B';
                y->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->leftUser)
                {
                    node = node->parent;
                    rightRotate(node);
                }

                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                leftRotate(node->parent->parent);
            };
        }

        if (node == this->root)
            break;
    }

    this->root->color = 'B';
}

void UserList::transplant(UserNode* u, UserNode* v)
{
    if (u->parent == nullptr)
    {
        this->root = v;
    }

    else if (u == u->parent->leftUser)
    {
        u->parent->leftUser = v;
    }

    else
        u->parent->rightUser = v;

    v->parent = u->parent;
}

void UserList::displayUserTree(UserNode* root, string indent, bool last)
{
    if (root)
    {
        if (root != nullNode) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "     ";
            }
            else {
                cout << "L----";
                indent += "|    ";
            }

            string sColor = root->color == 'R' ? "RED" : "BLACK";
            cout << root->Username << "(" << sColor << ")" << endl;
            displayUserTree(root->leftUser, indent, false);
            displayUserTree(root->rightUser, indent, true);
        }
    }
}

void UserList::deleteNode(string searchKey)
{
    UserNode* y;
    UserNode* x;

    UserNode* target = searchUser(searchKey);


    if (target == this->nullNode)
    {
        cout << "User does not exist";
        return;
    }

    y = target;
    char y_original_color = y->color;

    if (target->leftUser == this->nullNode)
    {
        x = target->rightUser;
        transplant(target, target->rightUser);
    }
    else if (target->rightUser == this->nullNode)
    {
        x = target->leftUser;
        transplant(target, target->leftUser);
    }
    else
    {
        y = minimum(target->rightUser);
        y_original_color = y->color;
        x = y->rightUser;

        if (y->parent == target)
        {
            x->parent = y;
        }
        else
        {
            transplant(y, y->rightUser);
            y->rightUser = target->rightUser;
            y->rightUser->parent = y;
        }

        transplant(target, y);
        y->leftUser = target->leftUser;
        y->leftUser->parent = y;
        y->color = target->color;
    }

    if (y_original_color == 'B')
    {
        deleteFixup(x);
    }
}

void UserList::deleteFixup(UserNode* x)
{
    UserNode* s;

    while (x != root && x->color == 'B') {
        if (x == x->parent->leftUser) {
            s = x->parent->rightUser;
            if (s->color == 'R') {
                // case 3.1
                s->color = 'B';
                x->parent->color = 'R';
                leftRotate(x->parent);
                s = x->parent->rightUser;
            }

            if (s->leftUser->color == 'B' && s->rightUser->color == 'B') {
                // case 3.2
                s->color = 'R';
                x = x->parent;
            }
            else {
                if (s->rightUser->color == 'B') {
                    // case 3.3
                    s->leftUser->color = 'B';
                    s->color = 'R';
                    rightRotate(s);
                    s = x->parent->rightUser;
                }

                // case 3.4
                s->color = x->parent->color;
                x->parent->color = 'B';
                s->rightUser->color = 'B';
                leftRotate(x->parent);
                x = root;
            }
        }
        else {
            s = x->parent->leftUser;
            if (s->color == 'R') {
                // case 3.1
                s->color = 'B';
                x->parent->color = 'R';
                rightRotate(x->parent);
                s = x->parent->leftUser;
            }

            if (s->rightUser->color == 'B' && s->rightUser->color == 'B') {
                // case 3.2
                s->color = 'R';
                x = x->parent;
            }
            else {
                if (s->leftUser->color == 'B') {
                    // case 3.3
                    s->rightUser->color = 'B';
                    s->color = 'R';
                    leftRotate(s);
                    s = x->parent->leftUser;
                }

                // case 3.4
                s->color = x->parent->color;
                x->parent->color = 'B';
                s->leftUser->color = 'B';
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 'B';
}

UserNode* UserList::searchUser(string searchKey)
{
    UserNode* x = this->root;

    while (x != this->nullNode && searchKey != x->Username)
    {
        if (searchKey.compare(x->Username) < 0)
            x = x->leftUser;
        else
            x = x->rightUser;
    }

    return x;
}

UserNode* UserList::searchUserByEmail(string searchKey)
{
    UserNode* x = this->root;

    while (x != this->nullNode && searchKey != x->Email)
    {
        if (searchKey.compare(x->Email) < 0)
            x = x->leftUser;
        else
            x = x->rightUser;
    }
    return x;
}

UserNode* UserList::minimum(UserNode* node)
{
    while (node->leftUser != this->nullNode)
        node = node->leftUser;

    return node;
}

UserNode* UserList::getRoot()
{
    return this->root;
}

UserNode* UserList::login(string Username, string Password) {
    // Traverse the list to find a matching user
    UserNode* currentUser = searchUser(Username);

    if (currentUser->Username == Username && currentUser->Password == Password) {
        currentUser->LastLogin = time(0); // update last login time
        return currentUser;
    }
    // If no matching user is found, return NULL
    return NULL;
}

//void UserList::addFavouriteUniToUser(UserNode* User, string UniID) {
//    if (!User) {
//        cout << "Error: User node is null." << endl;
//        return;
//    }
//
//    User->FavouriteUniList->insertIntoFavouriteUni(User->UserID, UniID, false);
//}

//// Add on show uni details
//void UserList::showOwnFavoriteUni(UserNode* User) {
//    if (User == NULL) {
//        cout << "User not found" << endl;
//        return;
//    }
//
//    UserFavouriteUni* currentUni = User->FavouriteUniList->head;
//    int count = 0;
//    while (currentUni != NULL) {
//        cout << "User ID: " << currentUni->UserID << endl;
//        cout << "Uni ID: " << currentUni->UniID << endl;
//        count++;
//        currentUni = currentUni->NextUni;
//    }
//    if (count == 0) {
//        cout << "No favourite uni found for the user" << endl;
//    }
//}

//void UserList::addFeedbackToUser(UserNode* User, const string& Feedback) {
//    if (!User) {
//        cout << "Error: User node is null." << endl;
//        return;
//    }
//
//    User->FeedbackList->insertIntoFeedbackList(User, Feedback);
//}

//void UserList::showOwnFeedback(UserNode* User) {
//
//
//    UserNode* currentUser = searchUser(User->Username);
//
//    if (User->UserID == "") {
//        cout << "User not found" << endl;
//        return;
//    }
//
//    //UserNode* currentUser = AllUserList->head;
//    if (currentUser->UserID == User->UserID) {
//        FeedbackNode* currentFeedback = currentUser->FeedbackList->head;
//        int count = 0;
//        while (currentFeedback != NULL) {
//            if (currentFeedback->UserID == User->UserID) {
//                cout << "Feedback ID: " << currentFeedback->FeedbackID << endl;
//                cout << "Feedback: " << currentFeedback->Feedback << endl;
//                ReplyNode* currentReply = currentFeedback->ReplyList->head;
//
//                if (currentReply == NULL) {
//                    cout << "There is no reply yet" << endl;
//                }
//                else {
//                    while (currentReply != NULL) {
//                        cout << "Replied by " << currentReply->Username << ": " << currentReply->Reply << endl;
//                        currentReply = currentReply->NextReply;
//                    }
//                }
//
//
//                //cout << "Create Time: " << ctime(&currentFeedback->CreateTime);
//                count++;
//            }
//            currentFeedback = currentFeedback->NextFeedback;
//        }
//        if (count == 0) {
//            cout << "No feedback found for the user" << endl;
//        }
//    }
//
//    if (currentUser == NULL) {
//        cout << "User not found" << endl;
//    }
//}

//void UserList::insertReplyIntoFeedbackNode(string FeedbackID, UserNode* User, const string& Reply) {
//    // Get feedback node for both all feedback list and user feedback list
//    FeedbackNode* currentAllFeedback = AllFeedbackLists->getFeedbackNode(FeedbackID);
//    FeedbackNode* currentFeedback = User->FeedbackList->getFeedbackNode(FeedbackID);
//    // Validation on the feedback node
//    if (currentFeedback == NULL || currentAllFeedback == NULL) {
//        cout << "Error: Feedback not found" << endl;
//        return;
//    }
//    // Insert to both feedback node
//    currentAllFeedback->ReplyList->insertReplyIntoFeedback(User->Username, Reply);
//    currentFeedback->ReplyList->insertReplyIntoFeedback(User->Username, Reply);
//}

void UserList::displayUserList() {
    // Print table header
    system("cls");
    cout << "User List" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(17) << "| UserID";
    cout << left << setw(20) << "Username";
    cout << left << setw(30) << "Email";
    cout << left << setw(25) << "Last Login" << right << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    // Call helper function to recursively display user tree
    displayUser(root, "");
    cout << "---------------------------------------------------------------------------------------------" << endl;
}
void UserList::displayUser(UserNode* root, string indent) {
    if (root != nullptr && root != nullNode)
    {
        // Print current user node
        cout << "| ";
        cout << left << setw(15) << root->UserID;
        cout << left << setw(20) << root->Username;
        cout << left << setw(30) << root->Email;

        time_t lastLoginTime = root->LastLogin;
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &lastLoginTime);
        buffer[24] = '\0';  // Remove the newline character from the output

        cout << left << setw(15) << buffer << " |" << endl;

        // Recursively display left and right subtrees
        displayUser(root->leftUser, indent + "  |");
        displayUser(root->rightUser, indent + "  ");
    }
}

void UserList::displayLoginUser(UserNode* user) {

    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(17) << "| UserID";
    cout << left << setw(20) << "Username";
    cout << left << setw(30) << "Email";
    cout << left << setw(25) << "Last Login" << right << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    // Print current user 
    cout << "| ";
    cout << left << setw(15) << user->UserID;
    cout << left << setw(20) << user->Username;
    cout << left << setw(30) << user->Email;

    time_t lastLoginTime = user->LastLogin;
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &lastLoginTime);
    buffer[24] = '\0';  // Remove the newline character from the output

    cout << left << setw(15) << buffer << " |" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

}


UserNode* UserList::getLoginUser() {
    return this->loginUser;
}

void UserList::setLoginUser(UserNode* loginUser) {
    this->loginUser = loginUser;
}
