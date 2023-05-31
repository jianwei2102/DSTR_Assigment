#pragma once

#include "uni.hpp"

struct BinarySearch {

    static UniNode* binarySearch(UniNode* array[], int low, int high, string sortType, string key) {
        if (low <= high) {
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
                return array[mid];  // Found the key at the middle index
            }

            if (uniValue < key) {
                return binarySearch(array, mid + 1, high, sortType, key);  // Search in the right half
            }

            return binarySearch(array, low, mid - 1, sortType, key);  // Search in the left half
        }

        return nullptr;  // Key not found
    }
};