#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "array_generator.h"


int main() {
    int size = 10000;


    std::vector<int> randomArray = ArrayGenerator::generateRandomArray(size);
    std::cout << "Random Array: ";
    for (int num : randomArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;



    return 0;
}