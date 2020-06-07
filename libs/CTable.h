//
// Created by biongoo on 04.06.2020.
//

#ifndef MP_12_CTABLE_H
#define MP_12_CTABLE_H

#include <algorithm>
#include <iostream>

class CTable {
public:
    void cocktailSort();
    void heapify(int n, int i);
    void heapSort();
    int partitionHoare(int low, int high);
    int partitionLomuto(int low, int high);
    void quickSort(int low, int high, int method);
    void quickSortMenu(int low, int high);

    int lenghtOfArray = 0;
    int table[];
};


class CSortTable{

};



#endif //MP_12_CTABLE_H