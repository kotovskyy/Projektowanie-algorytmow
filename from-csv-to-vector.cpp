#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>


void read_csv(std::string filename, std::vector<std::vector<std::string> >& dest, int start_row, int end_row) {
    std::fstream file(filename);
    // read from *.cvs file
    std::string line;
    int i = 0;
    while (!file.eof()) {
        if (std::getline(file, line)) {
            std::vector<std::string> row;
            if ((i >= start_row) && (i < end_row+2)) {
                std::string part;
                int first = line.find_first_of(',');
                int last = line.find_last_of(',');
                part = line.substr(0, first);
                row.push_back(part);
                part = line.substr(first+1, last-first-1);
                row.push_back(part);
                part = line.substr(last+1, line.size());
                row.push_back(part);
                dest.push_back(row);
            }
        }
        if (i >= end_row + 2) return;
        i++;
    }
    file.close();
}

int main() {
    std::string filename = "data.csv";
    std::vector<std::vector<std::string> > data;
    
    read_csv(filename, data, 1, 24);

    for (int i = 1; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return EXIT_SUCCESS;
}
