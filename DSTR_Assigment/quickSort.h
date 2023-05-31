#pragma once

#include "uni.hpp"

struct QuickSort {

    static void swap(UniNode* array[], int a, int b) {
        UniNode* temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }

    static int partition(UniNode* array[], int low, int high, string sortType) {
        // select the rightmost element as pivot
        UniNode* pivot = array[high];

        // pointer for greater element
        int i = (low - 1);

        // traverse each element of the array
        // compare them with the pivot
        for (int j = low; j < high; j++) {
            double uniValue, pivotValue;
            string uniValueIns, pivotValueIns;
            if (sortType == "Ar") {
                uniValue = array[j]->ArScore;
                pivotValue = pivot->ArScore;

                if (uniValue >= pivotValue) {

                    // if element smaller than pivot is found
                    // swap it with the greater element pointed by i
                    i++;

                    // swap element at i with element at j
                    swap(array, i, j);
                }
            }
            else if (sortType == "Er") {
                uniValue = array[j]->ErScore;
                pivotValue = pivot->ErScore;

                if (uniValue >= pivotValue) {

                    // if element smaller than pivot is found
                    // swap it with the greater element pointed by i
                    i++;

                    // swap element at i with element at j
                    swap(array, i, j);
                }
            }
            else if (sortType == "Fsr") {
                uniValue = array[j]->FsrScore;
                pivotValue = pivot->FsrScore;

                if (uniValue >= pivotValue) {

                    // if element smaller than pivot is found
                    // swap it with the greater element pointed by i
                    i++;

                    // swap element at i with element at j
                    swap(array, i, j);
                }
            }
            else if (sortType == "Institution") {
                uniValueIns = array[j]->Insitution;
                pivotValueIns = pivot->Insitution;

                if (uniValueIns <= pivotValueIns) {

                    // if element smaller than pivot is found
                    // swap it with the greater element pointed by i
                    i++;

                    // swap element at i with element at j
                    swap(array, i, j);
                }
            }
            else if (sortType == "Rank") {
                uniValueIns = array[j]->Rank;
                pivotValueIns = pivot->Rank;

                if (uniValueIns <= pivotValueIns) {

                    // if element smaller than pivot is found
                    // swap it with the greater element pointed by i
                    i++;

                    // swap element at i with element at j
                    swap(array, i, j);
                }
            }


        }

        // swap pivot with the greater element at i
        swap(array, i + 1, high);

        // return the partition point
        return (i + 1);
    }

    static void quickSort(UniNode* array[], int low, int high, string sortType) {
        if (low < high) {
            // find the pivot element such that
            // elements smaller than pivot are on left of pivot
            // elements greater than pivot are on righ of pivot
            int pi = partition(array, low, high, sortType);

            // recursive call on the left of pivot
            quickSort(array, low, pi - 1, sortType);

            // recursive call on the right of pivot
            quickSort(array, pi + 1, high, sortType);
        }
    }

    // function to print the array
    static void printByPagination(UniNode* array[], string sortType) {
        int i;
        int currentShownTotal = 20;
        int currentShownLimit = 20;
        string sortInput;

        int counter; // needed?
        cout << left << setw(5) << "No.";
        cout << left << setw(90) << "Insitution";
        cout << left << setw(8) << sortType << endl;
        for (i = 0; i < 20; i++)
            if (sortType == "Ar") {
                cout << left << setw(5) << i + 1;
                cout << left << setw(90) << array[i]->Insitution;
                cout << left << setw(8) << array[i]->ArScore << endl;
            }
            else if (sortType == "Er") {
                cout << left << setw(5) << i + 1;
                cout << left << setw(90) << array[i]->Insitution;
                cout << left << setw(8) << array[i]->ErScore << endl;
            }
            else if (sortType == "Fsr") {
                cout << left << setw(5) << i + 1;
                cout << left << setw(90) << array[i]->Insitution;
                cout << left << setw(8) << array[i]->FsrScore << endl;
            }
            else if (sortType == "Institution") {
                cout << left << setw(5) << i + 1;
                cout << left << setw(90) << array[i]->Insitution << endl;
            }
        //cout << "[" << i + 1 << "] " << array[i]->Insitution << endl;
        cout << endl;

        while (currentShownTotal < 1421) {
            cout << "Enter [Y] to view another 20 records or [N] to exit: " << endl;
            cin >> sortInput;

            if (sortInput == "Y" || sortInput == "y") {
                system("cls");
                cout << left << setw(5) << "No.";
                cout << left << setw(90) << "Insitution";
                cout << left << setw(8) << sortType << endl;
                for (currentShownLimit += 20; currentShownTotal < currentShownLimit; currentShownTotal++)
                    if (sortType == "Ar") {
                        cout << left << setw(5) << currentShownTotal + 1;
                        cout << left << setw(90) << array[currentShownTotal]->Insitution;
                        cout << left << setw(8) << array[currentShownTotal]->ArScore << endl;
                    }
                    else if (sortType == "Er") {
                        cout << left << setw(5) << currentShownTotal + 1;
                        cout << left << setw(90) << array[currentShownTotal]->Insitution;
                        cout << left << setw(8) << array[currentShownTotal]->ErScore << endl;
                    }
                    else if (sortType == "Fsr") {
                        cout << left << setw(5) << currentShownTotal + 1;
                        cout << left << setw(90) << array[currentShownTotal]->Insitution;
                        cout << left << setw(8) << array[currentShownTotal]->FsrScore << endl;
                    }
                    else if (sortType == "Institution") {
                        cout << left << setw(5) << currentShownTotal + 1;
                        cout << left << setw(90) << array[currentShownTotal]->Insitution;
                    }
                //cout << "[" << currentShownTotal + 1 << "] " << array[currentShownTotal]->Insitution << endl;
                cout << endl;
                cout << "Showing " << currentShownLimit << " records" << endl;
            }
            else if (sortInput == "N" || sortInput == "n") {
                return;
            }
        }
    }
};