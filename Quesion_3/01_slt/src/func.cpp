#include "./../lib/func.hpp"

void selection_sort_standard(std::vector<int> &arr){
    int n = arr.size() - 1;
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j <= n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
}

void selection_sort_cus(std::vector<int> &arr){
    int n = arr.size() - 1;
    int min         = 0;
    int temp_data   = 0;
    int temp_min    = 0;
    int data_key    = 0;
    int data_min    = 0;
    for(int i = 0; i < n; i++){
        data_key = arr[i];
        min = i;
        for(int j = i + 1; j <= n; j++){
            temp_data = arr[j];
            temp_min  = arr[min];
            if(temp_data < temp_min){
                min = j;
            }
            data_min = arr[min];
        }
        arr[i] = data_min;
        arr[min] = data_key;
    }
}

void selection_sort_hardware(std::vector<int> &arr){
    int n = arr.size() - 1;
    int temp_data   = 0;
    int temp_min    = 0;
    int data_key    = 0;
    // int data_min    = 0;
    int min         = 0;
    int i           = 0;
    int j           = 0;

    // IDLE:
        i = 0;
        goto B1; 
    B1:
        data_key    = arr[i];
        std::cout << "Data_key = " << data_key << std::endl;
        if(i < n){ // Self-generated signal updates the min, data_key, j
            min         = i;
            j           = i + 1;
            goto B2;
        } else {
            goto B9;
        }
    B2:
        temp_min    = arr[min]; // similar temp_data
        std::cout << "temp_min = " << temp_min << std::endl;
        goto B2_1;
    B2_1:
        if( j <= n){ // Self-generated signal updates the temp_data and temp_min value
            temp_data   = arr[j];   // Value at index j used for the j < n comparison
            std::cout << "temp_data = " << temp_data << std::endl;
            goto B3;
        } else {
            goto B7;
        }
    B3: 
        if(temp_data < temp_min){ // Self-generated signal updates the minium value
            min         = j;
            goto B5;
        } else {
            goto B5;
        }
    B5:
        j++; // o_update_j -> enable_j=1
        goto B6;
    B6:
        // wait for j to change value
        // wait for data_min value to be updated
        goto B2;
    B7:
        arr[i]          = temp_min; // writes the data_min value into arr[i]
        i++;                        // o_update_i->update_i
        goto B8;
    B8:
        // wait for i to change value
        // maybe the data in index i of array was be updated data equal data_min 
        arr[min]        = data_key; // writes the data_key value into arr[min]
        goto B1;
    B9: // Done
        return;
}