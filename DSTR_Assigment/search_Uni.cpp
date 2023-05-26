#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <chrono>
using namespace std;
using namespace std::chrono;

struct UniNode {
	string UniID, Insitution, LocationCode, Location, addon;
	double ArScore, ErScore, FsrScore, CpfScore, IfrScore, IsrScore, IrnScore, GerScore, ScoreScaled;
	int Rank, ArRank, ErRank, FsrRank, CpfRank, IfrRank, IsrRank, IrnRank, GerRank;
};

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
	//newUniNode->NextAdd = NULL;
	return newUniNode;
}

bool compareInst(const UniNode& u1, const UniNode& u2) {
	return u1.Insitution < u2.Insitution;
}

bool compareLoc(const UniNode& u3, const UniNode& u4) {
	return u3.Location < u4.Location;
}

void binarySearchInst(const vector<UniNode>& universities, const string& searchTerm2) {
	auto start = high_resolution_clock::now();
	int left = 0;
	int right = universities.size() - 1;
	bool found = false;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (universities[mid].Insitution == searchTerm2) {
			cout << "Rank: " << universities[mid].Rank << endl;
			cout << "Inistitution: " << universities[mid].Insitution << endl;
			cout << "Location Code: " << universities[mid].LocationCode << endl;
			cout << "Location: " << universities[mid].Location << endl;
			cout << "Academic Reputation Score: " << universities[mid].ArScore << endl;
			cout << "Academic Reputation Rank: " << universities[mid].ArRank << endl;
			cout << "Employer Reputation Score: " << universities[mid].ErScore << endl;
			cout << "Employer Reputation Rank: " << universities[mid].ErRank << endl;
			cout << "Faculty/Student Ratio Score: " << universities[mid].FsrScore << endl;
			cout << "Faculty/Student Ratio Rank: " << universities[mid].FsrRank << endl;
			cout << "Citations per Faculty Score: " << universities[mid].CpfScore << endl;
			cout << "Citations per Faculty Rank: " << universities[mid].CpfRank << endl;
			cout << "International Faculty Ratio Score: " << universities[mid].IfrScore << endl;
			cout << "International Faculty Ratio Rank: " << universities[mid].IfrRank << endl;
			cout << "International Student Ratio Score: " << universities[mid].IsrScore << endl;
			cout << "International Student Ratio Rank: " << universities[mid].IsrRank << endl;
			cout << "International Research Network Score: " << universities[mid].IrnScore << endl;
			cout << "International Research Network Rank: " << universities[mid].IrnRank << endl;
			cout << "Employment Outcome Score: " << universities[mid].GerScore << endl;
			cout << "Employment Outcome Rank: " << universities[mid].GerRank << endl;
			found = true;
			break;
		}
		else if (universities[mid].Insitution < searchTerm2) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	if (!found) {
		cout << "Institution Not Found!" << endl;
	}
	cout << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << endl << "Time taken by Binary search algorithm: " << duration.count() << " microseconds" << endl;
}

int binarySearchLoc(const vector<UniNode>& universities, const string& searchTerm) {
	int left = 0;
	int right = universities.size() - 1;
	int result = - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (universities[mid].Location < searchTerm) {
			left = mid + 1;
		}
		else if(universities[mid].Location > searchTerm) {
			right = mid - 1;
		}
		else {
			result = mid;
			right = mid - 1;
		}
	}
	return result;
}

void displayInfoByLoc(const vector<UniNode>& universities, const string& searchTerm) {
	auto start = high_resolution_clock::now();
	int startInd = binarySearchLoc(universities, searchTerm);
	if (startInd == -1) {
		cout << "No Institutions Found at this Location" << endl;
		return;
	}
	int endInd = universities.size() - 1;
	for (int i = startInd; i <= endInd; i++) {
		if (universities[i].Location != searchTerm) {
			break;
		}
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
		cout << "-------------------------------------------------------------------" << endl;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << endl << "Time taken by Binary search algorithm: " << duration.count() << " microseconds" << endl;
}

void linearSearchInst(const vector<UniNode>& universities, const string& searchTerm) {
	auto start = high_resolution_clock::now();
	bool found = false;
	for (const auto& university : universities) {
		if (university.Insitution == searchTerm) {
			cout << "Rank: " << university.Rank << endl;
			cout << "Inistitution: " << university.Insitution << endl;
			cout << "Location Code: " << university.LocationCode << endl;
			cout << "Location: " << university.Location << endl;
			cout << "Academic Reputation Score: " << university.ArScore << endl;
			cout << "Academic Reputation Rank: " << university.ArRank << endl;
			cout << "Employer Reputation Score: " << university.ErScore << endl;
			cout << "Employer Reputation Rank: " << university.ErRank << endl;
			cout << "Faculty/Student Ratio Score: " << university.FsrScore << endl;
			cout << "Faculty/Student Ratio Rank: " << university.FsrRank << endl;
			cout << "Citations per Faculty Score: " << university.CpfScore << endl;
			cout << "Citations per Faculty Rank: " << university.CpfRank << endl;
			cout << "International Faculty Ratio Score: " << university.IfrScore << endl;
			cout << "International Faculty Ratio Rank: " << university.IfrRank << endl;
			cout << "International Student Ratio Score: " << university.IsrScore << endl;
			cout << "International Student Ratio Rank: " << university.IsrRank << endl;
			cout << "International Research Network Score: " << university.IrnScore << endl;
			cout << "International Research Network Rank: " << university.IrnRank << endl;
			cout << "Employment Outcome Score: " << university.GerScore << endl;
			cout << "Employment Outcome Rank: " << university.GerRank << endl;

			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Institution Not Found!" << endl;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << endl << "Time taken by Linear Search Algorithm: " << duration.count() << " microseconds" << endl;
}

void linearSearchLoc(const vector<UniNode>& universities, const string& searchTerm) {  //<- need to find how to display multiple entries
	auto start = high_resolution_clock::now();
	bool found = false;
	for (const auto& university : universities) {
		if (university.Location == searchTerm) {
			cout << "Rank: " << university.Rank << endl;
			cout << "Inistitution: " << university.Insitution << endl;
			cout << "Location Code: " << university.LocationCode << endl;
			cout << "Location: " << university.Location << endl;
			cout << "Academic Reputation Score: " << university.ArScore << endl;
			cout << "Academic Reputation Rank: " << university.ArRank << endl;
			cout << "Employer Reputation Score: " << university.ErScore << endl;
			cout << "Employer Reputation Rank: " << university.ErRank << endl;
			cout << "Faculty/Student Ratio Score: " << university.FsrScore << endl;
			cout << "Faculty/Student Ratio Rank: " << university.FsrRank << endl;
			cout << "Citations per Faculty Score: " << university.CpfScore << endl;
			cout << "Citations per Faculty Rank: " << university.CpfRank << endl;
			cout << "International Faculty Ratio Score: " << university.IfrScore << endl;
			cout << "International Faculty Ratio Rank: " << university.IfrRank << endl;
			cout << "International Student Ratio Score: " << university.IsrScore << endl;
			cout << "International Student Ratio Rank: " << university.IsrRank << endl;
			cout << "International Research Network Score: " << university.IrnScore << endl;
			cout << "International Research Network Rank: " << university.IrnRank << endl;
			cout << "Employment Outcome Score: " << university.GerScore << endl;
			cout << "Employment Outcome Rank: " << university.GerRank << endl;
			cout << "-------------------------------------------------------------------" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Institution Not Found!" << endl;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << endl << "Time taken by Linear Search Algorithm: " << duration.count() << " microseconds" << endl;
}

void searchUni() {
	//head = NULL;
	string Insitution, LocationCode, Location, Rank, ArRank, ErRank, FsrRank, CpfRank, IfrRank, IsrRank, IrnRank, GerRank,
		ArScore, ErScore, FsrScore, CpfScore, IfrScore, IsrScore, IrnScore, GerScore, ScoreScaled;
	string addon;
	vector<UniNode> universities;
	ifstream file("2023 QS World University Rankings.csv");
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

	//search menu
	int choice, choice2;
	string searchTerm;
	do {
		cout << "How would you like to search by?" << endl;
		cout << "1. Search by Institution Name\n2. Search by Location" << endl;
		cout << "Operation No.: ";
		cin >> choice;
		cin.ignore(1, '\n'); // prevent skipping getline()
		// 1. Institution
		if (choice == 1) {												
			cout << "\nInstitution Name: ";
			getline(cin, searchTerm);

			do {
				cout << "\nWhich searching algorithm would you like to perform?\n1. Binary Search\n2. LinearSearch\nAlgorithm No.: ";
				cin >> choice2;

				if (choice2 == 1) {										//<- Binary Search for Institution
					cout << endl;
					sort(universities.begin(), universities.end(), compareInst);
					binarySearchInst(universities, searchTerm);
				}
				else if (choice2 == 2) {								//<- Linear Search for Institution
					cout << endl;
					linearSearchInst(universities, searchTerm);
				}
				else {
					cout << endl << "Invalid Input" << endl;
				}
			} while (choice2 != 1 && choice2 != 2);
		}
		//2. Location
		else if (choice == 2) {
			cout << "\nLocation: ";
			getline(cin, searchTerm);

			do {
				cout << "\nWhich searching algorithm would you like to perform?\n1. Binary Search\n2. LinearSearch\nAlgorithm No.: ";
				cin >> choice2;

				if (choice2 == 1) {										//<- Binary Search for Location
					cout << endl;
					sort(universities.begin(), universities.end(), compareLoc);
					displayInfoByLoc(universities, searchTerm);
				}
				else if (choice2 == 2) {								//<- Linear Search for Location
					cout << endl;
					linearSearchLoc(universities, searchTerm);
				}
				else {
					cout << endl << "Invalid Input" << endl;
				}
			} while (choice2 != 1 && choice2 != 2);
		}
		else {
			cout << endl << "Invalid Input" << endl;
		}
	} while (choice != 1 && choice != 2);
}

int main() {
	searchUni();
}
