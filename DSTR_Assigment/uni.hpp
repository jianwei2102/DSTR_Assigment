#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct UniNode {
    string UniID, Insitution, LocationCode, Location;
    double ArScore, ErScore, FsrScore, CpfScore, IfrScore, IsrScore, IrnScore, GerScore, ScoreScaled;
    int Rank, ArRank, ErRank, FsrRank, CpfRank, IfrRank, IsrRank, IrnRank, GerRank;
};

class UniList {
public:
    UniNode* UniArray[1422];
    UniNode* createNewUniNode(int Rank, string Insitution, string LocationCode, string Location, double ArScore, int ArRank,
        double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank,
        double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled);

    void insertIntoUniList(int Rank, string Insitution, string LocationCode, string Location, double ArScore, int ArRank,
        double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank,
        double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled);

    void linearSearching(string SearchType, string SearchData);

    void binarySearching(string SearchType, string SearchData);

    void quickSort(UniNode* array[], string sortType);
    void displayUniList();
    void displayUni();

    UniNode* getUniNode(string UniID);
};