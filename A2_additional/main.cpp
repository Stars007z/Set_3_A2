#include <iostream>
#include <vector>
#include <chrono>
#include"array_generator.h"
#include"sort_tester.h"
#include"sorting_alg.h"

int main() {
    int n = 10000;
    auto rand_arr = ArrayGenerator::generateRandomArray(n);

    auto reverse_arr = ArrayGenerator::generateReverseSortedArray(n);
    auto nearly_arr = ArrayGenerator::generateNearlySortedArray(n);
    auto rand_vect = ArrayGenerator::generateSubarrays(rand_arr);
    auto reverse_vect = ArrayGenerator::generateSubarrays(rand_arr);
    auto near_vect = ArrayGenerator::generateSubarrays(rand_arr);

    for (int i = 0; i < rand_vect.size(); ++i) {
        long long rand_time = SortTester::mSTime(rand_vect[i]);
        long long reverse_time = SortTester::mSTime(reverse_vect[i]);
        long long near_time = SortTester::mSTime(near_vect[i]);
        std::cout << rand_vect[i].size() << " " << rand_time << " " << reverse_time << " " << near_time << '\n';
    }


    return 0;
}