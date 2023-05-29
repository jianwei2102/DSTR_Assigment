#include "uni.hpp"

UniNode* UniList::createNewUniNode(int Rank, string Insitution, string LocationCode, string Location, double ArScore, int ArRank,
    double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank,
    double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled) {

    UniNode* newUniNode = new UniNode;
    string UniID = to_string(Rank);
    UniID = string(4 - UniID.length(), '0') + UniID;
    newUniNode->UniID = "UNI" + UniID;
    newUniNode->Rank = Rank;
    newUniNode->Insitution = Insitution;
    newUniNode->LocationCode = LocationCode;
    newUniNode->Location = Location;
    newUniNode->ArScore = ArScore;
    newUniNode->ArRank = ArRank;
    newUniNode->ErScore = ErScore;
    newUniNode->ErRank = ErRank;
    newUniNode->FsrScore = FsrScore;
    newUniNode->FsrRank = FsrRank;
    newUniNode->CpfScore = CpfScore;
    newUniNode->CpfRank = CpfRank;
    newUniNode->IfrScore = IfrScore;
    newUniNode->IfrRank = IfrRank;
    newUniNode->IsrScore = IsrScore;
    newUniNode->IsrRank = IsrRank;
    newUniNode->IrnScore = IrnScore;
    newUniNode->IrnRank = IrnRank;
    newUniNode->GerScore = GerScore;
    newUniNode->GerRank = GerRank;
    newUniNode->ScoreScaled = ScoreScaled;

    return newUniNode;
}

void UniList::insertIntoUniList(int Rank, string Insitution, string LocationCode, string Location, double ArScore, int ArRank,
    double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank,
    double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled) {

    UniNode* newnode = createNewUniNode(Rank, Insitution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore,
        FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled);

    UniArray[Rank - 1] = newnode;
}

void UniList::linearSearching(string SearchType, string SearchData) {}

void UniList::binarySearching(string SearchType, string SearchData) {}

void UniList::displayUniList() {
    int section = 20;
    int record = 0;
    int min = 0;

    while (true) {
        
        // Find min 
        if (record + section > size(UniArray)) {
            min = size(UniArray);
        }
        else {
            min = record + section;
        }

        system("cls");
        cout << "  --------------------------------------------------------------- " << endl;
        cout << " |                      University List                          |" << endl;
        cout << "  --------------------------------------------------------------- " << endl;

        for (; record < min; record++) {
            cout << UniArray[record]->UniID << ": " << UniArray[record]->Insitution << endl;
        }

        if (min == size(UniArray)) {
            cout << endl << "You have reach the end the uni list" << endl;
        }
        string input;
        cout << endl << "Do you want to display the next 20 records (Y/N): ";
        cin >> input;

        if (input == "Y" || input == "y") {
            continue;
        }
        else {
            break;
        }
    }
    return;
}

UniNode* UniList::getUniNode(string UniID) { return 0; }