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

int main(){
    std::vector<int> arr;
    ReadDataToFile_DEC<int>(PATH_UNSORTED_FILE, arr);

    std::vector<int> data_selection_sort_standard = arr;
    selection_sort_standard(data_selection_sort_standard);
    std::cout << "Check Selection_Sort Standard: " 
              << CheckSortedString<int>(data_selection_sort_standard) 
              << std::endl;
    WriteDataToFile_Dec<int>(data_selection_sort_standard, PATH_SORTED_FILE_0);

    std::vector<int> data_selection_sort_cus = arr;
    selection_sort_cus(data_selection_sort_cus);
    std::cout << "Check Selection_Sort Cus: " 
              << CheckSortedString<int>(data_selection_sort_cus) 
              << std::endl;
    WriteDataToFile_Dec<int>(data_selection_sort_cus, PATH_SORTED_FILE_1);

    std::vector<int> data_selection_sort_hardware = arr;
    selection_sort_hardware(data_selection_sort_hardware);
    std::cout << "Check Selection_Sort Hardware: " 
              << CheckSortedString<int>(data_selection_sort_hardware) 
              << std::endl;
    WriteDataToFile_Dec<int>(data_selection_sort_hardware, PATH_SORTED_FILE_2);

    return 0;
}