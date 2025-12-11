#ifndef FUNC_H_
#define FUNC_H_

#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdint>
#include <cstring>

void selection_sort_standard(std::vector<int> &arr);
void selection_sort_cus(std::vector<int> &arr);
void selection_sort_hardware(std::vector<int> &arr);

template <typename SIZE_TYPE_T>
void ReadDataToFile_DEC(const std::string& filename, std::vector<SIZE_TYPE_T> &arr) {
    std::ifstream file(filename);
    SIZE_TYPE_T number;

    if (file.is_open()) {
        while (file >> number) {
            arr.push_back(number);
        }
        file.close();
    } else {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    printf("Finished reading file: %s\n", filename.c_str());
}
template <typename SIZE_ARR_T>
void WriteDataToFile_Dec(const std::vector<SIZE_ARR_T>& vec, const std::string& filename) {
    std::ofstream outFile(filename); // Mở file để ghi

    if (!outFile.is_open()) {
        std::cerr << "Error: Can't open file '" << filename << std::endl;
        return;
    }

    for (const auto& val : vec) {
        outFile << val << "\n"; // Mỗi phần tử ghi trên một dòng
    }

    outFile.close();
    std::cout << "Finish write file '" << filename << "'.\n";
}
template <typename SIZE_ARR_T>
std::string CheckSortedString(const std::vector<SIZE_ARR_T>& arr){
    return std::is_sorted(arr.begin(), arr.end()) ? "PASS" : "FAIL";
}


#endif