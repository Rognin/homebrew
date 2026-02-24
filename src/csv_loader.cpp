#include "csv_loader.h"

std::vector<std::vector<int>> csv_loader::loadCSV(const std::string& filename) {
    std::vector<std::vector<int>> result;

    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<int> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stoi(cell));
        }
        result.push_back(row);
    }

    return result;
}