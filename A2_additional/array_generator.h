
#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class ArrayGenerator {
public:
    static std::vector<int> generateRandomArray(int size, int minValue = 0, int maxValue = 6000) {
        std::vector<int> arr(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(minValue, maxValue);

        for (int i = 0; i < size; ++i) {
            arr[i] = dis(gen);
        }

        return arr;
    }

    static std::vector<int> generateReverseSortedArray(int size) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = size - i;
        }
        return arr;
    }


    static std::vector<int> generateNearlySortedArray(int size, int swapCount = 10) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = i + 1;
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, size - 1);

        for (int i = 0; i < swapCount; ++i) {
            int index1 = dis(gen);
            int index2 = dis(gen);
            std::swap(arr[index1], arr[index2]);
        }

        return arr;
    }

    static std::vector<std::vector<int>> generateSubarrays(const std::vector<int> &fullArray) {
        std::vector<std::vector<int>> subarrays;
        const int maxSize = fullArray.size();
        const int step = 100;

        for (int size = 500; size <= maxSize; size += step) {
            subarrays.push_back(std::vector<int>(fullArray.begin(), fullArray.begin() + size));
        }
        return subarrays;
    }
};



#endif //ARRAY_GENERATOR_H
