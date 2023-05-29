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
            }
            else if (sortType == "Er") {
                uniValue = array[j]->ErScore;
                pivotValue = pivot->ErScore;
            }
            else if (sortType == "Fsr") {
                uniValue = array[j]->FsrScore;
                pivotValue = pivot->FsrScore;
            }
            else if (sortType == "Institution") {
                uniValueIns = array[j]->Insitution;
                pivotValueIns = pivot->Insitution;
            }

            if (uniValue <= pivotValue) {

                // if element smaller than pivot is found
                // swap it with the greater element pointed by i
                i++;

                // swap element at i with element at j
                swap(array, i, j);
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
};