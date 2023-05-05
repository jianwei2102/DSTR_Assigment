#include "read_file.hpp"
#include "uni_class.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

UniList ReadUniFromFile() {
	
	UniList list;
	string Insitution, LocationCode, Location, Rank, ArRank, ErRank, FsrRank, CpfRank, IfrRank, IsrRank, IrnRank, GerRank,
		ArScore, ErScore, FsrScore, CpfScore, IfrScore, IsrScore, IrnScore, GerScore, ScoreScaled;
	string addon;

	ifstream file("2023 QS World University Rankings.csv");
	while (file.good()) {
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
		list.insertIntoUniList(stoi(Rank), Insitution, LocationCode, Location, stod(ArScore), stoi(ArRank), stod(ErScore),
			stoi(ErRank), stod(FsrScore), stoi(FsrRank), stod(CpfScore), stoi(CpfRank), stod(IfrScore), stoi(IfrRank), stod(IsrScore),
			stoi(IsrRank), stod(IrnScore), stoi(IrnRank), stod(GerScore), stoi(GerRank), stod(ScoreScaled));
	}
	file.close();
	return list;
}