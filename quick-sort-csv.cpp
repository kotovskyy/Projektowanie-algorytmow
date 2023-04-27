#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>


void read_csv(std::string filename, std::vector<std::vector<std::string> >& dest, int start_row, int end_row) {
    std::fstream file(filename);
    // read from *.cvs file
    std::string line;
    for (int i = start_row; i < end_row+2; i++) {
        std::vector<std::string> row;
        if (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string part;
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

int findPivot(std::vector<std::vector<std::string> >& v, int start, int end, int col) {
    int pivot = end;
    int border = start;
    for (int i = start; i < end; i++) {
        if (std::stof(v[i][col]) < std::stof(v[pivot][col])) {
            std::swap(v[i], v[border++]);
        }
    }
    std::swap(v[pivot], v[border]);
    return border;
}

void quickSort(std::vector<std::vector<std::string> >& v, int start, int end, int col) {
    if (start >= end) return;
    int pivot = findPivot(v, start, end, col);
    quickSort(v, start, pivot - 1, col);
    quickSort(v, pivot + 1, end, col);
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

    quickSort(data, 1, data.size()-1, 2);

    std::cout << "###############################################################" << std::endl;

    for (int i = 1; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
