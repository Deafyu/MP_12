#include <iostream>
#include "libs/CSortTable.h"
#include "libs/CTable.h"

int main() {
    srand(time(nullptr));
    CSortTable cSortTable;
    cSortTable.arraySize();
    cSortTable.fillArray();
    cSortTable.displayArray();
    CTable ctable;
    ctable.heapSort(cSortTable);
    cSortTable.displayArray();
    return 0;
}
