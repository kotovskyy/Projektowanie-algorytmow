#include <iostream>
#include <vector>

void printArray(std::vector<int>& v) {
    if (v.size() <= 0) return;
    std::cout << "[" << v[0];
    for (int i = 1; i < v.size(); i++) {
        std::cout << ", " << v[i];
    }
    std::cout << "]" <<std::endl;
}

int findPivot(std::vector<int>& v, int start, int end) {
    int pivot = end;
    int border = start;
    for (int i = start; i < end; i++) {
        if (v[i] < v[pivot]) {
            std::swap(v[i], v[border++]);
        }
    }
    std::swap(v[pivot], v[border]);
    return border;
}

void quickSort(std::vector<int>& v, int start, int end) {
    if (start >= end) return;
    int pivot = findPivot(v, start, end);
    quickSort(v, start, pivot - 1);
    quickSort(v, pivot + 1, end);
}



int main() {
    srand(time(NULL));
    std::vector<int> arr;
    for (int i = 0; i < 20; i++) {
        arr.push_back(int(rand()%101));
    }
    printArray(arr);
    quickSort(arr, 0, arr.size()-1);
    printArray(arr);
    return EXIT_SUCCESS;
}
