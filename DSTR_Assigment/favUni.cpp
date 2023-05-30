#include "favUni.hpp"
#include "repository.h"


UserFavouriteUni* FavouriteUnilist::createNewFavouriteUni(string UserID, string UniID) {
    // Create a new FeedbackNode
    UserFavouriteUni* newFavouriteUni = new UserFavouriteUni();
    newFavouriteUni->UserID = UserID;
    newFavouriteUni->UniID = UniID;
    newFavouriteUni->NextUni = NULL;
    newFavouriteUni->PrevUni = NULL;
    return newFavouriteUni;
}

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

void FavouriteUnilist::insertIntoFavouriteUni(string UserID, string UniID) {
    
    UserFavouriteUni* exist = getFavouriteUni(UserID, UniID);

    if (exist)
    {
        cout << "The university is already in your favorite list" << endl;
        return;
    }

    // Create a new FavUni Node
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
}

void FavouriteUnilist::removeFavouriteUni(string UserID, string UniID) {
    UserFavouriteUni* exist = getFavouriteUni(UserID, UniID);
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