/*
<4 kyu> Snail
https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
    std::vector<int> result;
    int size = snail_map.size();
    if (snail_map[0].empty() == 0 && size <= 1) {
        return snail_map[0];
    }
    if (size == 1) {
        return {};
    }
    int travel = size + size - 1;
    int j = 0;
    int count = 0;
    // all travel line
    for (int i = 1; i <= travel; i++) {
        // get numbers in line
        for (int k = j; k < size - j; k++) {
            switch (count) {
                case 0: // left
                    result.insert(result.end(), snail_map[j][k]);
                    break;
                case 1: // down
                    if (k < size - 1 - j) {
                        result.insert(result.end(), snail_map[k + 1][size - 1 - j]);
                    }
                    break;
                case 2: // right
                    if (size - 2 - k >= j) {
                        result.insert(result.end(), snail_map[size - 1 - j][size - 2 - k]);
                    }
                    break;
                case 3: // up
                    if (size - 2 - k > j) {
                        result.insert(result.end(), snail_map[size - 2 - k][j]);
                    }
                    break;
            }
        }
        // count full travel block (4 line)
        count++;
        if (count == 4) {
            j++;
            count = 0;
        }
    }
    return result;
}

int main() {

    // std::vector<std::vector<int>> array = {
    //     {434}
    // };

    std::vector<std::vector<int>> array = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // std::vector<std::vector<int>> array = {
    //     {1, 2, 3, 4, 7, 8},
    //     {4, 5, 6, 4, 3, 4},
    //     {7, 8, 9, 7, 5, 6},
    //     {4, 8, 9, 7, 5, 6},
    //     {7, 8, 9, 7, 5, 6},
    //     {7, 8, 9, 7, 6, 7}
    // };

    for (int i = 0; i < snail(array).size(); i++) {
        std::cout << snail(array)[i] << " ";
    }

    return 0;
}