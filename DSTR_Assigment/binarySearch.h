#pragma once

#include "uni.hpp"

struct BinarySearch {

    static void binarySearch(UniNode* array[], int low, int high, string sortType, string key) {
        if (low <= high) {
            int i;
            int mid = low + (high - low) / 2;

            // search by different columns
            string uniValue;
            if (sortType == "name") {
                uniValue = array[mid]->Insitution;
            }
            else if (sortType == "location") {
                uniValue = array[mid]->Location;
            }

           
            if (uniValue == key) {
                cout<< endl << "  ------------------------------------------------- " << endl;
                cout << " |               University's Detail               |" << endl;
                cout << "  ------------------------------------------------- " << endl;
                cout << "Rank: " << array[mid]->Rank << endl;
                cout << "Inistitution:  " << array[mid]->Insitution << endl;
                cout << "Location Code: " << array[mid]->LocationCode << endl;
                cout << "Location: " << array[mid]->Location << endl;
                cout << "Academic Reputation Score: " << array[mid]->ArScore << endl;
                cout << "Academic Reputation Rank:  " << array[mid]->ArRank << endl;
                cout << "Employer Reputation Score: " << array[mid]->ErScore << endl;
                cout << "Employer Reputation Rank:  " << array[mid]->ErRank << endl;
                cout << "Faculty/Student Ratio Score: " << array[mid]->FsrScore << endl;
                cout << "Faculty/Student Ratio Rank:  " << array[mid]->FsrRank << endl;
                cout << "Citations per Faculty Score: " << array[mid]->CpfScore << endl;
                cout << "Citations per Faculty Rank:  " << array[mid]->CpfRank << endl;
                cout << "International Faculty Ratio Score: " << array[mid]->IfrScore << endl;
                cout << "International Faculty Ratio Rank:  " << array[mid]->IfrRank << endl;
                cout << "International Student Ratio Score: " << array[mid]->IsrScore << endl;
                cout << "International Student Ratio Rank:  " << array[mid]->IsrRank << endl;
                cout << "International Research Network Score: " << array[mid]->IrnScore << endl;
                cout << "International Research Network Rank:  " << array[mid]->IrnRank << endl;
                cout << "Employment Outcome Score: " << array[mid]->GerScore << endl;
                cout << "Employment Outcome Rank:  " << array[mid]->GerRank << endl;
                cout << "Score Scaled: " << array[mid]->ScoreScaled << endl;
                return;
            }
           
            if (uniValue < key) {
                return binarySearch(array, mid + 1, high, sortType, key);  // Search in the right half
            }

            return binarySearch(array, low, mid - 1, sortType, key);  // Search in the left half
        }

        //return nullptr;  // Key not found
    }
};