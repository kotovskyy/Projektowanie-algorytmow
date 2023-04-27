#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

void merge(std::vector<std::vector<std::string> >& arr, int left, int middle, int right, int col) {
    std::vector<std::vector<std::string> > left_arr(arr.begin() + left, arr.begin() + middle+1);
    std::vector<std::vector<std::string> > right_arr(arr.begin() + middle + 1, arr.begin() + right + 1);
    
    int left_elem_index = 0;
    int right_elem_index = 0;
    int merged_arr_index = left;

    while ((left_elem_index < left_arr.size()) && (right_elem_index < right_arr.size())) {
        if (std::stof(left_arr[left_elem_index][col]) <= std::stof(right_arr[right_elem_index][col])) {
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

void mergeSort(std::vector<std::vector<std::string> >& arr, int left, int right, int col){
    if (left >= right) return;
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle, col);
    mergeSort(arr, middle+1, right, col);
    merge(arr, left, middle, right, col);
}

void read_csv(std::string filename, std::vector<std::vector<std::string> >& dest, int start_row, int end_row) {
    std::fstream file(filename);
    // read from *.cvs file
    std::string line;
    for (int i = start_row; i < end_row+1; i++) {
        std::vector<std::string> row;
        if (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string part;
            bool isstr = false;
            while (std::getline(ss, part, ',')) {
                if (part[0] == '\"') {
                    continue;
                }
                row.push_back(part);
            }
            dest.push_back(row);
        }
    }
    file.close();
}

int main() {
    std::string filename = "data.csv";
    std::vector<std::vector<std::string> > data;
    
    read_csv(filename, data, 0, 19);

    for (int i = 1; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    mergeSort(data, 1, data.size()-1, 2);

    std::cout << "###############################################################" << std::endl;

    for (int i = 1; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
