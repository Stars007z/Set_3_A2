

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
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        return duration.count();
    }
    static long long hybrMSTime(const std::vector<int>& arr, int threshold) {
        std::vector<int> copy = arr;
        auto start = std::chrono::high_resolution_clock::now();
        SortingAlg::hybridMergeSort(copy, 0, copy.size() - 1, threshold);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        return duration.count();
    }
    static long long averageTimeMS(const std::vector<int>& arr, int numSamples = 5) {
        long long totalTime = 0;
        for (int i = 0; i < numSamples; ++i) {
            totalTime += mSTime(arr);
        }
        return totalTime / numSamples;
    }
    static long long averageTimeHMS(const std::vector<int>& arr, int threshold, int numSamples = 5) {
        long long totalTime = 0;
        for (int i = 0; i < numSamples; ++i) {
            totalTime += hybrMSTime(arr, threshold);
        }
        return totalTime / numSamples;
    }
};

#endif //SORT_TESTER_H
