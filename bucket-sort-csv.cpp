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

void bucketSort(std::vector<std::vector<std::string> >& arr, int lowest, int greatest, int col){
    std::vector<std::vector<std::vector<std::string> > > buckets(greatest-lowest+1);
    for (int i = 1; i < arr.size(); i++) {
        buckets[std::stoi(arr[i][col])-lowest].push_back(arr[i]);
    }
    arr.clear();
    for (int i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr.push_back(buckets[i][j]);
        }
    }
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

    bucketSort(data, 1, 10, 2);

    std::cout << "###############################################################" << std::endl;

    for (int i = 1; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
