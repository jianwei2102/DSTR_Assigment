#pragma once

#include <iostream>
#include <string>

using namespace std;

struct UserFavouriteUni {
    string UserID, UniID;
    UserFavouriteUni* PrevUni;
    UserFavouriteUni* NextUni;
};

class FavouriteUnilist {
public:
    UserFavouriteUni* head = NULL;
    UserFavouriteUni* tail = NULL;

    UserFavouriteUni* createNewFavouriteUni(string UserID, string UniID);

    UserFavouriteUni* getFavouriteUni(string UserID, string UniID);

    void insertIntoFavouriteUni(string UserID, string UniID);

    void insertIntoAllFavouriteList(UserFavouriteUni* newFavouriteUni);

    void removeFavouriteUni(string UserID, string UniID);

};