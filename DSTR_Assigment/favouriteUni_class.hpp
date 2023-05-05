#pragma once
#include <iostream>
#include <string>
using namespace std;

// Change to Doubly ( NOT YET INPLEMENT) - BETTER deletion
struct UserFavouriteUni {
    string UserID, UniID;
    int favoriteCount;
    UserFavouriteUni* PrevUni;
    UserFavouriteUni* NextUni;
};

class FavouriteUnilist;
extern FavouriteUnilist* AllFavouriteUnilist;
class FavouriteUnilist {
public:
    UserFavouriteUni* head = NULL;
    UserFavouriteUni* tail = NULL;

    UserFavouriteUni* createNewFavouriteUni(string UserID, string UniID);

    UserFavouriteUni* getFavouriteUni(string UserID, string UniID);

    void insertIntoFavouriteUni(string UserID, string UniID, bool isReportList);

    void insertIntoAllFavouriteList(UserFavouriteUni* newFavouriteUni);

    void removeFavouriteUni(string UserID, string UniID);

    FavouriteUnilist* generateFavouriteUniRecord();

    void displayALL();
};