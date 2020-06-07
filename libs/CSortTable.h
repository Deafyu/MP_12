//
// Created by knies on 04.06.2020.
//

#ifndef MP_12_CSORTTABLE_H
#define MP_12_CSORTTABLE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class CSortTable {
public:
    int equalities = 0;
    int swaps = 0;
    int *array;
    int size;
    std::string name;
    std::string arrayType;
    void arraySize();
    void fillArray();
    void displayArray();
    void randomOrdered();
    void random();
    void randomReverseOrdered();
    void randomAlmostOrdered();
};




#endif //MP_12_CSORTTABLE_H