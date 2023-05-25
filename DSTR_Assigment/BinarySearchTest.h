#pragma once

using namespace std;

UniNode* binarySearch(UniNode* array[], int low, int high, string key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid]->Insitution == key) {
            return array[mid];  // Found the key at the middle index
        }

        if (array[mid]->Insitution < key) {
            return binarySearch(array, mid + 1, high, key);  // Search in the right half
        }

        return binarySearch(array, low, mid - 1, key);  // Search in the left half
    }

    return nullptr;  // Key not found
}