/*
<6 kyu> Multiplication table
https://www.codewars.com/kata/534d2f5b5371ecf8d2000a08
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> multiplication_table(int n) {
    std::vector<std::vector<int>> array;
    for (int j = 1; j <= n; j++) {
        std::vector<int> row;
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                row.push_back(j);
            } else {
                row.push_back(i * j);
            }
        }
        array.push_back(row);  
    }
    return array;
}

int main() {

    for (auto x : multiplication_table(3)) {
        for (auto y : x) {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}