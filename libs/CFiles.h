//
// Created by biongoo on 07.06.2020.
//

#ifndef MP_12_CFILES_H
#define MP_12_CFILES_H

#include "CSortTable.h"
#include <fstream>
#include <iostream>

class CFiles {
public:
    std::string fileExists();
    void saveToFile(CSortTable &cSortTable);
};

#endif //MP_12_CFILES_H