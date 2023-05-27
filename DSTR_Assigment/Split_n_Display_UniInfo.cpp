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

void splitDisplay(const vector<UniNode>& universities, int startInd, int batchSize) {
	int totalCount = universities.size();
	int endInd = min(startInd + batchSize - 1, totalCount - 1);
	for (int i = startInd; i <= endInd; i++) {
		cout << "Rank: " << universities[i].Rank << endl;
		cout << "Inistitution: " << universities[i].Insitution << endl;
		cout << "Location Code: " << universities[i].LocationCode << endl;
		cout << "Location: " << universities[i].Location << endl;
		cout << "Academic Reputation Score: " << universities[i].ArScore << endl;
		cout << "Academic Reputation Rank: " << universities[i].ArRank << endl;
		cout << "Employer Reputation Score: " << universities[i].ErScore << endl;
		cout << "Employer Reputation Rank: " << universities[i].ErRank << endl;
		cout << "Faculty/Student Ratio Score: " << universities[i].FsrScore << endl;
		cout << "Faculty/Student Ratio Rank: " << universities[i].FsrRank << endl;
		cout << "Citations per Faculty Score: " << universities[i].CpfScore << endl;
		cout << "Citations per Faculty Rank: " << universities[i].CpfRank << endl;
		cout << "International Faculty Ratio Score: " << universities[i].IfrScore << endl;
		cout << "International Faculty Ratio Rank: " << universities[i].IfrRank << endl;
		cout << "International Student Ratio Score: " << universities[i].IsrScore << endl;
		cout << "International Student Ratio Rank: " << universities[i].IsrRank << endl;
		cout << "International Research Network Score: " << universities[i].IrnScore << endl;
		cout << "International Research Network Rank: " << universities[i].IrnRank << endl;
		cout << "Employment Outcome Score: " << universities[i].GerScore << endl;
		cout << "Employment Outcome Rank: " << universities[i].GerRank << endl;
		cout << "---------------------------------------------" << endl;
	}
	if (endInd < totalCount - 1) {
		cout << "---------------------------------------------" << endl;

		char userInput;
		do {
			
			cout << "Enter 'n' to continue: ";
			cin >> userInput;
			if (userInput == 'n' || userInput == 'N') {
				splitDisplay(universities, endInd + 1, batchSize);
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
	vector<UniNode> universities;
	while (file.good()) {
		UniNode university;
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

		university.Rank = stoi(Rank);
		university.Insitution = Insitution;
		university.LocationCode = LocationCode;
		university.Location = Location;
		university.ArScore = stod(ArScore);
		university.ArRank = stoi(ArRank);
		university.ErScore = stod(ErScore);
		university.ErRank = stoi(ErScore);
		university.FsrScore = stod(FsrScore);
		university.FsrRank = stoi(FsrRank);
		university.CpfScore = stod(CpfScore);
		university.CpfRank = stoi(CpfRank);
		university.IfrScore = stod(IfrScore);
		university.IfrRank = stoi(IfrRank);
		university.IsrScore = stod(IsrScore);
		university.IsrRank = stoi(IsrRank);
		university.IrnScore = stod(IrnScore);
		university.IrnRank = stoi(IrnRank);
		university.GerScore = stod(GerScore);
		university.GerRank = stoi(GerRank);
		university.ScoreScaled = stod(ScoreScaled);
		universities.push_back(university);

	}
	file.close();
	int startInd = 0;
	int batchSize = 20; //number for displaying by how much
	splitDisplay(universities, startInd, batchSize);

}

int main() {
	displayUniList();
	return 0;
}