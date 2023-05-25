#include "uni_class.hpp"


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
    cout << size(UniArray) << endl;
    for (int i = 0; i < size(UniArray); i++) {
        cout << "Uni Name:" << UniArray[i]->Insitution << endl;
    }
    cout << "List is ended here!!" << endl;
    //cout << "Uni Name:" << UniArray[0]->UniID;
}

UniNode* UniList::getUniNode(string UniID) { return 0; }
