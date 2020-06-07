#include <iostream>
#include "libs/CSortTable.h"
#include "libs/CTable.h"
#include "libs/cFiles.h"

int main() {
    srand(time(nullptr));

    CSortTable cSortTable;
    cSortTable.arraySize();
    cSortTable.fillArray();

    CTable ctable;
    ctable.heapSort(cSortTable);

    CFiles cfiles;
    cfiles.saveToFile(cSortTable);
    //std::cout << std::endl;
    //cSortTable.displayArray();
    //std::cout << cSortTable.swaps;
    return 0;
}


