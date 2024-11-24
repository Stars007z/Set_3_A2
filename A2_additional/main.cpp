#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include "array_generator.h"
#include "sort_tester.h"
#include "sorting_alg.h"

int main() {
    int n = 10000;
    auto rand_arr = ArrayGenerator::generateRandomArray(n);
    auto reverse_arr = ArrayGenerator::generateReverseSortedArray(n);
    auto nearly_arr = ArrayGenerator::generateNearlySortedArray(n);

    auto rand_vect = ArrayGenerator::generateSubarrays(rand_arr);
    auto reverse_vect = ArrayGenerator::generateSubarrays(reverse_arr);
    auto near_vect = ArrayGenerator::generateSubarrays(nearly_arr);

    std::ofstream outFile("ms_results.txt");
    if (!outFile.is_open()) {
        std::cerr << "Не удалось открыть файл для записи!" << std::endl;
        return 1;
    }

    outFile << "Size Trand Treverse Tnear\n";
    for (int i = 0; i < rand_vect.size(); ++i) {
        long long rand_time = SortTester::averageTimeMS(rand_vect[i]);
        long long reverse_time = SortTester::averageTimeMS(reverse_vect[i]);
        long long near_time = SortTester::averageTimeMS(near_vect[i]);

        outFile << rand_vect[i].size() << " " << rand_time << " " << reverse_time << " " << near_time << "\n";
    }
    outFile.close();
    std::cout << "Результаты записаны в файл ms_results.txt" << std::endl;




    std::ofstream outFile2("hms_results.txt");
    if (!outFile2.is_open()) {
        std::cerr << "Не удалось открыть файл для записи!" << std::endl;
        return 1;
    }

    outFile2 << "Size Trand Treverse Tnear\n";
    for (int i = 0; i < rand_vect.size(); ++i) {
        long long rand_time = SortTester::averageTimeHMS(rand_vect[i], 20);
        long long reverse_time = SortTester::averageTimeHMS(reverse_vect[i], 20);
        long long near_time = SortTester::averageTimeHMS(near_vect[i], 20);

        outFile2 << rand_vect[i].size() << " " << rand_time << " " << reverse_time << " " << near_time << "\n";
    }
    outFile2.close();
    std::cout << "Результаты записаны в файл hms_results.txt" << std::endl;
    return 0;
}