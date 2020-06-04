#include <iostream>
#include "libs/CTable.h"

int main() {
    int table[] = { 5, 1, 4, 2, 8, 0, 2 };
    int n = sizeof(table) / sizeof(table[0]);

    CTable test;
    //test.cocktailSort( table, n );
    //test.quickSortMenu( table, 0, n - 1);
    test.heapSort(table, n);

    // show sorted table
    for (int i = 0; i < n; i++)
        std::cout << table[i] << " ";

    return 0;
}
