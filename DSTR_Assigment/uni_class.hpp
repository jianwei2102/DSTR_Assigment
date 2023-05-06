#pragma once
#include <iostream>
#include <string>
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

    void mergeSort(UniNode* arr[], int l, int r);

    void merge(UniNode* arr[], int l, int m, int r);

    void quickSort(UniNode* UniArray[], int start, int end);

    int partition(UniNode* UniArray[], int start, int end);

    void swap(UniNode* UniArray[], int i, int j);

    void linearSearching(string SearchType, string SearchData);

    void binarySearching(string SearchType, string SearchData);

    void displayUniList();

    UniNode* getUniNode(string UniID);
};