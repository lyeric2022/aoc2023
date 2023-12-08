#include <bits/stdc++.h> 

std::pair<int, int> starCoords(std::vector<std::vector<char>> grid, int i, int j, int dim) {
    int row_above = i - 1;
    int row_below = i + 1;
    int col_left = j - 1;
    int col_right = j + 1;

    for (int l = row_above; l <= row_below; l++) {
        for (int k = col_left; k <= col_right; k++) {
            if (l >= 0 && l <= dim - 1 && k >= 0 && k <= dim - 1 && grid[l][k] == '*') {
                return std::make_pair(l, k);
            }
        }
    }
    return std::make_pair(0, 0);
}

bool starAdjacent(std::vector<std::vector<char>> grid, int i, int j, int dim) {

    int row_above = i - 1;
    int row_below = i + 1;
    int col_left = j - 1;
    int col_right = j + 1;

    for (int l = row_above; l <= row_below; l++) {
        for (int k = col_left; k <= col_right; k++) {
            if (l >= 0 && l <= dim - 1 && k >= 0 && k <= dim - 1 && grid[l][k] == '*') {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<std::string> lines_array;
    std::string current_line;

    while (std::getline(std::cin, current_line)) {
        lines_array.push_back(current_line);
    }

    int rows = lines_array.size();
    int cols = lines_array[0].size() - 1;

    std::cout << "Rows: " << rows << std::endl << "Cols: " << cols << std::endl;

    std::vector<std::vector<char>> grid(rows, std::vector<char>(cols, '.'));

    std::cout << std::endl << "Empty Matrix:" << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!std::isspace(lines_array[i][j])) {
                grid[i][j] = lines_array[i][j];
            }
        }
    }
    std::cout << std::endl << "Filled Matrix:" << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::map<std::pair<int, int>, std::pair<int, int>> map;
    int gearSum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::string number_string = "";
            if (std::isdigit(grid[i][j]) && (!std::isdigit(grid[i][j - 1]) || (j - 1) < 0)) {
                number_string = number_string + grid[i][j];
                if (std::isdigit(grid[i][j + 1])) {
                    number_string = number_string + grid[i][j + 1];
                    if (std::isdigit(grid[i][j + 2])) {
                        number_string = number_string + grid[i][j + 2];
                        if (starAdjacent(grid, i, j, rows) || starAdjacent(grid, i, j + 1, rows) || starAdjacent(grid, i, j + 2, rows)) {

                            if (starCoords(grid, i, j, rows) == std::make_pair(0, 0)) {
                                if (starCoords(grid, i, j + 1, rows) == std::make_pair(0, 0)) {
                                    if (map[starCoords(grid, i, j + 2, rows)].first == 0) {
                                        map[starCoords(grid, i, j + 2, rows)].first = std::stoi(number_string);
                                    }
                                    else {
                                        map[starCoords(grid, i, j + 2, rows)].second = std::stoi(number_string);
                            }
                                }
                                if (map[starCoords(grid, i, j + 1, rows)].first == 0) {
                                    map[starCoords(grid, i, j + 1, rows)].first = std::stoi(number_string);
                                }
                                else {
                                    map[starCoords(grid, i, j + 1, rows)].second = std::stoi(number_string);
                                }
                            }
                            else {
                                if (map[starCoords(grid, i, j, rows)].first == 0) {
                                map[starCoords(grid, i, j, rows)].first = std::stoi(number_string);
                                }
                                else {
                                    map[starCoords(grid, i, j, rows)].second = std::stoi(number_string);
                                }
                            }


                            
                            
                        }
                    }
                    else {
                        if (starAdjacent(grid, i, j, rows) || starAdjacent(grid, i, j + 1, rows)) {
                            if (starCoords(grid, i, j, rows) == std::make_pair(0, 0)) {
                                if (map[starCoords(grid, i, j, rows)].first == 0) {
                                    map[starCoords(grid, i, j, rows)].first = std::stoi(number_string);
                                }
                                else {
                                    map[starCoords(grid, i, j, rows)].second = std::stoi(number_string);
                                }
                            }
                            else {
                                if (map[starCoords(grid, i, j, rows)].first == 0) {
                                    map[starCoords(grid, i, j, rows)].first = std::stoi(number_string);
                                }
                                else {
                                    map[starCoords(grid, i, j, rows)].second = std::stoi(number_string);
                                }
                            }
                            
                        }
                    }
                }
                else {
                    if (starAdjacent(grid, i, j, rows)) {
                            if (map[starCoords(grid, i, j, rows)].first == 0) {
                                map[starCoords(grid, i, j, rows)].first = std::stoi(number_string);
                            }
                            else {
                                map[starCoords(grid, i, j, rows)].second = std::stoi(number_string);
                            }
                            
                        }
                }
            }
        }
    }
    int counter = 0;
    for (auto entry : map) {
        std::cout << std::endl << "<" << entry.first.first << "," << entry.first.second << ">" << "  -  " << "(" << entry.second.first << "," << entry.second.second << ")" << std::endl;
        if (entry.first.first != 0 && entry.first.second != 0) {
            gearSum += (entry.second.first * entry.second.second);
            counter++;
        }
    }

    std::cout << std::endl << "Gear Sum: " << gearSum << std::endl;
    std::cout << "Counter: " << counter << std::endl;
}