#pragma once

#include "uni.hpp"

struct MergeSort {

    static void merge(UniNode* array[], int left, int middle, int right, string sortType)
    {
        int sizeLeft = middle - left + 1;
        int sizeRight = right - middle;

        UniNode** leftArr = new UniNode * [sizeLeft];
        UniNode** rightArr = new UniNode * [sizeRight];

        // Copy data to temporary arrays
        for (int i = 0; i < sizeLeft; ++i)
            leftArr[i] = array[left + i];
        for (int j = 0; j < sizeRight; ++j)
            rightArr[j] = array[middle + 1 + j];

        // Merge the temporary arrays back into arr[l..r]
        int i = 0, j = 0, k = left;

        double uniValueLeft, uniValueRight;
        string uniValueLeftStr, uniValueRightStr;

        

        while (i < sizeLeft && j < sizeRight) {

            if (sortType == "Institution") {
                uniValueLeftStr = leftArr[i]->Insitution;
                uniValueRightStr = rightArr[j]->Insitution;

                if (uniValueLeftStr <= uniValueRightStr) {
                    array[k] = leftArr[i];
                    ++i;
                }
                else {
                    array[k] = rightArr[j];
                    ++j;
                }
                ++k;
            }
            else if (sortType == "Ar") {
                uniValueLeft = leftArr[i]->ArScore;
                uniValueRight = rightArr[j]->ArScore;

                if (uniValueLeft <= uniValueRight) {
                    array[k] = leftArr[i];
                    ++i;
                }
                else {
                    array[k] = rightArr[j];
                    ++j;
                }
                ++k;
            }
            else if (sortType == "Er") {
                uniValueLeft = leftArr[i]->ErScore;
                uniValueRight = rightArr[j]->ErScore;

                if (uniValueLeft <= uniValueRight) {
                    array[k] = leftArr[i];
                    ++i;
                }
                else {
                    array[k] = rightArr[j];
                    ++j;
                }
                ++k;
            }
            else if (sortType == "Fsr") {
                uniValueLeft = leftArr[i]->FsrScore;
                uniValueRight = rightArr[j]->FsrScore;

                if (uniValueLeft <= uniValueRight) {
                    array[k] = leftArr[i];
                    ++i;
                }
                else {
                    array[k] = rightArr[j];
                    ++j;
                }
                ++k;
            }
            else if (sortType == "Rank") {
                uniValueLeft = leftArr[i]->Rank;
                uniValueRight = rightArr[j]->Rank;

                if (uniValueLeft <= uniValueRight) {
                    array[k] = leftArr[i];
                    ++i;
                }
                else {
                    array[k] = rightArr[j];
                    ++j;
                }
                ++k;
            }
            else if (sortType == "Location") {
                uniValueLeftStr = leftArr[i]->Location;
                uniValueRightStr = rightArr[j]->Location;

                if (uniValueLeftStr <= uniValueRightStr) {
                    array[k] = leftArr[i];
                    ++i;
                }
                else {
                    array[k] = rightArr[j];
                    ++j;
                }
                ++k;
            }

            
        }

        // Copy the remaining elements of leftArr[], if any
        while (i < sizeLeft) {
            array[k] = leftArr[i];
            ++i;
            ++k;
        }

        // Copy the remaining elements of rightArr[], if any
        while (j < sizeRight) {
            array[k] = rightArr[j];
            ++j;
            ++k;
        }

        // Clean up the temporary arrays
        delete[] leftArr;
        delete[] rightArr;
    }

    static void mergeSort(UniNode* array[], int left, int right, string sortType)
    {
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Sort first and second halves
            mergeSort(array, left, mid, sortType);
            mergeSort(array, mid + 1, right, sortType);

            // Merge the sorted halves
            merge(array, left, mid, right, sortType);
        }

    }

    // function to print the array
    static void printByPagination(UniNode* array[]) {
        int i;
        int currentShownTotal = 20;
        int currentShownLimit = 20;
        string sortInput;

        int counter; // needed?

        cout << left << setw(5) << "No.";
        cout << left << setw(90) << "Insitution" << endl;

        for (i = 0; i < 20; i++)
            cout << left << setw(5) << i + 1 << setw(90) << array[i]->Insitution << endl;
        cout << endl;

        while (currentShownTotal < 1422) {
            cout << "Enter [Y] to view another 20 records or [N] to exit: ";
            cin >> sortInput;

            if (sortInput == "Y" || sortInput == "y") {
                system("cls");
                cout << left << setw(5) << "No.";
                cout << left << setw(90) << "Insitution" << endl;
                for (currentShownLimit += 20; currentShownTotal < currentShownLimit; currentShownTotal++)
                    cout << left << setw(5) << currentShownTotal + 1 << setw(90) << array[currentShownTotal]->Insitution << endl;

                cout << endl;
                cout << "Showing " << currentShownLimit << " records" << endl;
            }
            else if (sortInput == "N" || sortInput == "n") {
                return;
            }
        }
    }
};