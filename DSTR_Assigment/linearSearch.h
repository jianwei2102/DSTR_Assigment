#pragma once

#include "uni.hpp"

struct LinearSearch {

    static UniNode* linearSearch(UniNode* array[], int size, string sortType, string key) {
        for (int index = 0; index < size; index++)
        {
            if (array[index]->Insitution == key)
            {
                return array[index];
            }
        }

        return nullptr;  // Key not found
    }
};