

#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <iostream>
#include <vector>
#include <chrono>
#include "sorting_alg.h"

class SortTester {
public:
    static long long mSTime(const std::vector<int>& arr) {
        std::vector<int> copy = arr;
        auto start = std::chrono::high_resolution_clock::now();
        SortingAlg::mergeSort(copy, 0, copy.size() - 1);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long msec = std::chrono::duration_cast<std::chrono::milliseconds> (elapsed).count();
        return msec;
    }
    static long long hybrMSTime(const std::vector<int>& arr, int threshold) {
        std::vector<int> copy = arr;
        auto start = std::chrono::high_resolution_clock::now();
        SortingAlg::hybridMergeSort(copy, 0, copy.size() - 1, threshold);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long msec = std::chrono::duration_cast<std::chrono::milliseconds> (elapsed).count();
        return msec;
    }
};

#endif //SORT_TESTER_H
