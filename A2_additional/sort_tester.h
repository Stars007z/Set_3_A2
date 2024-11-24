//
// Created by dip00 on 24.11.2024.
//


#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <iostream>
#include <vector>
#include <chrono>
#include "sorting_alg.h"

class SortTimer {
    static long long mSTime(const std::vector<int>& arr) {
        std::vector<int> copy = arr;
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(copy, 0, copy.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }
    static long long hybrMSTime(const std::vector<int>& arr, int threshold) {
        std::vector<int> copy = arr;
        auto start = std::chrono::high_resolution_clock::now();
        hybridMergeSort(copy, 0, copy.size() - 1, threshold);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }
};

#endif //SORT_TESTER_H
