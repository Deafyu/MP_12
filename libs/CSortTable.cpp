#include "CSortTable.h"

void CSortTable::arraySize() {
    char a;
    do {
        std::cout << "Choose array size: 1. 100 2. 1000 3. 1000000 4. Custom" << std::endl;
        std::cin >> a;
        switch (a) {
            case '1': {
                array = new int[100];
                size = 100;
                break;
            }
            case '2': {
                array = new int[1000];
                size = 1000;
                break;
            }
            case '3': {
                array = new int[1000000];
                size = 1000000;
                break;
            }
            case '4': {
                std::cout << "Insert custom size." << std::endl;
                std::cin >> size;
                array = new int[size];
                break;
            }
            default: {
                std::cout << "Wrong option" << std::endl;
            }
        }
    } while (a != '1' and a != '2' and a != '3' and a != '4');
}

void CSortTable::fillArray() {
    char a;
    do {
        std::cout << "Choose array fill method: 1. random numbers 2. fill them by yourself" << std::endl;
        std::cin >> a;
        switch (a) {
            case '1': {
             randomOrdered();
             break;
            }
            case '2': {
                int data;
                for (int i = 0; i < size; ++i) {
                    std::cin >> data;
                    array[i] = data;
                }
                break;
            }
            default: {
                std::cout << "Wrong option" << std::endl;
            }
        }
    } while (a != '1' and a != '2');
}

void CSortTable::displayArray() {
    for (int i = 0; i < size; ++i) {
        std::cout<<array[i]<<std::endl;
    }
}

void CSortTable::random() {
    for (int i = 0; i < size; ++i) {
        int b = (std::rand()%50);
        array[i] = b;
    }
}

void CSortTable::randomOrdered() {
    int a = std::rand(), b;
    for (int i = 0; i < size; ++i) {
        int b = (std::rand()%50+a);
        a = b;
        array[i] = a;
    }
}

