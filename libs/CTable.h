//
// Created by biongoo on 04.06.2020.
//

#ifndef MP_12_CTABLE_H
#define MP_12_CTABLE_H

#include "CSortTable.h"
#include <algorithm>
#include <iostream>

class CTable {
public:
    void cocktailSort(CSortTable &cSortTable );

    void heapify(CSortTable &cSortTable, int n, int i);

    void heapSort(CSortTable &cSortTable);

    int partitionHoare(CSortTable &cSortTable, int low, int high);

    int partitionLomuto(CSortTable &cSortTable, int low, int high);

    void quickSort(CSortTable &cSortTable, int low, int high, int method);

    void quickSortMenu(CSortTable &cSortTable, int low, int high);
};

#endif //MP_12_CTABLE_H