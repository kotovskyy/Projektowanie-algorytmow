#include <iostream>
#include <vector>
#define print(x) std::cout << x << std::endl;


// auxiliary function to print an array
void printArray(std::vector<int> v) {
    std::cout << "[" << v[0];
    for (int i = 1; i < v.size(); i++) {
        std::cout << ", " << v[i];
    }
    std::cout << "]" <<std::endl;
}

void merge(std::vector<int>& arr, int left, int middle, int right) {
    std::vector<int> left_arr(arr.begin() + left, arr.begin() + middle + 1);
    std::vector<int> right_arr(arr.begin() + middle + 1, arr.end());
    
    int left_elem_index = 0;
    int right_elem_index = 0;
    int merged_arr_index = left;

    while ((left_elem_index < left_arr.size()) && (right_elem_index < right_arr.size())) {
        if (left_arr[left_elem_index] <= right_arr[right_elem_index]) {
            arr[merged_arr_index++] = left_arr[left_elem_index++];
        } else {
            arr[merged_arr_index++] = right_arr[right_elem_index++];
        }
    }

    while (left_elem_index < left_arr.size()) {
        arr[merged_arr_index++] = left_arr[left_elem_index++];
    }

    while (right_elem_index < right_arr.size()) {
        arr[merged_arr_index++] = right_arr[right_elem_index++];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right){
    if (left >= right) return;
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle+1, right);
    merge(arr, left, middle, right);
}


int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7, 4, 2};
    mergeSort(arr, 0, arr.size()-1);
    printArray(arr);
    return EXIT_SUCCESS;
}
