#include <iostream>
#include "libs/CTable.h"

int main() {
    //int table[] = { 5, 1, 4, 2, 8, 0, 2 };
    //int n = sizeof(table) / sizeof(table[0]);

    CTable test;
    test.table[0] = 10;
    test.table[1] = 7;
    test.table[2] = 3;
    test.lenghtOfArray = 3;

    test.quickSortMenu(0, test.lenghtOfArray - 1);
    //test.cocktailSort();
    //test.heapSort();

    // show sorted table
    for (int i = 0; i < test.lenghtOfArray; i++)
        std::cout << test.table[i] << " ";

    return 0;
}
