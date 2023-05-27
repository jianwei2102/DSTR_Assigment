#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct UniNode {
	string UniID, Insitution, LocationCode, Location, addon;
	double ArScore, ErScore, FsrScore, CpfScore, IfrScore, IsrScore, IrnScore, GerScore, ScoreScaled;
	int Rank, ArRank, ErRank, FsrRank, CpfRank, IfrRank, IsrRank, IrnRank, GerRank;
	UniNode* NextAdd;
} *head;

UniNode* createNewUniNode(int Rank, string Insitution, string LocationCode, string Location, double ArScore, int ArRank,
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
	newUniNode->NextAdd = NULL;
	return newUniNode;
}

void splitDisplay(UniNode* universities, int startInd, int batchSize) {
	int totalCount = 0;
	UniNode* current = universities;
	while (current != NULL && totalCount < startInd) {
		current = current->NextAdd;
		totalCount++;
	}
	for (int i = 0; i < batchSize && current != NULL; i++) {
		cout << "Rank: " << current->Rank << endl;
		cout << "Inistitution: " << current->Insitution << endl;
		cout << "Location Code: " << current->LocationCode << endl;
		cout << "Location: " << current->Location << endl;
		cout << "Academic Reputation Score: " << current->ArScore << endl;
		cout << "Academic Reputation Rank: " << current->ArRank << endl;
		cout << "Employer Reputation Score: " << current->ErScore << endl;
		cout << "Employer Reputation Rank: " << current->ErRank << endl;
		cout << "Faculty/Student Ratio Score: " << current->FsrScore << endl;
		cout << "Faculty/Student Ratio Rank: " << current->FsrRank << endl;
		cout << "Citations per Faculty Score: " << current->CpfScore << endl;
		cout << "Citations per Faculty Rank: " << current->CpfRank << endl;
		cout << "International Faculty Ratio Score: " << current->IfrScore << endl;
		cout << "International Faculty Ratio Rank: " << current->IfrRank << endl;
		cout << "International Student Ratio Score: " << current->IsrScore << endl;
		cout << "International Student Ratio Rank: " << current->IsrRank << endl;
		cout << "International Research Network Score: " << current->IrnScore << endl;
		cout << "International Research Network Rank: " << current->IrnRank << endl;
		cout << "Employment Outcome Score: " << current->GerScore << endl;
		cout << "Employment Outcome Rank: " << current->GerRank << endl;
		cout << "---------------------------------------------" << endl;

		current = current->NextAdd;
		totalCount++;
	}
	if (current != NULL) {
		cout << "---------------------------------------------" << endl;

		char userInput;
		do {

			cout << "Enter 'n' to continue: ";
			cin >> userInput;
			if (userInput == 'n' || userInput == 'N') {
				splitDisplay(universities, totalCount, batchSize);
			}
			else {
				cout << "Invalid Input" << endl;
			}
		} while (userInput != 'n' && userInput != 'N');
	}
	else {
		cout << "---------------------------------------------" << endl;
		cout << "End of List" << endl;
	}
}

void displayUniList() {
	head = NULL;
	ifstream file("2023 QS World University Rankings.csv");
	string Insitution, LocationCode, Location, Rank, ArRank, ErRank, FsrRank, CpfRank, IfrRank, IsrRank, IrnRank, GerRank,
		ArScore, ErScore, FsrScore, CpfScore, IfrScore, IsrScore, IrnScore, GerScore, ScoreScaled;
	string addon;
	UniNode* universities = NULL;
	UniNode* lastUniNode = NULL;

	while (file.good()) {
		UniNode* university = new UniNode;
		getline(file, Rank, ',');
		getline(file, Insitution, ',');
		if (Insitution[0] == '"') {
			bool endOfString = false;
			while (endOfString == false) {
				for (int i = 1; i < Insitution.length(); i++) {
					if (Insitution[i] == '"') {
						endOfString = true;
						break;
					}
				}
				if (!endOfString) {
					getline(file, addon, ',');
					Insitution = Insitution + ", " + addon;
				}
			}
			Insitution.erase(0, 1);
			Insitution.erase(Insitution.size() - 1);
		}
		getline(file, LocationCode, ',');
		getline(file, Location, ',');
		if (Location[0] == '"') {
			getline(file, addon, ',');
			Location = Location + ", " + addon;
			Location.erase(0, 1);
			Location.erase(Location.size() - 1);
		}
		getline(file, ArScore, ',');
		getline(file, ArRank, ',');
		getline(file, ErScore, ',');
		getline(file, ErRank, ',');
		getline(file, FsrScore, ',');
		getline(file, FsrRank, ',');
		getline(file, CpfScore, ',');
		getline(file, CpfRank, ',');
		getline(file, IfrScore, ',');
		getline(file, IfrRank, ',');
		getline(file, IsrScore, ',');
		getline(file, IsrRank, ',');
		getline(file, IrnScore, ',');
		getline(file, IrnRank, ',');
		getline(file, GerScore, ',');
		getline(file, GerRank, ',');
		getline(file, ScoreScaled);
		if (Insitution == "Institution") {
			continue;
		}
		else if (Rank == "") {
			break;
		}

		if (ErScore == "") {
			ErScore = "-1";
		}
		if (FsrScore == "") {
			FsrScore = "-1";
		}
		if (CpfScore == "") {
			CpfScore = "-1";
		}
		if (IfrScore == "") {
			IfrScore = "-1";
		}

		if (IfrRank == "601+") {
			IfrRank = "601";
		}
		else if (IfrRank == "") {
			IfrRank = "602";
		}

		if (IsrScore == "") {
			IsrScore = "0";
		}
		if (IsrRank == "601+") {
			IsrRank = "601";
		}
		else if (IsrRank == "") {
			IsrRank = "602";
		}

		if (IrnScore == "") {
			IrnScore = "0";
		}
		if (IrnRank == "601+") {
			IrnRank = "601";
		}
		else if (IrnRank == "") {
			IrnRank = "602";
		}

		if (GerScore == "") {
			GerScore = "0";
		}
		if (GerRank == "601+") {
			GerRank = "601";
		}
		else if (GerRank == "") {
			GerRank = "602";
		}
		if (ScoreScaled == "-") {
			ScoreScaled = "0";
		}

		university->Rank = stoi(Rank);
		university->Insitution = Insitution;
		university->LocationCode = LocationCode;
		university->Location = Location;
		university->ArScore = stod(ArScore);
		university->ArRank = stoi(ArRank);
		university->ErScore = stod(ErScore);
		university->ErRank = stoi(ErScore);
		university->FsrScore = stod(FsrScore);
		university->FsrRank = stoi(FsrRank);
		university->CpfScore = stod(CpfScore);
		university->CpfRank = stoi(CpfRank);
		university->IfrScore = stod(IfrScore);
		university->IfrRank = stoi(IfrRank);
		university->IsrScore = stod(IsrScore);
		university->IsrRank = stoi(IsrRank);
		university->IrnScore = stod(IrnScore);
		university->IrnRank = stoi(IrnRank);
		university->GerScore = stod(GerScore);
		university->GerRank = stoi(GerRank);
		university->ScoreScaled = stod(ScoreScaled);
		university->NextAdd = NULL;

		if (universities == NULL) {
			universities = university;
			lastUniNode = university;
		}
		else {
			lastUniNode->NextAdd = university;
			lastUniNode = university;
		}

	}
	file.close();
	splitDisplay(universities, 0, 25);
}

int main() {
	displayUniList();
	return 0;
}
