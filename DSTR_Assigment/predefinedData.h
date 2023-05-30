#pragma once

#include "Repository.h"
#include "loadUniCSV.h"
#include "addUser.h"

using namespace std;

struct predefinedData
{
	static void loadData() {
		Repository* repository = repository->getInstance();
		repository->AllUniList = loadUniCSV::ReadUniFromFile();
		repository->AllUserList = addPredefinedUser::addUser();
		HashMap FavUniCount = repository->FavUniCount;

		// FavUniCount.displaySortedUnis();
	}
};