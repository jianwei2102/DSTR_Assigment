#include "favUni.hpp"
#include "repository.h"


UserFavouriteUni* FavouriteUnilist::createNewFavouriteUni(string UserID, string UniID) {
    // Create a new FeedbackNode
    UserFavouriteUni* newFavouriteUni = new UserFavouriteUni();
    newFavouriteUni->UserID = UserID;
    newFavouriteUni->UniID = UniID;
    newFavouriteUni->favoriteCount = NULL;
    newFavouriteUni->NextUni = NULL;
    newFavouriteUni->PrevUni = NULL;
    return newFavouriteUni;
}

// Check if the favourite uni is added to the list
UserFavouriteUni* FavouriteUnilist::getFavouriteUni(string UserID, string UniID) { 
    Repository* r = Repository::getInstance();

    FavouriteUnilist* favouriteUniList = r->loginUser->FavouriteUniList;
    if (favouriteUniList == NULL)
    {
        return NULL;
    }
    UserFavouriteUni* currentUni = favouriteUniList->head;
    while (currentUni != NULL)
    {
        if (currentUni->UserID == UserID && currentUni->UniID == UniID)
        {
            return currentUni;
        }
        currentUni = currentUni->NextUni;
    }

    return NULL;
}

// Check if the node already exists in the list
void FavouriteUnilist::insertIntoFavouriteUni(string UserID, string UniID, bool isReportList) {
    
    UserFavouriteUni* exist = getFavouriteUni(UserID, UniID);

    if (exist)
    {
        cout << "The university is already in your favorite list" << endl;
        return;
    }

    // Create a new FeedbackNode
    UserFavouriteUni* newFavouriteUni = createNewFavouriteUni(UserID, UniID);

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

    insertIntoAllFavouriteList(newFavouriteUni);
}

void FavouriteUnilist::insertIntoAllFavouriteList(UserFavouriteUni* newFavouriteUni) {
    Repository* r = Repository::getInstance();
    r->FavUniCount.insert(newFavouriteUni->UniID);

    //if (AllFavouriteUnilist == NULL) {
    //    AllFavouriteUnilist = new FavouriteUnilist;
    //}

    //// If the list is empty, set the new node as the head and tail
    //if (AllFavouriteUnilist->head == NULL) {
    //    AllFavouriteUnilist->head = newFavouriteUni;
    //    AllFavouriteUnilist->tail = newFavouriteUni;
    //}
    //// Otherwise, insert the new node at the end of the list
    //else {
    //    AllFavouriteUnilist->tail->NextUni = newFavouriteUni;
    //    AllFavouriteUnilist->tail = AllFavouriteUnilist->tail->NextUni;
    //}
}
//
//// TESTING ONLY
//void FavouriteUnilist::displayALL() {
//    UserFavouriteUni* currentUni = AllFavouriteUnilist->head;
//    int count = 0;
//    while (currentUni != NULL) {
//        cout << "User ID: " << currentUni->UserID << endl;
//        cout << "Uni ID: " << currentUni->UniID << endl;
//        //cout << "Create Time: " << ctime(&currentFeedback->CreateTime);
//        count++;
//        currentUni = currentUni->NextUni;
//    }
//    if (count == 0) {
//        cout << "No favourite uni found for the user" << endl;
//    }
//}


void FavouriteUnilist::removeFavouriteUni(string UserID, string UniID) {
    UserFavouriteUni* exist = getFavouriteUni(UserID, UniID);
    cout << exist << endl;
    if (!exist)
    {
        cout << "The university is not in your favorite list" << endl;
        return;
    }

    // If the node to be deleted is the head node
    if (head == exist) {
        head = exist->NextUni;
    }

    // If the node to be deleted is the tail node
    if (tail == exist) {
        tail = exist->PrevUni;
    }

    // If the node to be deleted is not the last node, then we need to adjust the 'NextUni' of the next node
    if (exist->NextUni != NULL) {
        exist->NextUni->PrevUni = exist->PrevUni;
    }

    // If the node to be deleted is not the first node, then we need to adjust the 'PrevUni' of the previous node
    if (exist->PrevUni != NULL) {
        exist->PrevUni->NextUni = exist->NextUni;
    }

    delete exist;

    Repository* r = Repository::getInstance();
    r->FavUniCount.remove(UniID);
}
//
//FavouriteUnilist* FavouriteUnilist::generateFavouriteUniRecord() {
//    // Generate a new list for top favourite uni list
//    FavouriteUnilist* TopFavouriteList = new FavouriteUnilist();
//
//    // Traverse through the AllFavouriteUnilist
//    UserFavouriteUni* currentUni = AllFavouriteUnilist->head;
//    while (currentUni != NULL) {
//        // Check if this uni is already in the TopFavouriteList
//        UserFavouriteUni* uniInTopList = TopFavouriteList->head;
//        UserFavouriteUni* prevUniInTopList = NULL;
//        bool uniFoundInTopList = false;
//        while (uniInTopList != NULL) {
//            // If the uni already exist in the list
//            if (uniInTopList->UniID == currentUni->UniID) {
//                uniFoundInTopList = true;
//                break;
//            }
//            prevUniInTopList = uniInTopList;
//            uniInTopList = uniInTopList->NextUni;
//        }
//
//        // If uni is not in the TopFavouriteList, add it with favoriteCount of 1
//        if (!uniFoundInTopList) {
//            TopFavouriteList->insertIntoFavouriteUni("", currentUni->UniID, true);
//        }
//        // If uni is already in the TopFavouriteList, update its favoriteCount
//        else {
//            uniInTopList->favoriteCount++;
//            // If uni is not already at the head of the TopFavouriteList and its
//            // favoriteCount is greater than the previous node, move it to the head
//            if (prevUniInTopList != NULL && uniInTopList->favoriteCount > prevUniInTopList->favoriteCount) {
//                // Remove uni from its current position in the list
//                prevUniInTopList->NextUni = uniInTopList->NextUni;
//                // Add uni to the head of the list
//                uniInTopList->NextUni = TopFavouriteList->head;
//                TopFavouriteList->head = uniInTopList;
//                // If uni was at the tail, update tail pointer
//                if (uniInTopList == TopFavouriteList->tail) {
//                    TopFavouriteList->tail = prevUniInTopList;
//                }
//            }
//        }
//
//        currentUni = currentUni->NextUni;
//    }
//    return TopFavouriteList;
//}