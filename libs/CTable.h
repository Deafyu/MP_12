//
// Created by biongoo on 04.06.2020.
//

#ifndef MP_12_CTABLE_H
#define MP_12_CTABLE_H

#include <algorithm>
#include <iostream>

class CTable {
public:
    void cocktailSort(int table[], int n);
    void heapify(int table[], int n, int i);
    void heapSort(int table[], int n);
    int partitionHoare(int table[], int low, int high);
    int partitionLomuto(int table[], int low, int high);
    void quickSort(int table[], int low, int high, int method);
    void quickSortMenu(int table[], int low, int high);
};


class CSortTable{

};



#endif //MP_12_CTABLE_H