#include "CSortTable.h"

void CSortTable::arraySize() {
    char a;
    do {
        std::cout << "Choose array size: 1. 100 2. 1000 3. 1000000 4. Custom" << std::endl;
        std::cin >> a;
        std::cin.sync();
        std::cin.clear();
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
    char a, b ='0';
    do {
        std::cout << "Choose array fill method: 1. random numbers 2. fill them by yourself" << std::endl;
        std::cin >> a;
        std::cin.sync();
        std::cin.clear();
        switch (a) {
            case '1': {
                std::cout << "Choose random fill method: 1. random numbers 2. random ordered 3. random reverse ordered 4. random almost ordered" << std::endl;
                std::cin>>b;
                std::cin.sync();
                std::cin.clear();
                switch(b){
                    case '1':{
                        random();
                        break;
                    }
                    case '2':{
                        randomOrdered();
                        break;
                    }
                    case '3':{
                        randomReverseOrdered();
                        break;
                    }
                    case '4':{
                        randomAlmostOrdered();
                        break;
                    }
                    default:{
                        std::cout<<"wrong choice"<<std::endl;
                    }
                }
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
    } while (a != '1' and a != '2' and b!='1' and b!='2' and b!='3' and b!='4');
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
void CSortTable::randomReverseOrdered() {
    int a = std::rand(), b;
    for (int i = size-1; i > 0; i--) {
        int b = (std::rand()%50+a);
        a = b;
        array[i] = a;
    }
}
void CSortTable::randomAlmostOrdered() {
    int a = std::rand(), b, almost = 1;
    for (int i = 0; i < size; ++i, almost++) {
        int b = (std::rand()%50+a);
        a = b;
        if(almost==10){
            almost = 0;
            array[i] = i;
        }else{
            array[i] = a;
        }
    }
}