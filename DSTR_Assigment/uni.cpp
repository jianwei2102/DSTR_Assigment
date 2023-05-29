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

void UniList::quickSort(UniNode* array[], string sortType) {
    
}

void UniList::displayUniList() {
    int arraySize = size(UniArray);
    int section = 20;
    int min = 0;
    int startRecord = 0;

    while (true) {

        // Find min 
        if (startRecord + section > arraySize) {
            min = arraySize;
        }
        else {
            min = startRecord + section;
        }

        system("cls");
        cout << "  --------------------------------------------------------------- " << endl;
        cout << " |                      University List                          |" << endl;
        cout << "  --------------------------------------------------------------- " << endl;
        cout << left << setw(5) << "No.";
        cout << left << setw(8) << "UniID.";
        cout << left << setw(30) << "Insitution" << endl;

        for (; startRecord < min; startRecord++) {
            cout << left << setw(5) << startRecord + 1;
            cout << left << setw(8) << UniArray[startRecord]->UniID;
            cout << left << setw(30) << UniArray[startRecord]->Insitution << endl;
        }

        if (min == arraySize) {
            cout << endl << "You have reach the end the uni list" << endl;
        }

        string input;
        cout << endl << "pv - to display previous 20 records" << endl;
        cout << "nx - to display next 20 records" << endl;
        cout << "dt - to display the detials on one uni" << endl;
        cout << "Enter any other key to exit: ";
        cin >> input;

        if (input == "nx" || input == "NX") {
            // Move to the next set of records
            continue;
        }
        else if (input == "pv" || input == "PV") {
            cout << "1" << startRecord << endl;
            startRecord -= section * 2; // Move to the previous set of records
            if (startRecord < 0) {
                startRecord = 0; // Ensure the startRecord doesn't go below 0
            }
        }
        else if (input == "dt" || input == "DT") {
            displayUni();
            startRecord -= section;
        }
        else {
            break; // Exit the loop if the user enters any other key
        }
    }
    return;
}

void UniList::displayUni() {
    int id;
    cout << "Enter the uni no. (not ID): ";
    cin.ignore();
    cin >> id;
    id -= 1;
    system("cls");
    cout << "University's Detail" << endl;
    cout << "Rank: " << UniArray[id]->Rank << endl;
    cout << "University ID: " << UniArray[id]->UniID << endl;
    cout << "Institution: " << UniArray[id]->Insitution << endl;
    cout << "Location Code: " << UniArray[id]->LocationCode << endl;
    cout << "Location: " << UniArray[id]->Location << endl;
    cout << "Ar Score: " << UniArray[id]->ArScore << endl;
    cout << "Ar Rank: " << UniArray[id]->ArRank << endl;
    cout << "Er Score: " << UniArray[id]->ErScore << endl;
    cout << "Er Rank: " << UniArray[id]->ErRank << endl;
    cout << "Fsr Score: " << UniArray[id]->FsrScore << endl;
    cout << "Fsr Rank: " << UniArray[id]->FsrRank << endl;
    cout << "Cpf Score: " << UniArray[id]->CpfScore << endl;
    cout << "Cpf Rank: " << UniArray[id]->CpfRank << endl;
    cout << "Ifr Score: " << UniArray[id]->IfrScore << endl;
    cout << "Ifr Rank: " << UniArray[id]->IfrRank << endl;
    cout << "Isr Score: " << UniArray[id]->IsrScore << endl;
    cout << "Isr Rank: " << UniArray[id]->IsrRank << endl;
    cout << "Irn Score: " << UniArray[id]->IrnScore << endl;
    cout << "Irn Rank: " << UniArray[id]->IrnRank << endl;
    cout << "Ger Score: " << UniArray[id]->GerScore << endl;
    cout << "Ger Rank: " << UniArray[id]->GerRank << endl;
    cout << "Score Scaled: " << UniArray[id]->ScoreScaled << endl;

    int input;
    cout << "Enter any other key to exit: ";
    cin >> input;
}
UniNode* UniList::getUniNode(string UniID) { return 0; }