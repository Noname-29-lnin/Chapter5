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

void remove_element_even(std::vector<int> &arr);

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
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Can't open file '" << filename << std::endl;
        return;
    }

    for (const auto& val : vec) {
        outFile << val << "\n";
    }

    outFile.close();
    std::cout << "Finish write file '" << filename << "'.\n";
}
template <typename SIZE_ARR_T>
std::string CheckSortedString(const std::vector<SIZE_ARR_T>& arr){
    bool is_odd = true;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % 2 == 0) is_odd = false; 
    }
    return is_odd ? "PASS" : "FAIL";
}


#endif
