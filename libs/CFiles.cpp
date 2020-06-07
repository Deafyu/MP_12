//
// Created by biongoo on 07.06.2020.
//

#include "CFiles.h"

std::string CFiles::fileExists() {
    std::string nameOut;

    std::cout << "Provide output file name(without extension): ";
    std::cin >> nameOut;

    nameOut += ".txt";

    std::ifstream f(nameOut.c_str());

    if(!f.good())
        return nameOut;
    else {
        std::cout << "Error! This name is already taken." << std::endl;
        fileExists();
    }
}

void CFiles::saveToFile(CSortTable &cSortTable) {
    std::string nameOut;

    nameOut = fileExists();

    std::ofstream fileOut(nameOut + ".txt");

    for (int i = 0; i < cSortTable.size; i++) {
        fileOut << "| ";
        fileOut << cSortTable.array[i];
        fileOut << " | ";

        fileOut << cSortTable.name;
        fileOut << " | ";

        fileOut << cSortTable.size;
        fileOut << " | ";

        fileOut << cSortTable.arrayType;
        fileOut << " | ";

        fileOut << cSortTable.equalities;
        fileOut << " | ";

        fileOut << cSortTable.swaps;
        fileOut << " |";
        fileOut << std::endl;
    }
}