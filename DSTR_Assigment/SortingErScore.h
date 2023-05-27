#pragma once

using namespace std;

void mergeErScore(UniNode* array[], int left, int middle, int right)
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
    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i]->ErScore >= rightArr[j]->ErScore) {
            array[k] = leftArr[i];
            ++i;
        }
        else {
            array[k] = rightArr[j];
            ++j;
        }
        ++k;
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

// Merge Sort function
void mergeSortErScore(UniNode* array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSortErScore(array, left, mid);
        mergeSortErScore(array, mid + 1, right);

        // Merge the sorted halves
        mergeErScore(array, left, mid, right);
    }
}

void printErScoreByPagination(UniNode* array[], int size) {
    int i;
    int currentShownTotal = 20;
    int currentShownLimit = 20;
    string sortInput;

    int counter; // needed?

    cout << "Sorting University Information by Employer Reputation Score" << endl;

    for (i = 0; i < 20; i++)
        cout << "[" << i + 1 << "] " << "ErScore: " << array[i]->ErScore << " - (" << array[i]->Insitution << ")" << endl;
    cout << endl;
    cout << endl;

    while (currentShownTotal < 1422) {
        cout << "Enter [Y] to view another 20 records or [N] to exit: " << endl;
        cin >> sortInput;

        if (sortInput == "Y") {
            for (currentShownLimit += 20; currentShownTotal < currentShownLimit; currentShownTotal++)
                cout << "[" << currentShownTotal + 1 << "] " << "ErScore: " << array[currentShownTotal]->ErScore << "- (" << array[currentShownTotal]->Insitution << ")" << endl;
            cout << endl;
            cout << endl;
            cout << "Showing " << currentShownLimit << " records" << endl;
        }
    }
}