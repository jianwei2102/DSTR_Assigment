#pragma once

#include "uni.hpp"

struct LinearSearch {

    static void linearSearch(UniNode* array[], int size, string sortType, string key) {
        for (int index = 0; index < size; index++)
        {
            string uniValue;
            if (sortType == "name") {
                uniValue = array[index]->Insitution;
            }
            else if (sortType == "location") {
                uniValue = array[index]->Location;
            }

            if (uniValue == key)
            {
                cout << endl << "  ------------------------------------------------- " << endl;
                cout << " |               University's Detail?               |" << endl;
                cout << "  ------------------------------------------------- " << endl;
                cout << "Rank: " << array[index]->Rank << endl;
                cout << "Inistitution:  " << array[index]->Insitution << endl;
                cout << "Location Code: " << array[index]->LocationCode << endl;
                cout << "Location: " << array[index]->Location << endl;
                cout << "Academic Reputation Score: " << array[index]->ArScore << endl;
                cout << "Academic Reputation Rank : " << array[index]->ArRank << endl;
                cout << "Employer Reputation Score: " << array[index]->ErScore << endl;
                cout << "Employer Reputation Rank : " << array[index]->ErRank << endl;
                cout << "Faculty/Student Ratio Score: " << array[index]->FsrScore << endl;
                cout << "Faculty/Student Ratio Rank : " << array[index]->FsrRank << endl;
                cout << "Citations per Faculty Score: " << array[index]->CpfScore << endl;
                cout << "Citations per Faculty Rank : " << array[index]->CpfRank << endl;
                cout << "International Faculty Ratio Score: " << array[index]->IfrScore << endl;
                cout << "International Faculty Ratio Rank : " << array[index]->IfrRank << endl;
                cout << "International Student Ratio Score: " << array[index]->IsrScore << endl;
                cout << "International Student Ratio Rank : " << array[index]->IsrRank << endl;
                cout << "International Research Network Score: " << array[index]->IrnScore << endl;
                cout << "International Research Network Rank : " << array[index]->IrnRank << endl;
                cout << "Employment Outcome Score: " << array[index]->GerScore << endl;
                cout << "Employment Outcome Rank : " << array[index]->GerRank << endl;
                cout << "Score Scaled: " << array[index]->ScoreScaled << endl;
                return;
            }
        }
    }
};