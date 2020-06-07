//
// Created by biongoo on 04.06.2020.
//

#include "CTable.h"

// Sorts table a[0..n-1] using Cocktail sort
void CTable::cocktailSort(CSortTable &cSortTable) {
    int lenghtOfArray = cSortTable.size;
    int *table = cSortTable.array;
    bool swapped = true;
    int start = 0;
    int end = lenghtOfArray - 1;

    while (swapped) {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;

        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i) {
            cSortTable.equalities++;
            if (table[i] > table[i + 1]) {
                cSortTable.swaps++;
                std::swap(table[i], table[i + 1]);
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted.
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;

        // move the end point back by one, because
        // item at the end is in its rightful spot
        --end;

        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            cSortTable.equalities++;
            if (table[i] > table[i + 1]) {
                cSortTable.swaps++;
                std::swap(table[i], table[i + 1]);
                swapped = true;
            }
        }

        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
}

// To heapify a subtree rooted with node i which is
// an index in table[]. n is size of heap
void CTable::heapify(CSortTable &cSortTable, int n, int i) {
    int lenghtOfArray = cSortTable.size;
    int *table = cSortTable.array;
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    cSortTable.equalities ++;
    if (l < n && table[l] > table[largest])
        largest = l;

    // If right child is larger than largest so far
    cSortTable.equalities ++;
    if (r < n && table[r] > table[largest])
        largest = r;

    // If largest is not root
    cSortTable.equalities++;
    if (largest != i) {
        cSortTable.swaps++;
        std::swap(table[i], table[largest]);

        // Recursively heapify the affected sub-tree
        heapify(cSortTable, n, largest);
    }
}

// main function to do heap sort
void CTable::heapSort(CSortTable &cSortTable) {
    int lenghtOfArray = cSortTable.size;
    int *table = cSortTable.array;
    // Build heap (rearrange array)
    for (int i = lenghtOfArray / 2 - 1; i >= 0; i--)
        heapify(cSortTable, lenghtOfArray, i);

    // One by one extract an element from heap
    for (int i = lenghtOfArray - 1; i > 0; i--) {
        // Move current root to end
        cSortTable.swaps++;
        std::swap(table[0], table[i]);
        // call max heapify on the reduced heap
        heapify(cSortTable, i, 0);
    }
}

/*  This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot */
int CTable::partitionHoare(CSortTable &cSortTable, int low, int high) {
    int *table = cSortTable.array;
    int pivot = table[low];
    int i = low - 1, j = high + 1;

    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
            cSortTable.equalities++;
        } while (table[i] < pivot);

        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
            cSortTable.equalities++;
        } while (table[j] > pivot);
        // If two pointers met.
        cSortTable.equalities++;
        if (i >= j)
            return j;
        cSortTable.swaps++;
        std::swap(table[i], table[j]);
    }
}

/*  This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot */
int CTable::partitionLomuto(CSortTable &cSortTable, int low, int high) {
    int *table = cSortTable.array;
    int pivot = table[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    for (int j = low; j <= high - 1; j++)
        // If current element is smaller than or
        // equal to pivot
        if (table[j] <= pivot) {
            i++;    // increment index of smaller element
            std::swap(table[i], table[j]);
        }
    cSortTable.equalities++;
    std::swap(table[i + 1], table[high]);
    return (i + 1);
}

/*  The main function that implements QuickSort
    table[] -. Array to be sorted,
    low  -. Starting index,
    high  -. Ending index,
    method -. Lomuto's or Hoare's method */
void CTable::quickSort(CSortTable &cSortTable, int low, int high, int method) {
    cSortTable.equalities++;
    if (low < high) {
        int pi;

        /* pi is partitioning index, arr[p] is now
           at right place */
        switch (method) {
            case 1:
                pi = partitionLomuto(cSortTable, low, high);
                quickSort(cSortTable, low, pi - 1, method);
                break;

            case 2:
                pi = partitionHoare(cSortTable, low, high);
                quickSort(cSortTable, low, pi, method);
        }

        // Separately sort elements before (in switch)
        // partition and after partition

        quickSort(cSortTable, pi + 1, high, method);
    }
}

/*  Menu to chose method of quick sort
    table[] -. Array to be sorted,
    low  -. Starting index,
    high  -. Ending index */
void CTable::quickSortMenu(CSortTable &cSortTable, int low, int high) {
    int choice;

    std::cout << "Which method do You want to use? (1 - > Lomuto, 2 - > Hoare):";
    std::cin >> choice;
    if ((choice == 1) || choice == 2)
        quickSort(cSortTable, low, high, choice);
    else {
        std::cout << "Invalid option selected! Try again." << std::endl << std::endl;
        quickSortMenu(cSortTable, low, high);
    }
}