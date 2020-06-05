#include <iostream>
#include "libs/CSortTable.h"

int main() {
    srand(time(nullptr));
    CSortTable cSortTable;
    cSortTable.arraySize();
    cSortTable.fillArray();
    cSortTable.displayArray();
    return 0;
}
