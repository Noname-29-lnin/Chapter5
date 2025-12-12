#include "./../lib/func.hpp"

void remove_element_even(std::vector<int> &arr){
    int n = arr.size() - 1;
    int key_odd;
    int temp_n = n;

    for(int i = 0; i <= n; i++){
        if(arr[i] % i == 1){
            std::swap(arr[i], arr[key_odd]);
            key_odd ++;
            temp_n --;
        }
    }
}