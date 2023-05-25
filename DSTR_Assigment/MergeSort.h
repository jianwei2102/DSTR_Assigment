#pragma once

void merge(UniNode* array[], int left, int middle, int right)
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
        if (leftArr[i]->Insitution <= rightArr[j]->Insitution) {
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
void mergeSort(UniNode* array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}
