#include "favouriteUni_class.hpp"

FavouriteUnilist* AllFavouriteUnilist = NULL;

// Change to Doubly ( NOT YET INPLEMENT) - BETTER deletion

UserFavouriteUni* FavouriteUnilist::createNewFavouriteUni(string UserID, string UniID) {
    // Create a new FeedbackNode
    UserFavouriteUni* newFavouriteUni = new UserFavouriteUni();
    newFavouriteUni->UserID = UserID;
    newFavouriteUni->UniID = UniID;
    newFavouriteUni->favoriteCount = NULL;
    newFavouriteUni->NextUni = NULL;

    return newFavouriteUni;
}

// Check if the favourite uni is added to the list or not? if no, not able to add
UserFavouriteUni* FavouriteUnilist::getFavouriteUni(string UserID, string UniID) { return 0; }

// Check if the node already exists in the list
void FavouriteUnilist::insertIntoFavouriteUni(string UserID, string UniID, bool isReportList) {
    // Create a new FeedbackNode
    UserFavouriteUni* newFavouriteUni = createNewFavouriteUni(UserID, UniID);

    if (isReportList) {
        newFavouriteUni->favoriteCount = 1;
    }
    else {
        insertIntoAllFavouriteList(newFavouriteUni);
    }

    // If the list is empty, set the new node as the head and tail
    if (head == NULL) {
        head = newFavouriteUni;
        tail = newFavouriteUni;
    }
    // Otherwise, insert the new node at the end of the list
    else {
        tail->NextUni = newFavouriteUni;
        newFavouriteUni->PrevUni = tail;
        tail = newFavouriteUni;
    }
    cout << "Head " << head << " FOR " << UserID << endl;
    cout << "Tail " << tail << " FOR " << UserID << endl << endl;

}

void FavouriteUnilist::insertIntoAllFavouriteList(UserFavouriteUni* newFavouriteUni) {
    if (AllFavouriteUnilist == NULL) {
        AllFavouriteUnilist = new FavouriteUnilist;
    }

    // If the list is empty, set the new node as the head and tail
    if (AllFavouriteUnilist->head == NULL) {
        AllFavouriteUnilist->head = newFavouriteUni;
        AllFavouriteUnilist->tail = newFavouriteUni;
    }
    // Otherwise, insert the new node at the end of the list
    else {
        AllFavouriteUnilist->tail->NextUni = newFavouriteUni;
        AllFavouriteUnilist->tail = AllFavouriteUnilist->tail->NextUni;
    }

    /*cout << "ALLFU" << endl;
    cout << "Head " << AllFavouriteUnilist->head << endl;
    cout << "Tail " << AllFavouriteUnilist->tail << endl << endl;*/
}

void FavouriteUnilist::displayALL() {
    UserFavouriteUni* currentUni = AllFavouriteUnilist->head;
    int count = 0;
    while (currentUni != NULL) {
        cout << "User ID: " << currentUni->UserID << endl;
        cout << "Uni ID: " << currentUni->UniID << endl;
        //cout << "Create Time: " << ctime(&currentFeedback->CreateTime);
        count++;
        currentUni = currentUni->NextUni;
    }
    if (count == 0) {
        cout << "No favourite uni found for the user" << endl;
    }
}

// Not yet
void FavouriteUnilist::removeFavouriteUni(string UserID, string UniID) {}

FavouriteUnilist* FavouriteUnilist::generateFavouriteUniRecord() {
    FavouriteUnilist* TopFavouriteList = new FavouriteUnilist();

    // Traverse through the AllFavouriteUnilist
    UserFavouriteUni* currentUni = AllFavouriteUnilist->head;
    while (currentUni != NULL) {

        // Check if this uni is already in the TopFavouriteList
        UserFavouriteUni* uniInTopList = TopFavouriteList->head;
        UserFavouriteUni* prevUniInTopList = NULL;
        bool uniFoundInTopList = false;
        while (uniInTopList != NULL) {
            if (uniInTopList->UniID == currentUni->UniID) {
                uniFoundInTopList = true;
                break;
            }
            prevUniInTopList = uniInTopList;
            uniInTopList = uniInTopList->NextUni;
        }

        // If uni is not in the TopFavouriteList, add it with favoriteCount 1
        if (!uniFoundInTopList) {
            UserFavouriteUni* newUni = createNewFavouriteUni("", currentUni->UniID);
            newUni->favoriteCount = 1;
            TopFavouriteList->insertIntoFavouriteUni("", newUni->UniID, true);
        }
        // If uni is already in the TopFavouriteList, update its favoriteCount
        else {
            uniInTopList->favoriteCount++;
            // If uni is not already at the head of the TopFavouriteList and its
            // favoriteCount is greater than the previous node, move it to the head
            if (prevUniInTopList != NULL && uniInTopList->favoriteCount > prevUniInTopList->favoriteCount) {
                // Remove uni from its current position in the list
                prevUniInTopList->NextUni = uniInTopList->NextUni;
                // Add uni to the head of the list
                uniInTopList->NextUni = TopFavouriteList->head;
                TopFavouriteList->head = uniInTopList;
                // If uni was at the tail, update tail pointer
                if (uniInTopList == TopFavouriteList->tail) {
                    TopFavouriteList->tail = prevUniInTopList;
                }
            }
        }

        currentUni = currentUni->NextUni;
    }
    return TopFavouriteList;
}